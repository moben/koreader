project('lua-htmlparser', version: '0.3.9')

meson.override_dependency(meson.project_name(), declare_dependency(version: meson.project_version()))

dependency('lua', version: ['>= 5.1'], fallback: 'luajit')

install_data(
  'src/htmlparser.lua',
  'src/htmlparser/ElementNode.lua',
  'src/htmlparser/voidelements.lua',
  rename: [
    'htmlparser.lua',
    'htmlparser/ElementNode.lua',
    'htmlparser/voidelements.lua',
  ],
  install_dir: 'common',
  install_tag: 'runtime',
)
