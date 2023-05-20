project('gcc-lua-cdecl', version: '3.0.0')

lua_path = get_option('datadir') / 'lua/5.1'

install_data(
  'ffi-cdecl/ffi-cdecl.lua',
  install_dir: lua_path / 'ffi-cdecl',
  install_tag: 'devel',
)

install_subdir(
  'gcc',
  install_dir: lua_path,
  install_tag: 'devel',
)

install_headers(
  'ffi-cdecl/C.c',
  'ffi-cdecl/C99.c',
  'ffi-cdecl/ffi-cdecl.h',
  subdir: 'ffi-cdecl',
)
