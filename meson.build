project(
  'koreader',
  ['c', 'cpp'],
  version: '2023.01',
  meson_version: '>= 0.64.0',
  default_options: ['c_std=gnu11', 'cpp_std=gnu++11'],
)

opt_amalgam = get_option('static_if_amalgam') == 'static'

cc = meson.get_compiler('c')
fs = import('fs')

toinstall = {}

global_comp_args = [
  '-fvisibility-inlines-hidden',
]
global_link_args = []

if host_machine.system() == 'darwin'
  # FIXME: does not work; meson overrides the runtime
  # path at install, so we have to fix it again in
  # our `fix-libs.py` install script.
  global_link_args += '-Wl,-rpath,@executable_path/libs,-rpath,@executable_path/../koreader/libs'
else
  global_link_args += '-Wl,-z,origin,-rpath=$ORIGIN,-rpath=$ORIGIN/libs,--disable-new-dtags'
endif

foreach _language : ['c', 'cpp']
  _compiler = meson.get_compiler(_language)
  add_global_arguments(
    _compiler.get_supported_arguments(global_comp_args),
    language: _language,
  )
  add_global_link_arguments(
    _compiler.get_supported_link_arguments(global_link_args),
    language: _language,
  )
endforeach

# Dependencies. {{{

# Iconv replacement…
if host_machine.system() == 'android'
  subproject('miniconv')
endif

# Luajit.
luajit_dep = dependency('luajit')
lua_dep = dependency('lua')

# Libraries.
crengine_dep = dependency('crengine')
czmq_dep = dependency('libczmq')
djvulibre_dep = dependency('djvulibre')
freetype_dep = dependency('freetype2')
fribidi_dep = dependency('fribidi')
giflib_dep = dependency('giflib')
harfbuzz_dep = dependency('harfbuzz')
k2pdfopt_dep = dependency('k2pdfopt')
lodepng_dep = dependency('lodepng')
mupdf_dep = dependency('libmupdf')
nanosvg_dep = dependency('nanosvg')
popen_noshell_dep = dependency('libpopen_noshell', required: get_option('koreader_input') or disabler())
sqlite3_dep = dependency('sqlite3')
threads_dep = dependency('threads')
turbojpeg_dep = dependency('libturbojpeg')
unibreak_dep = dependency('libunibreak')
utf8proc_dep = dependency('libutf8proc')
webp_dep = dependency('libwebpdemux')
zlib_dep = dependency('zlib')
zmq_dep = dependency('libzmq')
zstd_dep = dependency('libzstd')

# LUA.
dependency('koreader-lfs')
dependency('lua-htmlparser')
dependency('lua-ljsqlite3')
dependency('lua-rapidjson')
dependency('lua-spore')
dependency('lua-turbo')
dependency('luajson')
dependency('luasec')
dependency('luasocket')
dependency('lj-wpaclient')

# }}}

# Helpers. {{{

_helpers = {
  'koreader-cre': {
    '_loader': ['preload', 'libs/libkoreader-cre', 'luaopen_cre'],
    'dependencies': [crengine_dep, lua_dep],
    'sources': ['base/cre.cpp'],
  },
  'koreader-djvu': {
    '_loader': ['preload', 'libs/libkoreader-djvu', 'luaopen_djvu'],
    'dependencies': [djvulibre_dep, k2pdfopt_dep, lua_dep, threads_dep],
    'sources': ['base/djvu.c'],
  },
  'koreader-nnsvg': {
    '_loader': ['preload', 'libs/libkoreader-nnsvg', 'luaopen_nnsvg'],
    'dependencies': [lua_dep, nanosvg_dep],
    'sources': ['base/nnsvg.c'],
  },
  'koreader-xtext': {
    '_loader': ['preload', 'libs/libkoreader-xtext', 'luaopen_xtext'],
    'dependencies': [
      freetype_dep,
      fribidi_dep,
      harfbuzz_dep,
      lua_dep,
      unibreak_dep,
    ],
    'sources': ['base/xtext.cpp'],
  },
  'wrap-mupdf': {
    '_loader': ['ffi', 'wrap-mupdf'],
    'dependencies': [mupdf_dep],
    'sources': ['base/wrap-mupdf.c'],
  },
}

if get_option('blitbuffer')
  _helpers += {
    'blitbuffer': {
      '_loader': ['ffi', 'blitbuffer'],
      'sources': ['base/blitbuffer.c'],
    },
  }
endif

if get_option('koreader_input')
  _helpers += {
    'koreader-input': {
      '_loader': ['preload', 'libs/libkoreader-input', 'luaopen_input'],
      'c_args': '-D' + get_option('target').to_upper(),
      'dependencies': [lua_dep, popen_noshell_dep],
      'include_directories': include_directories('base/input'),
      'sources': 'base/input/input.c',
    },
  }
endif

foreach _name, _params : _helpers
  _lib = build_target(
    _name,
    c_args: _params.get('c_args', []),
    gnu_symbol_visibility: 'inlineshidden',
    dependencies: _params.get('dependencies', []),
    include_directories: _params.get('include_directories', []),
    install: true,
    install_dir: get_option('libdir'),
    sources: _params['sources'],
    target_type: opt_amalgam ? 'static_library' : 'shared_module',
  )
  _helpers += {_name: {'_lib': _lib} + _params}
endforeach

_exports = [
  'freetype2',
  'giflib',
  'harfbuzz',
  'koptcontext',
  'leptonica',
  'libwebp',
  'lodepng',
  'mupdf',
  'sqlite3',
  'turbojpeg',
  'utf8proc',
  'zeromq',
  'zlib',
  'zstd',
]
_deps = [
  czmq_dep,
  giflib_dep,
  harfbuzz_dep,
  lodepng_dep,
  sqlite3_dep,
  turbojpeg_dep,
  utf8proc_dep,
  webp_dep,
  zlib_dep,
  zmq_dep,
  zstd_dep,
]
_loaders = [
  ['ffi', 'czmq.1'],
  ['ffi', 'freetype.6'],
  ['ffi', 'gif.7'],
  ['ffi', 'harfbuzz.0'],
  ['ffi', 'k2pdfopt.2'],
  ['ffi', 'lept.5'],
  ['ffi', 'lodepng'],
  ['ffi', 'mupdf'],
  ['ffi', 'sqlite3.0'],
  ['ffi', 'turbojpeg'],
  ['ffi', 'utf8proc.2'],
  ['ffi', 'webpdemux.2'],
  ['ffi', 'z'],
  ['ffi', 'zmq.4'],
  ['ffi', 'zstd.1'],
]
_libs = []

if get_option('sdl')
  _exports += 'SDL2_0'
  _deps += dependency('sdl2')
  _loaders += [['ffi', 'SDL2-2.0.0']]
endif

foreach _name, _params : _helpers
  _loaders += [_params['_loader']]
  _libs += _params['_lib']
  _exports += _name
endforeach

if opt_amalgam

  _link_scripts_inputs = []
  foreach _e : _exports
    _cdecl = f'base/ffi-cdecl/@_e@_cdecl.c'
    if not fs.exists(_cdecl)
      _cdecl = f'base/ffi-cdecl/@_e@_decl.c'
    endif
    _link_scripts_inputs += _cdecl
  endforeach

  _link_args = [
    '-Wl', '@' + (meson.current_build_dir() / 'libkoreader.link_args'),
  ]

  _link_scripts = custom_target(
    'koreader_link_scripts',
    input: _link_scripts_inputs,
    output: [
      'libkoreader.link_args',
      'libkoreader.version_script',
    ],
    command: [
      find_program('./base/libkoreader.gen_link_files.sh'),
      cc.get_linker_id(),
      '@OUTPUT@',
      '@INPUT@',
    ],
  )

  _libkoreader = shared_module(
    'koreader',
    dependencies: _deps,
    gnu_symbol_visibility: 'inlineshidden',
    install: true,
    install_dir: get_option('libdir'),
    link_args: ','.join(_link_args),
    link_depends: _link_scripts[0],
    link_with: _libs,
  )

  _preloads = []
  _redirects = []

  foreach _l : _loaders
    if _l[0] == 'preload'
      _preloads += '["' + _l[1] + '"] = "' + _l[2] + '",'
    elif _l[0] == 'ffi'
      _redirects += '["' + _l[1] + '"] = true,'
    else
      error(_l[0])
    endif
  endforeach

  _libdir = get_option('libdir')
  if _libdir.endswith('.staging')
    _libdir = _libdir.substring(0, -8)
  endif
  configure_file(
    input: 'base/libkoreader.meson.lua',
    output: 'libkoreader.lua',
    install_dir: '.',
    install_tag: 'runtime',
    configuration: {
      'library': _libdir / fs.name(_libkoreader.full_path()),
      'preloads': '\n        '.join(_preloads),
      'redirects': '\n        '.join(_redirects),
    },
  )

endif

# }}}

# Launcher. {{{

if get_option('launcher') == 'default'
  toinstall += {
    'koreader': 'base/launcher.sh',
  }
elif get_option('launcher') == 'luajit-launcher'
  subproject('luajit-launcher')
elif get_option('launcher') == 'macos'
  executable(
    'koreader',
    'base/osx_loader.c',
    dependencies: [luajit_dep],
    # FIXME: does not seem to work; when statically linking
    # to the luajit library loading a LUA module fail with
    # missing symbols…
    export_dynamic: true,
    install: true,
  )
elif get_option('launcher') == 'remarkable'
  executable('button-listen', 'base/button-listen.c', install: true)
endif

# }}}

# Subprojects.

if (
  not meson.is_cross_build()
  and meson.get_compiler('c').get_id() == 'gcc'
  and get_option('ffi-cdecl')
)
  subproject('ffi-cdecl')
endif

# Extra configurable subprojects.
foreach _prj : get_option('subprojects')
  subproject(_prj)
endforeach

# }}}.

# Install. {{{

# Platorm pre-built binaries.
foreach _exe : get_option('platform_executables')
  install_data(_exe, install_dir: get_option('bindir'))
endforeach

# Development stuff.
install_headers(
  'base/blitbuffer.h',
  'base/cre.h',
  'base/djvu.h',
  'base/drawcontext.h',
  'base/koptcontext.h',
  'base/nnsvg.h',
  'base/wrap-mupdf.h',
  'base/xtext.h',
  subdir: 'koreader-base',
)
pkg = import('pkgconfig')
pkg.generate(
  description: 'Base framework for creating document readers like KOReader',
  name: 'koreader-base',
  subdirs: 'koreader-base',
)

# Toolchain libraries.
if meson.is_cross_build()
  toolchain_libs = []
  toolchain_arg = ''
  if host_machine.system() == 'android'
    toolchain_libs += ['libc++_shared.so']
    if get_option('b_sanitize') == 'address'
      toolchain_libs += [
        'libclang_rt.asan-' + host_machine.cpu_family() + '-android.so',
      ]
    endif
    toolchain_arg = '--print-file-name'
  elif host_machine.system() == 'linux'
    toolchain_libs += ['libstdc++.so.6']
    toolchain_arg = '--print-file-name'
  elif host_machine.system() == 'windows' and cc.get_id() == 'gcc'
    toolchain_libs += [
      'libgcc_s_seh-1.dll',
      'libstdc++-6.dll',
      'libwinpthread-1.dll',
    ]
    toolchain_arg = '--print-prog-name'
  endif
  foreach _lib : toolchain_libs
    res = run_command([cc, toolchain_arg, _lib], check: true)
    fs.copyfile(
      res.stdout().strip(),
      install: true,
      install_dir: get_option('libdir'),
    )
  endforeach
endif

# Empty directories.
toinstall += {
  'cache'      : '',
  'clipboard'  : '',
  'history'    : '',
  'ota'        : '',
  'screenshots': '',
}

# Directories.
toinstall += {
  'ffi'                 : 'base/ffi',
  'fonts'               : 'resources/fonts',
  'frontend'            : 'frontend',
  'l10n'                : 'l10n',
  'plugins'             : 'plugins',
  'resources/icons'     : 'resources/icons',
  'resources/quickstart': 'resources/quickstart',
  'tools'               : 'tools',
}

# Files.
toinstall += {
  'COPYING'               : 'COPYING',
  'README.md'             : 'README.md',
  'datastorage.lua'       : 'datastorage.lua',
  'defaults.lua'          : 'defaults.lua',
  'reader.lua'            : 'reader.lua',
  'resources/koreader.png': 'resources/koreader.png',
  'resources/koreader.svg': 'resources/koreader.svg',
  'setupkoenv.lua'        : 'setupkoenv.lua',
}

# Tests data.
if get_option('tests')
  subproject('koreader-runtests')
  subproject('tessdata')
  toinstall += {
    '.luacov'             : '.luacov',
    'spec/base'           : '',
    'spec/base/unit'      : 'base/spec/unit',
    'spec/front'          : '',
    'spec/front/unit'     : 'spec/unit',
  }
endif

foreach _dst, _src : toinstall
  if _src == ''
    install_emptydir(_dst, install_tag: 'runtime')
    continue
  endif
  if get_option('install_symlinks')
    install_symlink(
      fs.name(_dst),
      install_dir: fs.parent(_dst),
      install_tag: 'runtime',
      pointing_to: meson.project_source_root() / _src,
    )
    continue
  endif
  if fs.is_file(_src)
    install_data(
      _src,
      install_dir: fs.parent(_dst),
      install_tag: 'runtime',
      rename: fs.name(_dst),
    )
    continue
  endif
  install_subdir(
    _src,
    install_dir: _dst,
    install_tag: 'runtime',
    strip_directory: true,
  )
endforeach

foreach _tag : ['devel', 'runtime']
  meson.add_install_script(
    [
      find_program('./base/fix_libs.py'),
      host_machine.system(),
      get_option('libdir'),
      _tag,
    ],
    install_tag: _tag,
  )
endforeach

# }}}

# vim: foldmethod=marker
