project('lua-lpeg', 'c', version: '1.0.2')

meson.override_dependency(meson.project_name(), declare_dependency(version: meson.project_version()))

lua_dep = dependency('lua', version: ['>= 5.1'], fallback: 'luajit')

shared_module(
  'lpeg',
  [
    'lpcap.c',
    'lpcode.c',
    'lpprint.c',
    'lptree.c',
    'lpvm.c',
  ],
  dependencies: lua_dep,
  install: true,
  install_dir: 'common',
  install_tag: 'runtime',
  name_prefix: '',
)

install_data(
  're.lua',
  install_dir: 'common',
  install_tag: 'runtime',
)
