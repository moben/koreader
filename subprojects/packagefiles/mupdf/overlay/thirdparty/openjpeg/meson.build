compile_args = ['-DOPJ_STATIC']
if cc.has_header('stdint.h')
  compile_args += '-DOPJ_HAVE_STDINT_H'
endif
if cc.has_header('inttypes.h')
  compile_args += '-DOPJ_HAVE_INTTYPES_H'
endif

sources = []
foreach _file : [
  'bio.c',
  'cio.c',
  'dwt.c',
  'event.c',
  'function_list.c',
  'image.c',
  'invert.c',
  'j2k.c',
  'jp2.c',
  'mct.c',
  'mqc.c',
  'openjpeg.c',
  'pi.c',
  'raw.c',
  't1.c',
  't2.c',
  'tcd.c',
  'tgt.c',
  'thread.c',
]
  sources += 'src/lib/openjp2' / _file
endforeach

openjp2_lib = static_library(
  'openjp2',
  c_args: compile_args,
  sources: sources,
)

openjp2_dep = declare_dependency(
  compile_args: compile_args,
  include_directories: include_directories('src/lib/openjp2'),
  link_with: openjp2_lib,
)
