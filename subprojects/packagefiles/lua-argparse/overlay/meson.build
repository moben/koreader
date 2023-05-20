project('lua-argparse', version: '0.7.1')

meson.override_dependency(meson.project_name(), declare_dependency(version: meson.project_version()))

dependency('lua', version: ['>= 5.1', '< 5.5'], fallback: 'luajit')

install_data(
  'src/argparse.lua',
  rename: [
    'argparse.lua',
  ],
  install_dir: 'common',
  install_tag: 'runtime',
)
