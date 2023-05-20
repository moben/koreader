project('cpr', 'cpp',
  default_options: 'cpp_std=c++14',
  license: 'MIT',
  version: files('VERSION'),
  )

curl_dep = dependency('libcurl')
thread_dep = dependency('threads')

includes = include_directories('include')
subdir('cpr')

cpr_lib = library(
  'cpr',
  dependencies: [curl_dep, thread_dep],
  include_directories: includes,
  install: true,
  sources: cpr_src,
  )

cpr_dep = declare_dependency(include_directories: includes, link_with: cpr_lib)

meson.override_dependency('libcpr', cpr_dep)
