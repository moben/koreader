project('fbink', 'c', version: '1.25.0')

cc = meson.get_compiler('c')

m_dep = cc.find_library('m', required: false)
unibreak_dep = dependency('libunibreak')

c_args = [
  '-D_REENTRANT=1',
  '-D_GNU_SOURCE',
  '-DFBINK_MINIMAL',
  '-DFBINK_WITH_DRAW',
  '-DFBINK_WITH_BITMAP',
  '-DFBINK_WITH_FONTS',
  '-DFBINK_WITH_OPENTYPE',
  '-DFBINK_FOR_' + get_option('target').to_upper(),
  '-DFBINK_VERSION="' + meson.project_version() + ' for ' + get_option('target') + '"',
  ]

fbink_lib = static_library(
  'fbink',
  [
    'cutef8/dfa.c',
    'cutef8/utf8.c',
    'i2c-tools/lib/smbus.c',
    'fbink.c',
    'fbink_cmd.c',
  ],
  c_args: c_args,
  dependencies: [m_dep, unibreak_dep],
  include_directories: include_directories(
    'i2c-tools/include',
  ),
)

if 'fbink' in get_option('progs')
  executable(
    'fbink',
    'fbink_cmd.c',
    c_args: c_args,
    include_directories: include_directories(
      'i2c-tools/include',
    ),
    install: true,
    link_with: fbink_lib,
  )
endif

if 'fbdepth' in get_option('progs')
  executable(
    'fbdepth',
    'utils/fbdepth.c',
    c_args: c_args,
    install: true,
    link_with: fbink_lib,
  )
endif
