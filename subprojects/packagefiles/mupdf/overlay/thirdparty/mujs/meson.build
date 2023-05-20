mujs_lib = static_library(
  'mujs',
  dependencies: m_dep,
  sources: files('one.c'),
  )

mujs_dep = declare_dependency(
  include_directories: include_directories('.'),
  link_with: mujs_lib,
  )
