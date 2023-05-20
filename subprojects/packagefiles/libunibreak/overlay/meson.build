project('libunibreak', 'c', version: '5.1')

subdir('src')

unibreak_lib = library(
  'unibreak',
  unibreak_sources,
  install: true,
)

unibreak_dep = declare_dependency(
  include_directories: include_directories('src'),
  link_with: unibreak_lib,
)

meson.override_dependency('libunibreak', unibreak_dep)
