bl_info = {
	"name": "Lucas' Pure3D Editor Model XML Format",
	"author": "Lucas Cardellini",
	"version": (1,1,3),
	"blender": (2,80,0),
	"location": "File > Import-Export",
	"description": "Import and export model XML files for use with Lucas' Pure3D Editor.",
	"wiki_url": "https://donutteam.com/downloads/BlenderXMLAddon/",
	"tracker_url": "https://donutteam.com/forum",
	"support": "COMMUNITY",
	"category": "Import-Export"}

if "bpy" in locals():
	if bpy.app.version >= (2, 71, 0):
		import importlib
	else:
		import imp as importlib
	if "import_lucas_pure3d_editor_model_xml" in locals():
		importlib.reload(import_lucas_pure3d_editor_model_xml)
	if "export_lucas_pure3d_editor_model_xml" in locals():
		importlib.reload(export_lucas_pure3d_editor_model_xml)

import bpy
from bpy.props import (
		StringProperty,
		BoolProperty,
		)
from bpy_extras.io_utils import (
		ImportHelper,
		ExportHelper,
		)

class ImportLucasPure3DEditorModelXML(bpy.types.Operator, ImportHelper):
	bl_idname = "import_scene.lucas_pure3d_editor_model_xml"
	bl_label = "Import Lucas' Pure3D Editor Model XML"
	bl_options = {"UNDO"}
	
	filename_ext = ".xml"
	filter_glob = StringProperty(default="*.xml",options={"HIDDEN"})
	
	def execute(Self, Context):
		from . import import_lucas_pure3d_editor_model_xml
		
		return import_lucas_pure3d_editor_model_xml.Load(Self,Context,**Self.as_keywords(ignore=("filter_glob",)))

class ExportLucasPure3DEditorModelXML(bpy.types.Operator, ExportHelper):
	bl_idname = "export_scene.lucas_pure3d_editor_model_xml"
	bl_label = "Export Lucas' Pure3D Editor Model XML"
	bl_options = {"PRESET"}

	filename_ext = ".xml"
	filter_glob = StringProperty(default="*.xml",options={"HIDDEN"})
	
	use_selection = BoolProperty(
			name="Selection Only",
			description="Export selected objects only",
			default=False,
			)

	use_mesh_modifiers = BoolProperty(
			name="Apply Modifiers",
			description="Apply modifiers",
			default=True,
			)
	use_mesh_modifiers_render = BoolProperty(
			name="Use Modifiers Render Settings",
			description="Use render settings when applying modifiers to mesh objects",
			default=False,
			)
	
	use_visible = BoolProperty(
			name="Visible Only",
			description="Export visible objects only",
			default=True,
			)

	use_mesh_transformation = BoolProperty(
			name="Apply Transformations",
			description="Apply transformations",
			default=True,
			)

	use_mesh_normals = BoolProperty(
			name="Include Normals",
			description="Include normals",
			default=True,
			)
			
	def draw(self, context):
		layout = self.layout
	
		layout.prop(self, "use_selection")
		layout.prop(self, "use_mesh_modifiers")
		if bpy.app.version < (2, 80, 0):
			layout.prop(self, "use_mesh_modifiers_render")
		layout.prop(self, "use_visible")
		layout.prop(self, "use_mesh_transformation")
		layout.prop(self, "use_mesh_normals")

	def execute(Self, Context):
		from . import export_lucas_pure3d_editor_model_xml

		return export_lucas_pure3d_editor_model_xml.Save(Self,Context,**Self.as_keywords(ignore=("check_existing","filter_glob",)))

def menu_func_import(Self, Context):
	Self.layout.operator(ImportLucasPure3DEditorModelXML.bl_idname,text="Lucas' Pure3D Editor Model (.xml)")

def menu_func_export(self, context):
	self.layout.operator(ExportLucasPure3DEditorModelXML.bl_idname,text="Lucas' Pure3D Editor Model (.xml)")

classes = (
	ImportLucasPure3DEditorModelXML,
	ExportLucasPure3DEditorModelXML,
)

def register():
	if hasattr(bpy.utils, "register_module"):#< 2.80
		bpy.utils.register_module(__name__)
	else:
		for cls in classes:
			bpy.utils.register_class(cls)
	
	if hasattr(bpy.types, "TOPBAR_MT_file_import"):#>= 2.80
		bpy.types.TOPBAR_MT_file_import.append(menu_func_import)
	else:
		bpy.types.INFO_MT_file_import.append(menu_func_import)
	if hasattr(bpy.types, "TOPBAR_MT_file_export"):#>= 2.80
		bpy.types.TOPBAR_MT_file_export.append(menu_func_export)
	else:
		bpy.types.INFO_MT_file_export.append(menu_func_export)

def unregister():
	if hasattr(bpy.utils, "unregister_module"):#< 2.80
		bpy.utils.unregister_module(__name__)
	else:
		for cls in classes:
			bpy.utils.unregister_class(cls)
	
	if hasattr(bpy.types, "TOPBAR_MT_file_import"):#>= 2.80
		bpy.types.TOPBAR_MT_file_import.remove(menu_func_import)
	else:
		bpy.types.INFO_MT_file_import.remove(menu_func_import)
	if hasattr(bpy.types, "TOPBAR_MT_file_export"):#>= 2.80
		bpy.types.TOPBAR_MT_file_export.remove(menu_func_export)
	else:
		bpy.types.INFO_MT_file_export.remove(menu_func_export)

if __name__ == "__main__":
	register()