project('luasystem', 'c', version: '0.2.1')

meson.override_dependency(meson.project_name(), declare_dependency(version: meson.project_version()))

lua_dep = dependency('lua', version: ['>= 5.1'], fallback: 'luajit')

shared_module(
  'core',
  [
    'src/core.c',
    'src/compat.c',
    'src/time.c',
  ],
  dependencies: [lua_dep],
  gnu_symbol_visibility: 'inlineshidden',
  install: true,
  install_dir: 'common/system',
  install_tag: 'runtime',
  name_prefix: '',
)

install_data(
  'system/init.lua',
  rename: [
    'system/init.lua',
  ],
  install_dir: 'common',
  install_tag: 'runtime',
)
