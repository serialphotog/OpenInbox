openinbox_sources = [
  'main.c',
  'openinbox-application.c',
  'openinbox-window.c',
]

openinbox_deps = [
  dependency('gtk4'),
]

openinbox_sources += gnome.compile_resources('openinbox-resources',
  'openinbox.gresource.xml',
  c_name: 'openinbox'
)

# Configuration
config_h = configuration_data()
config_h.set('version', meson.project_version())
config_h.set('gettext_package', 'openinbox')
config_h.set('localdir', join_paths(get_option('prefix'), get_option('localedir')))
configure_file(input: 'config.h.in', output: 'config.h', configuration: config_h)

config_inc = include_directories('.')

executable('openinbox', openinbox_sources,
  include_directories: config_inc,
  dependencies: openinbox_deps,
  install: true,
)
