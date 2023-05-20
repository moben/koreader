libtest_targets = []

libtest_targets += shared_library(
  'hostname',
  c_args: '-DCURL_HIDDEN_SYMBOLS',
  dependencies: curl_internal_dep,
  sources: files('sethostname.c'),
  )

# `runtests.pl` expects `libhostname.so`
# to be present in a `.libs` subdirectory.
libtest_targets += custom_target(
  command: [find_program('ln'), '-s', '.', '@OUTPUT@'],
  output: '.libs',
  )

_generated_srcs = {
  'lib1521.c': custom_target(
    'lib1521.c',
    command: [perl_exe, meson.current_source_dir() / 'mk-lib1521.pl'],
    depend_files: ['mk-lib1521.pl'],
    capture: true, feed: true,
    input: '../../include/curl/curl.h',
    output: 'lib1521.c',
    ),
  }

_vars = {
  'CURL_NETWORK_LIBS': ['deps', []],
  'TESTUTIL_LIBS'    : ['deps', []],
  }

makefile_extractor_script = '''
srcdir = ../../src
TESTUTIL_LIBS = @TESTUTIL_LIBS@
.PHONY: _extract

_extract:
	$(foreach prog,$(noinst_PROGRAMS),$(info $(prog) $(filter-out %.h,$(call nodist_$(prog)_SOURCES) $(call $(prog)_SOURCES)) $(call $(prog)_CPPFLAGS) $(call $(prog)_LDADD)))
'''
_res = run_command(
  make_exe,
  '--silent',
  '--no-builtin-rules',
  '--no-builtin-variables',
  '-f', meson.current_source_dir() / 'Makefile.inc',
  '--eval', makefile_extractor_script, '_extract',
  check: true,
  env: 'MAKEFLAGS=',
  )
foreach _spec: _res.stdout().strip().split('\n')
  _name = ''
  _args = []
  _deps = []
  _incs = []
  _srcs = []
  foreach _part: _spec.strip().split()
    if _name == ''
      _name = _part
      continue
    endif
    if _part.startswith('@') and _part.endswith('@')
      _value = _vars.get(_part.substring(1, -1))
      if _value[0] == 'deps'
        _deps += _value[1]
      endif
    elif _part.startswith('-D')
      _args += _part
    elif _part.startswith('-I')
      _incs += include_directories(_part.substring(2))
    elif _part.endswith('.c')
      _srcs += _part in _generated_srcs ? _generated_srcs.get(_part) : files(_part)
    endif
  endforeach
  libtest_targets += executable(
    _name,
    c_args: _args,
    dependencies: _deps + [curl_internal_dep],
    include_directories: _incs,
    sources: _srcs,
    )
endforeach
