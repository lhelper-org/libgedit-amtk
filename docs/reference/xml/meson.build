gtkdocentities_conf_data = configuration_data()
gtkdocentities_conf_data.set('PACKAGE_STRING', 'Amtk @0@'.format(meson.project_version()))
gtkdocentities_conf_data.set('PACKAGE_API_VERSION', AMTK_API_VERSION)

gtkdocentities_filename = 'gtkdocentities.ent'

configure_file(
  input: gtkdocentities_filename + '.in',
  output: gtkdocentities_filename,
  configuration: gtkdocentities_conf_data
)
