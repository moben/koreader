# To get an updated list of sources:
# `make -s -E $'all:\n\tprintf "'\''%s'\'',\\n" $(sort $(filter-out %.h,$(CURL_FILES)))' -f src/Makefile.inc`
curl_src = [
  '../lib/curl_multibyte.c',
  '../lib/dynbuf.c',
  '../lib/nonblock.c',
  '../lib/strtoofft.c',
  '../lib/timediff.c',
  '../lib/version_win32.c',
  '../lib/warnless.c',
  'slist_wc.c',
  'tool_binmode.c',
  'tool_bname.c',
  'tool_cb_dbg.c',
  'tool_cb_hdr.c',
  'tool_cb_prg.c',
  'tool_cb_rea.c',
  'tool_cb_see.c',
  'tool_cb_wrt.c',
  'tool_cfgable.c',
  'tool_dirhie.c',
  'tool_doswin.c',
  'tool_easysrc.c',
  'tool_filetime.c',
  'tool_findfile.c',
  'tool_formparse.c',
  'tool_getparam.c',
  'tool_getpass.c',
  'tool_help.c',
  'tool_helpers.c',
  'tool_hugehelp.c',
  'tool_libinfo.c',
  'tool_listhelp.c',
  'tool_main.c',
  'tool_msgs.c',
  'tool_operate.c',
  'tool_operhlp.c',
  'tool_paramhlp.c',
  'tool_parsecfg.c',
  'tool_progress.c',
  'tool_setopt.c',
  'tool_sleep.c',
  'tool_stderr.c',
  'tool_strdup.c',
  'tool_urlglob.c',
  'tool_util.c',
  'tool_vms.c',
  'tool_writeout.c',
  'tool_writeout_json.c',
  'tool_xattr.c'
]

# - remove all source arguments
# - run `meson rewrite target curl_exe add $(make -s -E $'all:\n\t$(info $(filter-out %.h,$(CURL_FILES)))' -f src/Makefile.inc)`
curl_exe = executable(
  'curl',
  curl_src,
  dependencies: [curl_internal_dep, sys_deps],
  install: get_option('tool'),
)

if enable_tests
  curltool_lib = static_library(
    'curltool',
    curl_src,
    c_args: ['-DCURL_STATICLIB', '-DUNITTESTS'],
    dependencies: [curl_internal_dep, sys_deps],
  )
  curltool_dep = declare_dependency(
    dependencies: [curl_internal_dep, sys_deps],
    link_with: curltool_lib,
  )
endif
