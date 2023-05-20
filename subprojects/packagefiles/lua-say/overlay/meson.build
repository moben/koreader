project('lua-say', version: '1.4.1')

meson.override_dependency(meson.project_name(), declare_dependency(version: meson.project_version()))

dependency('lua', version: ['>= 5.1'], fallback: 'luajit')

install_data(
  'src/say/init.lua',
  rename: [
    'say/init.lua',
  ],
  install_dir: 'common',
  install_tag: 'runtime',
)
