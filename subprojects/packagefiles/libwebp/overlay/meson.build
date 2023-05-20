project(
  'libwebp',
  'c',
  version: '1.2.4',
)

cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required: false)

sse2_flag = '-msse2'
has_sse2 = cc.has_header('emmintrin.h') and cc.has_argument(sse2_flag)
if has_sse2
  add_project_arguments([sse2_flag, '-DWEBP_HAVE_SSE2=1'], language: 'c')
endif

sse41_flag = '-msse4.1'
has_sse41 = cc.has_header('smmintrin.h') and cc.has_argument(sse41_flag)
if has_sse41
  add_project_arguments([sse41_flag, '-DWEBP_HAVE_SSE41=1'], language: 'c')
endif

top_includes = include_directories('.')

subdir('sharpyuv')
subdir('src')

webp_lib = library(
  'webp',
  [
    sharpyuv_sources,
    dec_sources,
    dsp_dec_sources,
    utils_dec_sources,
    # No need for the encoder.
    # enc_sources,
    # dsp_enc_sources,
    # utils_enc_sources,
  ],
  dependencies: m_dep,
  gnu_symbol_visibility: 'hidden',
  include_directories: [webp_includes, top_includes],
  install: true,
  version: '7',
)

libwebp_dep = declare_dependency(
  include_directories: include_directories('src'),
  link_with: webp_lib,
)

meson.override_dependency('libwebp', libwebp_dep)

webpdemux_lib = library(
  'webpdemux',
  demux_sources,
  dependencies: libwebp_dep,
  install: true,
  version: '2',
)

libwebpdemux_dep = declare_dependency(
  dependencies: libwebp_dep,
  link_with: webpdemux_lib,
)

meson.override_dependency('libwebpdemux', libwebpdemux_dep)

install_headers(webp_headers, subdir: 'webp')
install_headers(sharpyuv_headers, subdir: 'webp/sharpyuv')

pkg = import('pkgconfig')
pkg.generate(
  webp_lib,
  description: 'Library for the WebP graphics format',
  name: 'libwebp',
)
pkg.generate(
  webpdemux_lib,
  description: 'Library for parsing the WebP graphics format container',
  name: 'libwebdemux',
  requires: 'libwebp',
)
