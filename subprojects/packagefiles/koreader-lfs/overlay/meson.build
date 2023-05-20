project('koreader-lfs', 'c', version: '1.8.0')

meson.override_dependency(meson.project_name(), declare_dependency(version: meson.project_version()))

lua_dep = dependency('lua', version: ['>= 5.1'], fallback: 'luajit')

shared_module(
  'koreader-lfs',
  'src/lfs.c',
  dependencies: [lua_dep],
  gnu_symbol_visibility: 'hidden',
  install: true,
  install_dir: get_option('libdir'),
)
