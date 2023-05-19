project('lj-wpaclient', version: '0.1.0')

meson.override_dependency(meson.project_name(), declare_dependency(version: meson.project_version()))

dependency('lua', version: ['>= 5.1', '< 5.5'], fallback: 'luajit')

install_data(
  'ffi-cdecl/wpa_ctrl.cdef.c',
  'consts_h.lua',
  'poll_h.lua',
  'select_h.lua',
  'socket.lua',
  'socket_h.lua',
  'time_h.lua',
  'wpa_ctrl.lua',
  'wpaclient.lua',
  install_dir: 'common',
  install_tag: 'lj-wpaclient',
)
