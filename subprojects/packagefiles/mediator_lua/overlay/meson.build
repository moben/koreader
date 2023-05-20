project('mediator_lua', version: '1.1.2')

meson.override_dependency(meson.project_name(), declare_dependency(version: meson.project_version()))

dependency('lua', version: ['>= 5.1'], fallback: 'luajit')

install_data(
  'src/mediator.lua',
  rename: [
    'mediator.lua',
  ],
  install_dir: 'common',
  install_tag: 'runtime',
)
