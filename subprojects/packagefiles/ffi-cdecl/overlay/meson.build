project('ffi-cdecl', ['c', 'cpp'])

plugin_path = subproject('gcc-lua').get_variable('plugin_path')
lua_path = subproject('gcc-lua-cdecl').get_variable('lua_path')

cdata = configuration_data()
cdata.set(
  'CC',
  '\'' + '\' \''.join(meson.get_compiler('c').cmd_array()) + '\'',
)
cdata.set(
  'CXX',
  '\'' + '\' \''.join(meson.get_compiler('cpp').cmd_array()) + '\'',
)

foreach _dirname, _dir : {
  'prefix': get_option('prefix'),
  'bindir': get_option('bindir'),
  'incdir': get_option('includedir'),
  'libdir': get_option('libdir'),
  'lua_path': lua_path,
}
  cdata.set_quoted(_dirname.to_upper(), _dir == '.' ? '' : _dir)
endforeach

configure_file(
  configuration: cdata,
  input: 'ffi-cdecl.meson.sh',
  output: 'ffi-cdecl',
  install: true,
  install_dir: get_option('bindir'),
  install_tag: 'devel',
)

install_data(
  'ffi-cdecl.lua',
  install_dir: lua_path,
  install_tag: 'devel',
)

pkg = import('pkgconfig')
pkg.generate(
  name: 'ffi-cdecl',
  description: 'Automated C declarations extraction tool for FFI interfaces.',
  extra_cflags: [
    '-fplugin=${prefix}' / plugin_path,
    '-fplugin-arg-gcclua-script=${prefix}' / lua_path / 'ffi-cdecl.lua',
    ],
  subdirs: 'ffi-cdecl',
)
