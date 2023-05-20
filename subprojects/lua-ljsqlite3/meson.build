project('lua-ljsqlite3', version: '1.0.2')

meson.override_dependency(meson.project_name(), declare_dependency(version: meson.project_version()))

dependency('lua', version: ['>= 5.1'], fallback: 'luajit')

install_data(
  'init.lua',
  rename: [
    'lua-ljsqlite3/init.lua',
  ],
  install_dir: 'common',
  install_tag: 'runtime',
)
