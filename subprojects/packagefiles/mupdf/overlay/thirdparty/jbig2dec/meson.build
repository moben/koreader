c_args = []

if cc.has_header('stdint.h')
  c_args += '-DHAVE_STDINT_H'
endif

memento_header = meson.project_source_root() / 'include/mupdf/memento.h'
c_args += f'-DJBIG_EXTERNAL_MEMENTO_H="@memento_header@"'

jbig2dec_lib = static_library(
  'jbig2dec',
  c_args: c_args,
  sources: [
    'jbig2.c',
    'jbig2_arith.c',
    'jbig2_arith_iaid.c',
    'jbig2_arith_int.c',
    'jbig2_generic.c',
    'jbig2_halftone.c',
    'jbig2_huffman.c',
    'jbig2_image.c',
    'jbig2_metadata.c',
    'jbig2_mmr.c',
    'jbig2_page.c',
    'jbig2_refinement.c',
    'jbig2_segment.c',
    'jbig2_symbol_dict.c',
    'jbig2_text.c',
  ],
)

jbig2dec_dep = declare_dependency(
  include_directories: include_directories('.'),
  link_with: jbig2dec_lib,
)
