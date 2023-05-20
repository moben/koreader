project('luasec', 'c', version: '1.3.1')

meson.override_dependency(meson.project_name(), declare_dependency(version: meson.project_version()))

lua_dep = dependency('lua', version: ['>= 5.1'], fallback: 'luajit')
dependency('luasocket', version: [])
ssl_dep = dependency('openssl')

c_args = ['-DWITH_LUASOCKET']

if host_machine.system() == 'windows'
  luasocket_socket_src = 'src/luasocket/wsocket.c'
  c_args += [
    '-DLSEC_API=__declspec(dllexport)',
    '-DWINVER=0x0501',
    '-D_WIN32_WINNT=0x0501',
    '-DNTDDI_VERSION=0x05010300',
  ]
else
  luasocket_socket_src = 'src/luasocket/usocket.c'
endif

shared_module(
  'ssl',
  [
    luasocket_socket_src,
    'src/config.c',
    'src/context.c',
    'src/ec.c',
    'src/luasocket/buffer.c',
    'src/luasocket/io.c',
    'src/luasocket/timeout.c',
    'src/options.c',
    'src/ssl.c',
    'src/x509.c',
  ],
  c_args: c_args,
  dependencies: [lua_dep, ssl_dep],
  include_directories: include_directories('src'),
  install: true,
  install_dir: 'common',
  install_tag: 'runtime',
  name_prefix: '',
)

install_data(
  'src/ssl.lua',
  'src/https.lua',
  rename: [
    'ssl.lua',
    'ssl/https.lua',
  ],
  install_dir: 'common',
  install_tag: 'runtime',
)
