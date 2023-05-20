project('luacov', version: '0.15.0')

meson.override_dependency(meson.project_name(), declare_dependency(version: meson.project_version()))

dependency('lua', version: ['>= 5.1', '< 5.5'], fallback: 'luajit')

install_data(
  'src/bin/luacov',
  rename: [
    'luacov',
  ],
  install_dir: get_option('bindir'),
  install_tag: 'runtime',
)

install_data(
  'src/luacov.lua',
  'src/luacov/defaults.lua',
  'src/luacov/hook.lua',
  'src/luacov/linescanner.lua',
  'src/luacov/reporter.lua',
  'src/luacov/reporter/default.lua',
  'src/luacov/runner.lua',
  'src/luacov/stats.lua',
  'src/luacov/tick.lua',
  'src/luacov/util.lua',
  rename: [
    'luacov.lua',
    'luacov/defaults.lua',
    'luacov/hook.lua',
    'luacov/linescanner.lua',
    'luacov/reporter.lua',
    'luacov/reporter/default.lua',
    'luacov/runner.lua',
    'luacov/stats.lua',
    'luacov/tick.lua',
    'luacov/util.lua',
  ],
  install_dir: 'common',
  install_tag: 'runtime',
)
