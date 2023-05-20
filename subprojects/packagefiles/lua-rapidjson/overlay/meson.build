project(
  'lua-rapidjson',
  'cpp',
  version: '0.7.1',
  default_options: 'cpp_std=c++17',
)

meson.override_dependency(meson.project_name(), declare_dependency(version: meson.project_version()))

lua_dep = dependency('lua', version: ['>= 5.1'], fallback: 'luajit')

shared_module(
  'rapidjson',
  [
    'src/Document.cpp',
    'src/Schema.cpp',
    'src/Userdata.hpp',
    'src/file.hpp',
    'src/luax.hpp',
    'src/rapidjson.cpp',
    'src/values.cpp',
    'src/values.hpp',
  ],
  dependencies: [lua_dep],
  gnu_symbol_visibility: 'inlineshidden',
  include_directories: include_directories('rapidjson/include'),
  install: true,
  install_dir: 'common',
  install_tag: 'runtime',
  name_prefix: '',
)
