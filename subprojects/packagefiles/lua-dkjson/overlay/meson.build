project('lua-dkjson', 'c', version: '2.6')

meson.override_dependency(meson.project_name(), declare_dependency(version: meson.project_version()))

dependency('lua', version: ['>= 5.1', '< 5.5'], fallback: 'luajit')

install_data(
  'dkjson.lua',
  rename: [
    'dkjson.lua',
  ],
  install_dir: 'common',
  install_tag: 'runtime',
)
