project(
  'libk2pdfopt',
  ['c', 'cpp'],
  version: '2.42',
)

cc = meson.get_compiler('c')

add_project_arguments('-DNOMEMDEBUG', language: 'c')

# Fix crash when compiling with LTO enabled.
add_project_arguments(
  cc.get_supported_arguments('-fno-strict-aliasing'),
  language: 'c',
)

m_dep = cc.find_library('m', required: false)
threads_dep = dependency('threads')

dependencies = [m_dep, threads_dep]

if host_machine.system() == 'windows'
  dependencies += cc.find_library('shlwapi')
endif

cdata = configuration_data()

foreach _depspec : [
  ['djvu'     , 'djvulibre', get_option('djvulibre')],
  ['jpeg'     , 'libjpeg'  , get_option('libjpeg')  ],
  ['leptonica', 'lept'     , true                   ],
  ['mupdf'    , 'libmupdf' , get_option('mupdf')    ],
  ['png'      , 'libpng'   , get_option('libpng')   ],
  ['tesseract', 'tesseract', true                   ],
  ['z'        , 'zlib'     , get_option('zlib')     ],
]
  _dep = dependency(_depspec[1], required: _depspec[2])
  cdata.set('HAVE_@0@_LIB'.format(_depspec[0].to_upper()), _dep.found())
  set_variable('@0@_dep'.format(_depspec[0]), _dep)
  dependencies += _dep
endforeach

willus_config_h = configure_file(
  configuration: cdata,
  input: 'willus_config.meson.h',
  output: 'willus_config.h',
  install_dir: get_option('includedir'),
  install_tag: 'devel',
)

k2pdf_src = [
  'koptcrop.c',
  'koptimize.c',
  'koptocr.c',
  'koptreflow.c',
  'setting.c',
]

foreach _prefix, _files : {
  'k2pdfoptlib': [
    'bmpregion.c',
    'devprofile.c',
    'k2bmp.c',
    'k2file.c',
    'k2files.c',
    'k2gui.c',
    'k2gui_cbox.c',
    'k2gui_osdep.c',
    'k2gui_overlay.c',
    'k2mark.c',
    'k2master.c',
    'k2mem.c',
    'k2menu.c',
    'k2ocr.c',
    'k2parsecmd.c',
    'k2proc.c',
    'k2publish.c',
    'k2settings2cmd.c',
    'k2settings.c',
    'k2sys.c',
    'k2usage.c',
    'k2version.c',
    'pagelist.c',
    'pageregions.c',
    'textrows.c',
    'textwords.c',
    'userinput.c',
    'wrapbmp.c',
  ],
  'tesseract_mod': [
    'tesscapi.cpp',
  ],
  'willuslib': [
    'ansi.c',
    'array.c',
    'bmp.c',
    'bmpdjvu.c',
    'bmpmupdf.c',
    'dtcompress.c',
    'filelist.c',
    'fontdata.c',
    'fontrender.c',
    'gslpolyfit.c',
    'linux.c',
    'math.c',
    'mem.c',
    'ocr.c',
    'ocrgocr.c',
    'ocrtess.c',
    'pdfwrite.c',
    'point2d.c',
    'render.c',
    'strbuf.c',
    'string.c',
    'token.c',
    'wfile.c',
    'wgs.c',
    'wgui.c',
    'willusversion.c',
    'winbmp.c',
    'win.c',
    'wincomdlg.c',
    'winmbox.c',
    'winshell.c',
    'winshellwapi.c',
    'wleptonica.c',
    'wmupdf.c',
    'wmupdfinfo.c',
    'wpdf.c',
    'wsys.c',
    'wzfile.c',
  ],
}
  foreach _entry : _files
    k2pdf_src += _prefix / _entry
  endforeach
endforeach

k2pdfopt_lib = library(
  'k2pdfopt',
  [willus_config_h] + k2pdf_src,
  c_args: '-DK2PDFOPT_EXPORT=__attribute__ ((visibility("default")))',
  dependencies: dependencies,
  gnu_symbol_visibility: 'inlineshidden',
  include_directories: include_directories(
    'k2pdfoptlib',
    'willuslib',
  ),
  install: true,
  soversion: 2,
)

k2pdfopt_dep = declare_dependency(
  dependencies: [leptonica_dep.partial_dependency(includes: true)],
  include_directories: include_directories(
    '.',
    'k2pdfoptlib',
    'willuslib',
  ),
  link_with: k2pdfopt_lib,
)

meson.override_dependency('k2pdfopt', k2pdfopt_dep)

install_headers(
  'context.h',
  'k2pdfoptlib/k2pdfopt.h',
  'koptcrop.h',
  'koptimize.h',
  'koptocr.c',
  'koptocr.h',
  'koptreflow.h',
  'leptonica.h',
  'setting.h',
  'tesseract.h',
  'willuslib/willus.h',
  subdir: 'k2pdfopt',
)

pkg = import('pkgconfig')
pkg.generate(k2pdfopt_lib, subdirs: 'k2pdfopt')
