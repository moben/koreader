project(
  'crengine',
  ['c', 'cpp'],
  version: '3.0.57-ko',
  default_options: 'cpp_std=c++11',
)

fs = import('fs')

subdir('crengine')
subdir('thirdparty/antiword')
subdir('thirdparty/chmlib')

freetype_dep  = dependency('freetype2')
fribidi_dep   = dependency('fribidi', required: get_option('fribidi'))
harfbuzz_dep  = dependency('harfbuzz')
jpeg_dep      = dependency('libjpeg')
png_dep       = dependency('libpng')
srell_dep     = dependency('srell', required: get_option('srell_regex'))
unibreak_dep  = dependency('libunibreak', required: get_option('libunibreak'))
utf8proc_dep  = dependency('libutf8proc', required: get_option('utf8proc'))
webpdemux_dep = dependency('libwebpdemux', required: get_option('webp'))
zlib_dep      = dependency('zlib')
zstd_dep      = dependency('libzstd', required: get_option('zstd'))

err_msg = 'the lunasvg and nanosvg features are mutually exclusive'
lunasvg_dep = dependency(
  'lunasvg',
  required: get_option(
    'lunasvg',
  ).require(
    not get_option('nanosvg').enabled(),
    error_message: err_msg,
  ),
)
nanosvg_dep = dependency(
  'nanosvg',
  required: get_option(
    'nanosvg',
  ).require(
    not lunasvg_dep.found(),
    error_message: err_msg,
  ),
)
if lunasvg_dep.found()
  svg_support = 'lunasvg'
elif nanosvg_dep.found()
  svg_support = 'nanosvg'
else
  svg_support = ''
endif

if get_option('debug')
  debug_flags = ['-D_DEBUG=1', '-DDEBUG=1']
else
  debug_flags = []
endif

antiword_lib = static_library(
  'antiword',
  c_args: debug_flags + antiword_flags,
  gnu_symbol_visibility: 'hidden',
  include_directories: antiword_includes,
  sources: antiword_sources,
)

chmlib_lib = static_library(
  'chmlib',
  c_args: debug_flags + chmlib_flags,
  gnu_symbol_visibility: 'hidden',
  include_directories: chmlib_includes,
  sources: chmlib_sources,
)

crengine_flags = [
  '-DALLOW_KERNING=1',
  '-DCHM_SUPPORT_ENABLED=1',
  '-DCR3_ANTIWORD_PATCH=1',
  '-DCR_EMULATE_GETTEXT=1',
  '-DENABLE_ANTIWORD=1',
  '-DMATHML_SUPPORT=1',
  '-DUSE_FONTCONFIG=0',
]

foreach _flag, _dep : {
  'USE_FRIBIDI'    : fribidi_dep,
  'USE_LIBUNIBREAK': unibreak_dep,
  'USE_LIBWEBP'    : webpdemux_dep,
  'USE_LUNASVG'    : lunasvg_dep,
  'USE_NANOSVG'    : nanosvg_dep,
  'USE_SRELL_REGEX': srell_dep,
  'USE_UTF8PROC'   : utf8proc_dep,
  'USE_ZSTD'       : zstd_dep,
}
  crengine_flags += '-D@0@=@1@'.format(_flag, _dep.found() ? '1' : '0')
endforeach

if (
  8 == meson.get_compiler('cpp').sizeof(
    'off64_t',
    args: '-D_LARGEFILE64_SOURCE=1',
    prefix: '#include<<sys/types.h>',
  )
)
  crengine_flags += [
    '-D_LARGEFILE64_SOURCE=1',
    '-DHAVE_STAT64=1',
  ]
endif

if host_machine.system() != 'windows'
  crengine_flags += [
    '-DLINUX',
    '-D_LINUX=1',
  ]
endif

crengine_lib = library(
  'crengine',
  cpp_args: debug_flags + crengine_flags,
  dependencies: [
    freetype_dep,
    fribidi_dep,
    harfbuzz_dep,
    jpeg_dep,
    lunasvg_dep,
    nanosvg_dep,
    png_dep,
    srell_dep,
    unibreak_dep,
    utf8proc_dep,
    webpdemux_dep,
    zlib_dep,
    zstd_dep,
  ],
  gnu_symbol_visibility: 'inlineshidden',
  include_directories: [crengine_includes, antiword_includes, chmlib_includes],
  sources: crengine_sources,
)

crengine_dep = declare_dependency(
  compile_args: crengine_flags,
  link_with: [
    crengine_lib,
    antiword_lib,
    chmlib_lib,
  ],
  include_directories: crengine_includes,
  dependencies: [
    # Some public headers include harfbuzz and/or unibreak headers.
    harfbuzz_dep.partial_dependency(compile_args: true, includes: true),
    unibreak_dep.partial_dependency(compile_args: true, includes: true),
  ],
)

meson.override_dependency('crengine', crengine_dep)

_toinstall = []

foreach _data : [
  # Directories.
  'hyph/',
  # Files.
  'NOTES.txt',
  'chm.css',
  'cr3.css',
  'dict.css',
  'doc.css',
  'epub.css',
  'fb2.css',
  'htm.css',
  'html5.css',
  'rtf.css',
  'txt.css',
]
  _toinstall += 'cr3gui/data' / _data
endforeach

foreach _data : _toinstall
  if get_option('install_symlinks')
    install_symlink(
      fs.name(_data),
      install_dir: 'data',
      install_tag: 'runtime',
      pointing_to: meson.project_source_root() / _data,
    )
  else
    if fs.is_file(_data)
      install_data(
        _data,
        install_dir: 'data',
        install_tag: 'runtime',
      )
    else
      install_subdir(
        _data,
        install_dir: 'data',
        install_tag: 'runtime',
      )
    endif
  endif
endforeach

summary(
  {
    'FriBidi'    : fribidi_dep.found(),
    'libunibreak': unibreak_dep.found(),
    'SRELL regex': srell_dep.found(),
    'SVG'        : svg_support == '' ? false: svg_support,
    'utf8proc'   : utf8proc_dep.found(),
    'WebP'       : webpdemux_dep.found(),
    'ZSTD'       : zstd_dep.found(),
  },
  bool_yn: true,
  section: 'Features',
)
