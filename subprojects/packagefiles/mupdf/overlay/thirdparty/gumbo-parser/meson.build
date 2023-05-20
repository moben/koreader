gumbo_parser_lib = static_library(
  'mupdf-gumbo-parser',
  files(
    'src/attribute.c',
    'src/char_ref.c',
    'src/error.c',
    'src/parser.c',
    'src/string_buffer.c',
    'src/string_piece.c',
    'src/tag.c',
    'src/tokenizer.c',
    'src/utf8.c',
    'src/util.c',
    'src/vector.c',
  ),
)

gumbo_parser_dep = declare_dependency(
  include_directories: include_directories('src'),
  link_with: gumbo_parser_lib,
)
