project(
  'gcc-lua', 'c',
  version: '1.3.0',
  default_options: 'c_std=none',
)

fs = import('fs')

native_cc = meson.get_compiler('c', native: true)
cross_cc = meson.get_compiler('c', native: false)

if native_cc.get_id() != 'gcc' or cross_cc.get_id() != 'gcc'
  error('this project only supports the GCC compiler')
endif

if native_cc.version().version_compare('>=13')
  error('gcc-lua is currently broken with GCC >= 13')
endif

gcc_plugins_dir = get_option('gcc_plugins_dir')
if gcc_plugins_dir == ''
  res = run_command([cross_cc, '-print-libgcc-file-name'], check: true)
  gcc_plugins_dir = fs.parent(res.stdout().strip()) / 'plugin'
endif

if not fs.is_dir(gcc_plugins_dir)
  error(f'plugins directory does not exists: “@gcc_plugins_dir@”')
endif

plugins_dir = get_option('plugins_dir')
if plugins_dir == ''
  plugins_dir = get_option('libdir') / 'gcc-plugins'
endif

includes = include_directories(gcc_plugins_dir / 'include', 'gcc')

native_cc.has_header(
  'gcc-plugin.h',
  include_directories: includes,
  required: true,
)

luajit_dep = dependency('luajit', native: true)
m_dep = native_cc.find_library('m', required: false)

plugin = shared_module(
  'gcclua',
  'gcc/gcclua.c',
  c_args: ['-x', 'c++'],
  dependencies: [luajit_dep, m_dep],
  include_directories: includes,
  install: true,
  install_dir: plugins_dir,
  install_tag: 'devel',
  name_prefix: '',
  native: true,
  override_options: 'b_sanitize=none',
)

plugin_path = plugins_dir / fs.name(plugin.full_path())
