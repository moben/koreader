project('luasocket', 'c', version: '3.1.0')

meson.override_dependency(meson.project_name(), declare_dependency(version: meson.project_version()))

lua_dep = dependency('lua', version: ['>= 5.1'], fallback: 'luajit')

add_project_arguments('-DLUASOCKET_NODEBUG', language: ['c'])

if host_machine.system() == 'darwin'
  add_project_arguments('-DUNIX_HAS_SUN_LEN', language: ['c'])
  socket_src = 'src/usocket.c'
  socket_dep = dependency('', required: false)
elif host_machine.system() in ['android', 'linux']
  socket_src = 'src/usocket.c'
  socket_dep = dependency('', required: false)
elif host_machine.system() == 'windows'
  add_project_arguments('-DWINVER=0x0501', language: ['c'])
  socket_src = 'src/wsocket.c'
  socket_dep = meson.get_compiler('c').find_library('ws2_32')
else
  error('unsupported host system: ' + host_machine.system())
endif

shared_module(
  'score',
  [
    'src/auxiliar.c',
    'src/buffer.c',
    'src/compat.c',
    'src/except.c',
    'src/inet.c',
    'src/io.c',
    'src/luasocket.c',
    'src/options.c',
    'src/select.c',
    'src/tcp.c',
    'src/timeout.c',
    'src/udp.c',
    socket_src,
  ],
  dependencies: [lua_dep, socket_dep],
  gnu_symbol_visibility: 'hidden',
  install: true,
  install_dir: 'common/socket',
  install_tag: 'runtime',
  name_prefix: '',
)

shared_module(
  'mcore',
  [
    'src/compat.c',
    'src/mime.c',
  ],
  dependencies: [lua_dep],
  install: true,
  install_dir: 'common/mime',
  install_tag: 'runtime',
  name_prefix: '',
)

install_data(
  'src/ltn12.lua',
  'src/mime.lua',
  'src/socket.lua',
  'src/ftp.lua',
  'src/headers.lua',
  'src/http.lua',
  'src/smtp.lua',
  'src/tp.lua',
  'src/url.lua',
  rename: [
    'ltn12.lua',
    'mime.lua',
    'socket.lua',
    'socket/ftp.lua',
    'socket/headers.lua',
    'socket/http.lua',
    'socket/smtp.lua',
    'socket/tp.lua',
    'socket/url.lua',
  ],
  install_dir: 'common',
  install_tag: 'runtime',
)
