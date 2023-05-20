subdir('libtest')
subdir('server')
subdir('unit')

_srcdir = meson.current_source_dir()

test(
  'runtests',
  perl_exe,
  args: [
    '-I' + _srcdir,
    _srcdir / 'runtests.pl',
    # Continue even if a test fails.
    '-a',
    # No valgrind.
    '-n',
    ],
  depends: [curl_exe, libtest_targets, server_targets],
  env: 'srcdir=' + _srcdir,
  is_parallel: false,
  timeout: 0,
  verbose: true,
  workdir: meson.current_build_dir(),
  )
