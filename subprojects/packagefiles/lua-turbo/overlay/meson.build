project('lua-turbo', 'c', version: '2.1.3')

meson.override_dependency(meson.project_name(), declare_dependency(version: meson.project_version()))

crypto_dep = dependency('libcrypto')
lua_dep = dependency('lua', version: ['>= 5.1'], fallback: 'luajit')
ssl_dep = dependency('libssl')

shared_module(
  'tffi_wrap',
  [
    'deps/http-parser/http_parser.c',
    'deps/turbo_ffi_wrap.c',
  ],
  c_args: '-DHTTP_PARSER_STRICT=0',
  dependencies: [
    crypto_dep,
    lua_dep,
    ssl_dep,
  ],
  gnu_symbol_visibility: 'hidden',
  include_directories: include_directories(
    'deps/http-parser',
  ),
  install: true,
  install_dir: 'common',
  install_tag: 'runtime',
)

install_data(
  'turbo.lua',
  'turbovisor.lua',
  install_dir: 'common',
  install_tag: 'runtime',
)

install_subdir(
  'turbo',
  # Ignore outdated certificates…
  exclude_files: 'ca-certificates.crt',
  install_dir: 'common',
  install_tag: 'runtime',
)
