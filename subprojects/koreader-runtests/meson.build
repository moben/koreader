project('koreader-runtests')

dependency('lua-busted')
dependency('luacov')
dependency('luafilesystem')

fs = import('fs')

_toinstall = {
  '.busted': 'busted_config.lua',
  'runtests': 'runtests',
}

foreach _dst, _src : _toinstall
  if get_option('install_symlinks')
    install_symlink(
      fs.name(_dst),
      install_dir: fs.parent(_dst),
      install_tag: 'runtime',
      pointing_to: meson.project_source_root() / _src,
    )
  else
    install_data(
      _src,
      install_dir: fs.parent(_dst),
      install_tag: 'runtime',
      rename: fs.name(_dst),
    )
  endif
endforeach
