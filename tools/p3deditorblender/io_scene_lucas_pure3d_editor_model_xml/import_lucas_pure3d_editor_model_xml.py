import bpy
import xml.etree.cElementTree
import os
import mathutils

class Joint:
	def __init__(Self, Name):
		Self.Name = Name

BlenderToXML = mathutils.Matrix(((1,0,0,0),(0,0,1,0),(0,1,0,0),(0,0,0,1)))
XMLToBlender = BlenderToXML.copy()
XMLToBlender.invert()

VertexNames = ["Vertex3", "Vertex2", "Vertex1"]

if hasattr(mathutils.Matrix, "__matmul__"):#>= 2.80
	MultiplyMatrices = mathutils.Matrix.__matmul__
else:
	def MultiplyMatrices(Matrix1, Matrix2):
		return Matrix1 * Matrix2

def Load(Operator, Context, filepath):
	ElementTree = xml.etree.ElementTree.parse(filepath)
	RootElement = ElementTree.getroot()
	Scene = bpy.context.scene
	Joints2 = []
	Joints3 = {}
	Shaders = {}
	Textures = {}
	
	if bpy.app.version >= (2, 80, 0):#HACK
		from bpy_extras import node_shader_utils
	
	if hasattr(Context, "view_layer"):#>= 2.80
		view_layer = Context.view_layer
		collection = view_layer.active_layer_collection.collection
	else:
		collection = None
		
	for Element in RootElement:
		if Element.tag == "Joint":
			JointName = Element.attrib["Name"]
			Joint2 = Joint(JointName)
			Joint2.RestPose = XMLToBlender
			for Element2 in Element:
				if Element2.tag == "Scale":
					Joint2.RestPose = MultiplyMatrices(MultiplyMatrices(MultiplyMatrices(mathutils.Matrix.Scale(Element2.attrib["X"],4,(1,0,0)),mathutils.Matrix.Scale(Element2.attrib["Y"],4,(0,1,0))),mathutils.Matrix.Scale(Element2.attrib["Z"],4,(0,0,1))),Joint2.RestPose)
				elif Element2.tag == "Rotation":
					Joint2.RestPose = MultiplyMatrices(mathutils.Quaternion((float(Element2.attrib["W"]),float(Element2.attrib["X"]),float(Element2.attrib["Y"]),float(Element2.attrib["Z"]))).to_matrix().to_4x4(),Joint2.RestPose)
				elif Element2.tag == "Translation":
					Joint2.RestPose = MultiplyMatrices(mathutils.Matrix.Translation((float(Element2.attrib["X"]),float(Element2.attrib["Y"]),float(Element2.attrib["Z"]))),Joint2.RestPose)
			Joint2.RestPose = MultiplyMatrices(BlenderToXML,Joint2.RestPose)
			if "Parent" in Element.attrib:
				ParentName = Element.attrib["Parent"]
				Joint2.AbsoluteRestPose = MultiplyMatrices(Joints3[ParentName].AbsoluteRestPose,Joint2.RestPose)
			else:
				Joint2.AbsoluteRestPose = Joint2.RestPose
			Joints2.append(Joint2)
			Joints3[JointName] = Joint2
		elif Element.tag == "Shader":
			ShaderName = Element.attrib["Name"]
			Material = bpy.data.materials.new(ShaderName)
			if bpy.app.version < (2, 80, 0):
				Material.specular_intensity = 0
			if "TextureName" in Element.attrib:
				TextureName = Element.attrib["TextureName"]
				if TextureName in Textures:
					Texture = Textures[TextureName]
				else:
					try:
						Image = bpy.data.images.load(os.path.join(os.path.dirname(filepath),TextureName)+".png")
					except:
						Image = None
					if hasattr(Material, "texture_slots"):#< 2.80
						Texture = bpy.data.textures.new(TextureName,type="IMAGE")
						Texture.image = Image
					else:
						if not Image is None:
							Image.name = TextureName
							
						Texture = Image
				Textures[TextureName] = Texture
				if hasattr(Material, "texture_slots"):#< 2.80
					TextureSlot = Material.texture_slots.add()
					TextureSlot.texture = Texture
					TextureSlot.texture_coords = "UV"
					TextureSlot.use_map_color_diffuse = True
				else:
					ma_wrap = node_shader_utils.PrincipledBSDFWrapper(Material, is_readonly=False)
					ma_wrap.use_nodes = True
					
					ma_wrap.base_color_texture.image = Texture
					ma_wrap.base_color_texture.texcoords = "UV"
			if "Red" in Element.attrib:
				Material.diffuse_color = (float(Element.attrib["Red"])/255,float(Element.attrib["Green"])/255,float(Element.attrib["Blue"])/255,(float(Element.attrib["Alpha"])/255) if ("Alpha" in Element.attrib) else 1)[:len(Material.diffuse_color)]#>= 2.80
			Shaders[ShaderName] = Material
		elif Element.tag == "Mesh":
			MaterialIndex = 0
			UVs = []
			if "Name" in Element.attrib:
				Name = Element.attrib["Name"]
			else:
				Name = ""
			Joints = {}
			VertexCount = int(Element.attrib["VertexCount"])
			PrimitiveCount = int(Element.attrib["PrimitiveCount"])
			Mesh = bpy.data.meshes.new(Name)
			Mesh.vertices.add(VertexCount)
			if hasattr(Mesh, "loops"):#>= 2.63
				Mesh.loops.add(PrimitiveCount*3)
				Mesh.polygons.add(PrimitiveCount)
			else:
				pass#Mesh.faces.add(PrimitiveCount)#TODO: This
			if hasattr(Mesh, "normals_split_custom_set"):#>= 2.74
				Mesh.create_normals_split()
			HasNormals = False
			if hasattr(Mesh, "uv_textures"):#< 2.80
				Mesh.uv_textures.new()
			else:
				Mesh.uv_layers.new()
			if hasattr(Mesh, "loops"):#>= 2.63
				UVLayer = Mesh.uv_layers[0]
			Object = bpy.data.objects.new(Name,Mesh)
			if "JointName" in Element.attrib:
				JointName = Element.attrib["JointName"]
				Joint2 = Joints3[JointName]
				Object.matrix_world = Joint2.AbsoluteRestPose
			VertexIndex = 0
			PrimitiveIndex = 0
			HasMatrices = False
			ColourLayer = None
			Colours = []
			for Element4 in Element:
				if Element4.tag == "Shader":
					ShaderFirstVertexIndex = VertexIndex
					if "Name" in Element4.attrib:
						ShaderName = Element4.attrib["Name"]
						if ShaderName in Shaders:
							Material = Shaders[ShaderName]
						else:
							Material = bpy.data.materials.new(ShaderName)
					else:
						Material = None
					Mesh.materials.append(Material)
					for Element2 in Element4:
						if Element2.tag == "Vertex":
							Mesh.vertices[VertexIndex].co = (float(Element2.attrib["PositionX"]),float(Element2.attrib["PositionZ"]),float(Element2.attrib["PositionY"]))
							if "NormalX" in Element2.attrib:
								Mesh.vertices[VertexIndex].normal = (float(Element2.attrib["NormalX"]),float(Element2.attrib["NormalZ"]),float(Element2.attrib["NormalY"]))
								HasNormals = True
							if "U" in Element2.attrib:
								UVs.append((float(Element2.attrib["U"]),float(Element2.attrib["V"])))
							else:
								UVs.append(None)
							if "Red" in Element2.attrib:
								Colours.append((float(Element2.attrib["Red"])/255,float(Element2.attrib["Green"])/255,float(Element2.attrib["Blue"])/255,(float(Element2.attrib["Alpha"])/255) if ("Alpha" in Element2.attrib) else 1))
							else:
								Colours.append(None)
							for Element3 in Element2:
								if Element3.tag == "Matrix":
									if not HasMatrices:
										HasMatrices = True
										for Joint2 in Joints2:
											MatrixIndex = len(Object.vertex_groups)
											Object.vertex_groups.new(name=Joint2.Name)
											Joints[Joint2.Name] = MatrixIndex
									MatrixName = Element3.attrib["Name"]
									if not MatrixName in Joints:
										MatrixIndex = len(Object.vertex_groups)
										Object.vertex_groups.new(MatrixName)
										Joints[MatrixName] = MatrixIndex
									else:
										MatrixIndex = Joints[MatrixName]
									Object.vertex_groups[MatrixIndex].add([VertexIndex],float(Element3.attrib["Weight"]),"ADD")
							VertexIndex += 1
						elif Element2.tag == "Primitive":
							StartIndex = PrimitiveIndex*3
							for I in range(3):
								Index = StartIndex+I
								if hasattr(Mesh, "loops"):#>= 2.63
									Loop = Mesh.loops[Index]
									Loop.vertex_index = ShaderFirstVertexIndex+int(Element2.attrib[VertexNames[I]])
									if HasNormals:
										if hasattr(Mesh, "normals_split_custom_set"):#>= 2.74
											Loop.normal = Mesh.vertices[Loop.vertex_index].normal
									if not UVs[Loop.vertex_index] is None:
										UVLayer.data[Index].uv = UVs[Loop.vertex_index]
									if not Colours[Loop.vertex_index] is None:
										if ColourLayer is None:
											ColourLayer = Mesh.vertex_colors.new()
										ColourLayer.data[Index].color = Colours[Loop.vertex_index][:len(ColourLayer.data[Index].color)]
								else:
									pass#TODO: This
							if hasattr(Mesh, "loops"):#>= 2.63
								Mesh.polygons[PrimitiveIndex].loop_start = StartIndex
								Mesh.polygons[PrimitiveIndex].loop_total = 3
								Mesh.polygons[PrimitiveIndex].material_index = MaterialIndex
								Mesh.polygons[PrimitiveIndex].use_smooth = True
							else:
								pass#TODO: This
							PrimitiveIndex += 1
					MaterialIndex += 1
			if not HasNormals:
				if hasattr(Mesh, "free_normals_split"):#>= 2.69
					Mesh.free_normals_split()
			if bpy.app.version >= (2, 74, 0):
				Mesh.validate(clean_customdata=False)
			else:
				Mesh.validate()
			Mesh.update(calc_edges=False)
			if HasNormals:
				if hasattr(Mesh, "normals_split_custom_set"):#>= 2.74
					Normals = []
					for I in range(len(Mesh.loops)):
						Normals.append(Mesh.loops[I].normal)
					Mesh.normals_split_custom_set(Normals)
					Mesh.use_auto_smooth = True
			if not collection is None:#>= 2.80
				collection.objects.link(Object)
			else:
				Scene.objects.link(Object)
			if hasattr(Object, "select_set"):#>= 2.80
				Object.select_set(True)
			else:
				Object.select = True
	return {"FINISHED"}