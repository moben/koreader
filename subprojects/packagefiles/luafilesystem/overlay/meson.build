project('luafilesystem', 'c', version: '1.8.0')

meson.override_dependency(meson.project_name(), declare_dependency(version: meson.project_version()))

lua_dep = dependency('lua', version: ['>= 5.1'], fallback: 'luajit')

shared_module(
  'lfs',
  'src/lfs.c',
  dependencies: lua_dep,
  install: true,
  install_dir: 'common',
  name_prefix: '',
)
