project('lua-term', 'c', version: '0.7')

meson.override_dependency(meson.project_name(), declare_dependency(version: meson.project_version()))

lua_dep = dependency('lua', version: ['>= 5.1'], fallback: 'luajit')

shared_module(
  'core',
  'core.c',
  dependencies: [lua_dep],
  install: true,
  install_dir: 'common/term',
  install_tag: 'runtime',
  name_prefix: '',
)

install_data(
  'term/colors.lua',
  'term/cursor.lua',
  'term/init.lua',
  rename: [
    'term/colors.lua',
    'term/cursor.lua',
    'term/init.lua',
  ],
  install_dir: 'common',
  install_tag: 'runtime',
)
