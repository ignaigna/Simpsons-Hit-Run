import bpy
import xml.etree.cElementTree
if bpy.app.version >= (2, 64, 0):#HACK
	import bmesh
if bpy.app.version >= (2, 80, 0):#HACK
	from bpy_extras import node_shader_utils

class Vertex:
	def __init__(Self, VertexIndex, Normal, UV, Colour):
		Self.VertexIndex = VertexIndex
		Self.Normal = Normal
		Self.UV = UV
		Self.Colour = Colour

class Shader:
	def __init__(Self, Element):
		Self.Element = Element
		Self.VertexIndices = {}

	def GetOrAddVertexIndex(Self, VertexIndex, Normal, UV, Colour):
		Key = (VertexIndex, )
		if not Normal is None:
			Key += (round(Normal[0],4), round(Normal[1],4))
		Key += (round(UV[0],4), round(UV[1],4))
		if not Colour is None:
			Key += Colour
			
		Added = not Key in Self.VertexIndices
		if Added:
			VertexIndex2 = len(Self.VertexIndices)
			Self.VertexIndices[Key] = VertexIndex2
		else:
			VertexIndex2 = Self.VertexIndices[Key]
			
		return VertexIndex2, Added

ColourNames = ["Red", "Green", "Blue", "Alpha"]
NormalNames = ["NormalX", "NormalY", "NormalZ"]
UVNames = ["U", "V"]
VertexNames = ["Vertex3", "Vertex2", "Vertex1"]
MeshColourNames = ["color1", "color2", "color3", "color4"]

def IsObjectHidden(Object):
	if hasattr(Object, "hide_viewport"):#>= 2.80
		return Object.hide_viewport
	else:
		return Object.hide

def Save(Operator, Context, filepath, use_selection, use_mesh_modifiers, use_mesh_modifiers_render, use_visible, use_mesh_transformation, use_mesh_normals):
	if bpy.app.version >= (2, 80, 0):
		depsgraph = Context.evaluated_depsgraph_get()
	
	if bpy.ops.object.mode_set.poll():
		bpy.ops.object.mode_set(mode="OBJECT")
	RootElement = xml.etree.cElementTree.Element("Model")
	Scene = bpy.context.scene
	Joints = set()
	Shaders2 = set()
	if use_selection:
		Objects = Context.selected_objects
	else:
		Objects = bpy.data.objects
	for Object in Objects:
		if Object.type == "MESH":
			if not use_visible or not IsObjectHidden(Object):
				VertexCount = 0
				PrimitiveCount = 0
				LoopVertexIndices = {}
				Shaders = {}
				if bpy.app.version >= (2, 80, 0):
					ob_for_convert = Object.evaluated_get(depsgraph) if use_mesh_modifiers else Object.original
					
					Mesh = ob_for_convert.to_mesh()
				else:
					if bpy.app.version >= (2, 66, 0):
						Mesh = Object.to_mesh(Scene,use_mesh_modifiers,calc_tessface=False,settings="RENDER" if use_mesh_modifiers_render else "PREVIEW")
					else:
						Mesh = Object.to_mesh(Scene,use_mesh_modifiers,settings="RENDER" if use_mesh_modifiers_render else "PREVIEW")
				if bpy.app.version >= (2, 64, 0):#HACK
					BMesh = bmesh.new()
					BMesh.from_mesh(Mesh)
					bmesh.ops.triangulate(BMesh,faces=BMesh.faces)
					BMesh.to_mesh(Mesh)
					BMesh.free()
				if use_mesh_transformation:
					Mesh.transform(Object.matrix_world)
					if Object.matrix_world.determinant() < 0.0:
						Mesh.flip_normals()
				if use_mesh_normals:
					if hasattr(Mesh, "calc_normals_split"):#>= 2.69
						Mesh.calc_normals_split()
					else:
						Mesh.calc_normals()
				for VertexGroup in Object.vertex_groups:
					if not VertexGroup.name in Joints:
						JointElement = xml.etree.cElementTree.SubElement(RootElement,"Joint")
						JointElement.set("Name",VertexGroup.name)
						Joints.add(VertexGroup.name)
				for Material in Mesh.materials:
					if Material is None:
						continue
					if not Material.name in Shaders2:
						ShaderElement = xml.etree.cElementTree.SubElement(RootElement,"Shader")
						ShaderElement.set("Name",Material.name)
						if hasattr(Material, "texture_slots"):#< 2.80
							for TextureSlot in Material.texture_slots:
								if not TextureSlot is None:
									if TextureSlot.use_map_color_diffuse:
										if TextureSlot.texture.type == "IMAGE":
											ShaderElement.set("TextureName",TextureSlot.texture.name)
											break
						else:
							mat_wrap = node_shader_utils.PrincipledBSDFWrapper(Material)
							
							tex_wrap = mat_wrap.base_color_texture
							if not tex_wrap is None:
								image = tex_wrap.image
								if not image is None:
									ShaderElement.set("TextureName",image.name)
						for I in range(3):
							ShaderElement.set(ColourNames[I],str(int(round(Material.diffuse_color[I]*255))))
						Shaders2.add(Material.name)
				MeshElement = xml.etree.cElementTree.SubElement(RootElement,"Mesh")
				MeshElement.set("Name",Object.name)
				if bpy.app.version >= (2, 64, 0):#HACK
					UVLayer = Mesh.uv_layers.active
					ColourLayer = Mesh.vertex_colors.active
					Polygons = Mesh.polygons
				else:
					if hasattr(Mesh, "tessface_uv_textures"):#>= 2.63
						UVLayer = Mesh.tessface_uv_textures.active
					if hasattr(Mesh, "tessface_vertex_colors"):#>= 2.63
						ColourLayer = Mesh.tessface_vertex_colors.active
					if hasattr(Mesh, "tessfaces"):#>= 2.63
						Polygons = Mesh.tessfaces
					else:
						Polygons = []#TODO: This
				for PrimitiveIndex in range(len(Polygons)):
					Polygon = Polygons[PrimitiveIndex]
					if len(Mesh.materials) > 0:
						Material = Mesh.materials[Polygon.material_index]
					else:
						Material = None
					if not Material in Shaders:
						Shader2 = Shader(xml.etree.cElementTree.SubElement(MeshElement,"Shader"))
						if not Material is None:
							Shader2.Element.set("Name",Material.name)
						Shaders[Material] = Shader2
					else:
						Shader2 = Shaders[Material]
						
					if bpy.app.version >= (2, 64, 0):#HACK
						TriangleLoopIndices = ((Polygon.loop_start+0, Polygon.loop_start+1, Polygon.loop_start+2), )
					else:
						if len(Polygon.vertices) == 3:
							TriangleLoopIndices = (Polygon.vertices, )
						else:
							TriangleLoopIndices = (Polygon.vertices[0], Polygon.vertices[1], Polygon.vertices[2]), (Polygon.vertices[0], Polygon.vertices[2], Polygon.vertices[3])
							
					for TriangleLoopIndices2 in TriangleLoopIndices:
						for I in range(len(TriangleLoopIndices2)):
							LoopIndex = TriangleLoopIndices2[I]
							if bpy.app.version >= (2, 64, 0):#HACK
								Loop = Mesh.loops[LoopIndex]
							else:
								Loop = None
								
							if not Loop is None:
								VertexIndex = Loop.vertex_index
							else:
								VertexIndex = LoopIndex
								
							Vertex2 = Mesh.vertices[VertexIndex]
							if use_mesh_normals:
								if not Loop is None and hasattr(Loop, "normal"):#>= 2.69
									Normal3 = Loop.normal
									Normal2 = Normal3
								else:
									Normal3 = None
									Normal2 = Vertex2.normal
								Normal = (Normal2.x,Normal2.z,Normal2.y)
							else:
								Normal3 = None
								Normal = None
							if not UVLayer is None:
								if not Loop is None:
									UVLayerData = UVLayer.data[LoopIndex]
									UV = UVLayerData.uv
								else:
									UVLayerData = UVLayer.data[PrimitiveIndex]
									UV = UVLayerData.uv[I]
							else:
								UV = (0,0)
							if not ColourLayer is None:
								if not Loop is None:
									ColourLayerData = ColourLayer.data[LoopIndex]
									Colour = ColourLayerData.color
								else:
									ColourLayerData = ColourLayer.data[PrimitiveIndex]
									Colour = getattr(ColourLayerData, MeshColourNames[I])
							else:
								Colour = None
								
							if not Colour is None:
								Colour2 = ()
								for Value in Colour:
									Colour2 += (int(round(Value*255)), )
							else:
								Colour2 = None
								
							VertexIndex2, Added = Shader2.GetOrAddVertexIndex(VertexIndex,Normal3,UV,Colour2)
							if Added:
								VertexElement = xml.etree.cElementTree.SubElement(Shader2.Element,"Vertex")
								VertexElement.set("PositionX",str(Vertex2.co.x))
								VertexElement.set("PositionY",str(Vertex2.co.z))
								VertexElement.set("PositionZ",str(Vertex2.co.y))
								if not Normal is None:
									for I in range(len(Normal)):
										VertexElement.set(NormalNames[I],str(Normal[I]))
								for I in range(len(UV)):
									VertexElement.set(UVNames[I],str(UV[I]))
								if not Colour2 is None:
									for I in range(len(Colour2)):
										VertexElement.set(ColourNames[I],str(Colour2[I]))
								for Group in Vertex2.groups:
									MatrixElement = xml.etree.cElementTree.SubElement(VertexElement,"Matrix")
									MatrixElement.set("Name",Object.vertex_groups[Group.group].name)
									MatrixElement.set("Weight",str(Group.weight))
								VertexCount += 1
							LoopVertexIndices[LoopIndex] = VertexIndex2
						Primitive = xml.etree.cElementTree.SubElement(Shader2.Element,"Primitive")
						for I in range(len(TriangleLoopIndices2)):
							Primitive.set(VertexNames[I],str(LoopVertexIndices[TriangleLoopIndices2[I]]))
						PrimitiveCount += 1
				MeshElement.set("VertexCount",str(VertexCount))
				MeshElement.set("PrimitiveCount",str(PrimitiveCount))
	ElementTree = xml.etree.cElementTree.ElementTree(RootElement)
	ElementTree.write(filepath,encoding="utf-8",xml_declaration=True)
	return {"FINISHED"}