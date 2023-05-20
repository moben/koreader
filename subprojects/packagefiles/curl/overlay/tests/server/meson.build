server_targets = []

_vars = {
  'CURL_NETWORK_AND_TIME_LIBS': ['deps', []],
  }

makefile_extractor_script = '''
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
      _srcs += files(_part)
    endif
  endforeach
  server_targets += executable(
    _name,
    c_args: _args,
    dependencies: _deps + [curl_internal_dep],
    include_directories: [include_directories('../../src'), _incs],
    sources: _srcs,
    )
endforeach
