# Init. {{{

project(
  'curl',
  'c',
  version: '8.0.1',
  meson_version: '>=0.63',
)

fs = import('fs')
cc = meson.get_compiler('c')
cdata = configuration_data()

sys_deps = []
lib_deps = []

# Constants. {{{

CURL_PUBLIC_INC = include_directories('include')
CURL_INTERNAL_INC = include_directories('lib')
CURL_VERSION = cc.get_define(
  'LIBCURL_VERSION',
  include_directories: CURL_PUBLIC_INC,
  prefix: '#include"curl/curlver.h"',
).strip('"')
if CURL_VERSION.endswith('-DEV')
  CURL_VERSION = CURL_VERSION.substring(0, -4)
endif
CURL_VERSION_NUM = cc.get_define(
  'LIBCURL_VERSION_NUM',
  include_directories: CURL_PUBLIC_INC,
  prefix: '#include"curl/curlver.h"',
)

if CURL_VERSION != meson.project_version()
  error(
    'versions mismatch, meson has @0@, while `culver.h` reports @1@!'.format(
      meson.project_version(),
      CURL_VERSION,
    ),
  )
endif

# }}}

# }}}

# Platform dependencies. {{{

if host_machine.system() == 'windows'
  ws2_32_dep = cc.find_library('ws2_32', required: false)
  if ws2_32_dep.found() and cc.has_function('getch', dependencies: ws2_32_dep)
    sys_deps += ws2_32_dep
  endif
  winmm_dep = cc.find_library('winmm', required: false)
  if winmm_dep.found() and cc.has_function('getch', dependencies: winmm_dep)
    sys_deps += winmm_dep
  endif
endif

# }}}

# Basic checks. {{{

check_args = []
check_headers = []

_headerlist = {
  'arpa/inet.h': [
    'getpeername',
    'getsockname',
    'inet_ntop',
    'inet_pton',
    'setsockopt',
  ],
  'arpa/tftp.h': [],
  'bsd/unistd.h': [
    'setmode',
  ],
  'fcntl.h': [
    'fcntl',
  ],
  'fnmatch.h': [
    'fnmatch',
  ],
  'idn2.h': [],
  'ifaddrs.h': [],
  'inttypes.h': [],
  'io.h': [],
  'krb.h': [],
  'libgen.h': [
    'basename',
  ],
  'linux/tcp.h': [],
  'locale.h': [
    'setlocale',
  ],
  'net/if.h': [
    'if_nametoindex',
  ],
  'netdb.h': [
    'freeaddrinfo',
    'getaddrinfo',
    'gethostbyname_r',
  ],
  'netinet/in.h': [],
  'netinet/in6.h': [],
  'netinet/tcp.h': [],
  'pem.h': [],
  'poll.h': [
    'poll',
  ],
  'process.h': [],
  'proto/bsdsocket.h': [],
  'pwd.h': [
    'getpwuid',
    'getpwuid_r',
  ],
  'setjmp.h': [
    'sigsetjmp',
  ],
  'signal.h': [
    'SIGALRM',
    'sigaction',
    'siginterrupt',
    'signal',
  ],
  'sockio.h': [],
  'ssl.h': [],
  'stdatomic.h': [],
  'stdbool.h': [],
  'stddef.h': [],
  'stdint.h': [],
  'stdio.h': [],
  'stdlib.h': [
    '_strtoi64',
    'strtoll',
  ],
  'string.h': [
    'strcmpi',
    'strdup',
    'strerror_r',
    'stricmp',
    'strncmpi',
    'strstr',
    'strtok_r',
  ],
  'strings.h': [
    'strcasecmp',
  ],
  'stropts.h': [],
  'sys/filio.h': [],
  'sys/ioctl.h': [],
  'sys/param.h': [],
  'sys/poll.h': [],
  'sys/resource.h': [
    'getrlimit',
    'setrlimit',
  ],
  'sys/select.h': [
    'select',
  ],
  'sys/socket.h': [
    'sa_family_t',
    'socket',
    'socketpair',
  ],
  'sys/sockio.h': [],
  'sys/stat.h': [
    'fchmod',
  ],
  'sys/time.h': [
    'gettimeofday',
    'utimes',
  ],
  'sys/types.h': [],
  'sys/uio.h': [],
  'sys/un.h': [],
  'sys/utime.h': [],
  'sys/utsname.h': [
    'uname',
  ],
  'sys/wait.h': [],
  'sys/xattr.h': [
    'fsetxattr',
  ],
  'termio.h': [],
  'termios.h': [],
  'time.h': [
    'clock_gettime',
    'gmtime_r',
    'strftime',
  ],
  'unistd.h': [
    'alarm',
    'ftruncate',
    'geteuid',
    'gethostname',
    'getpass_r',
    'getppid',
    'pipe',
  ],
  'utime.h': [
    'utime',
  ],
}

if host_machine.system() == 'windows'
  _headerlist += {
    'windows.h': [],
    'winsock.h': [
      'closesocket',
    ],
    'winsock2.h': [
      'ADDRESS_FAMILY',
      'select',
      'socket',
    ],
    'wincrypt.h': [],
    'ws2tcpip.h': [
      'freeaddrinfo',
      'getaddrinfo',
      'inet_ntop',
      'inet_pton',
    ],
  }
endif

foreach _header, _symlist : _headerlist
  if not cc.has_header(_header)
    continue
  endif
  _var = 'HAVE_' + _header.underscorify().to_upper()
  cdata.set(_var, true)
  check_args += f'-D@_var@'
  check_headers += _header
  foreach _symbol : _symlist
    cdata.set(
      'HAVE_' + _symbol.underscorify().to_upper(),
      cc.has_header_symbol(_header, _symbol),
    )
  endforeach
endforeach

check_prefix = {}
foreach _name, _headerlist : {
  'stdinc': [
    'sys/types.h',
    'stdint.h',
    'stddef.h',
  ],
  'timeinc': [
    'sys/time.h',
    'time.h',
  ],
}
  _prefix = []
  foreach _header : _headerlist
    if _header in check_headers
      _prefix += f'#include<@_header@>'
    endif
  endforeach
  check_prefix += {_name: '\n'.join(_prefix)}
endforeach

foreach _type, _prefix : {
  'int': check_prefix['stdinc'],
  'short': check_prefix['stdinc'],
  'long': check_prefix['stdinc'],
  'long double': check_prefix['stdinc'],
  'long long': check_prefix['stdinc'],
  '__int64': check_prefix['stdinc'],
  'off_t': check_prefix['stdinc'],
  'size_t': check_prefix['stdinc'],
  'ssize_t': check_prefix['stdinc'],
  'time_t': check_prefix['stdinc'],
  'curl_off_t': '#include"curl/system.h"',
}
  _var = _type.underscorify().to_upper()
  _size_var = f'SIZEOF_@_var@'
  _have_var = f'HAVE_@_size_var@'
  _size = cc.sizeof(
    _type,
    args: check_args,
    include_directories: CURL_PUBLIC_INC,
    prefix: _prefix,
  )
  if _size >= 0
    cdata.set(_have_var, 1)
  endif
  cdata.set(_size_var, _size)
endforeach

cdata.set(
  'HAVE_GETIFADDRS',
  cc.has_function(
    'getifaddrs',
    prefix: '''
  #include <sys/types.h>
  #include <ifaddrs.h>
  ''',
  ),
)

if not cdata.get('HAVE_GETPWUID_R', false) and cc.has_function('getpwuid_r')
  cdata.set('HAVE_GETPWUID_R', true)
  cdata.set('HAVE_DECL_GETPWUID_R_MISSING', true)
endif

cdata.set('HAVE_SIGNAL', cdata.get('HAVE_SIGALRM') and cdata.get('HAVE_SIGNAL'))

cdata.set(
  'HAVE_SUSECONDS_T',
  cc.has_type('suseconds_t', prefix: '#include<sys/time.h>'),
)

cdata.set('HAVE_LONGLONG', cdata.has('HAVE_SIZEOF_LONG_LONG'))
if not cdata.has('HAVE_SIZEOF_SSIZE_T')
  if cdata.get('SIZEOF_LONG') == cdata.get('SIZEOF_SIZE_T')
    cdata.set('ssize_t', 'long')
  endif
  if (
    not cdata.has('ssize_t')
    and cdata.get('SIZEOF___INT64') == cdata.get('SIZEOF_SIZE_T')
  )
    cdata.set('ssize_t', '__int64')
  endif
endif

if cdata.has('HAVE_CLOCK_GETTIME')
  sys_deps += cc.find_library('rt', required: false)
  if not cc.has_function('clock_gettime', dependencies: sys_deps)
    error('cannot link with `clock_gettime`')
  endif
endif

# }}}

# Features & protocols. {{{

# DNS. {{{

_provider = get_option('asynchdns')
enable_asynchdns = _provider != 'disabled'

# Threader resolver.
if _provider in ['auto', 'threaded']
  threads_dep = dependency('threads', required: _provider == 'threaded')
  enable_asynchdns = threads_dep.found()
  if host_machine.system() == 'windows'
    cdata.set('USE_THREADS_WIN32', enable_asynchdns)
  else
    cdata.set('USE_THREADS_POSIX', enable_asynchdns)
    cdata.set(
      'HAVE_PTHREAD_H',
      cc.has_header(
        'pthread.h',
        dependencies: threads_dep,
      ),
    )
  endif
  lib_deps += threads_dep
endif

# c-ares resolver.
if _provider == 'ares'
  lib_deps += dependency('libcares', required: true)
  cdata.set('USE_ARES', 1)
  enable_asynchdns = true
endif

# }}}

# Brotli. {{{

enable_brotli = get_option('brotli')
brotli_dep = dependency('libbrotlidec', required: enable_brotli)
enable_brotli = brotli_dep.found()
lib_deps += enable_brotli ? brotli_dep : []

cdata.set('HAVE_BROTLI', enable_brotli)

# }}}

# IDN. {{{

# enable_idn = get_option('idn')
# idn2_dep = dependenc('libidn2', required: libidn2)
# enable_idn = enable_idn.require(idn2_dep.found(), error_message: 'libidn2 not found')
# if enable_unixsockets.allowed() and host_machine.system() != 'windows'

# USE_WIN32_IDN or USE_LIBIDN2

# subdir_done()

# }}}

# IPv6. {{{

enable_ipv6 = get_option('ipv6')
if enable_ipv6.allowed() and host_machine.system() != 'windows'
  enable_ipv6 = enable_ipv6.require(
    cc.has_members(
      'struct sockaddr_in6',
      'sin6_addr',
      'sin6_scope_id',
      prefix: '#include<netinet/in.h>',
    ),
    error_message: 'struct sockaddr_in6 not available',
  )
endif
enable_ipv6 = enable_ipv6.allowed()

cdata.set('ENABLE_IPV6', enable_ipv6)

# }}}

# Large file. {{{

use_win32_largefile = host_machine.system() == 'windows'
enable_largefile = (
  use_win32_largefile
  or (cdata.get('SIZEOF_CURL_OFF_T') > 4
  and cdata.get('SIZEOF_OFF_T') > 4)
)
cdata.set('USE_WIN32_LARGE_FILES', use_win32_largefile)

# }}}

# LDAP. {{{

enable_ldap = get_option('ldap')
enable_ldaps = get_option('ldaps').require(enable_ldap.allowed())
enable_ldap = false
enable_ldaps = false

# }}}

# Samba. {{{

enable_smb = get_option('smb')
enable_smb = false

# }}}

# SSH. {{{

ssh_provider = get_option('ssh')
enable_ssh = false

foreach _lib, _header : {
  'libssh2': 'libssh2.h',
  'libssh': 'libssh/libssh.h',
}
  if ssh_provider not in ['auto', _lib]
    continue
  endif
  _required = ssh_provider == _lib
  ssh_dep = dependency(_lib, required: _required)
  if (
    ssh_dep.found()
    and cc.has_header(
      _header,
      dependencies: ssh_dep.partial_dependency(includes: true),
      required: _required,
    )
  )
    cdata.set('HAVE_' + _header.underscorify().to_upper(), true)
    cdata.set('USE_' + _lib.to_upper(), true)
    lib_deps += ssh_dep
    enable_ssh = true
    break
  endif
endforeach

# }}}

# SSL. {{{

enable_ssl = get_option('ssl').allowed()

# OpenSSL. {{{

enable_openssl = get_option(
  'openssl',
).require(enable_ssl, error_message: 'feature ssl is disabled')
openssl_dep = dependency('openssl', required: enable_openssl)
enable_openssl = openssl_dep.found()

if enable_openssl
  partial_openssl_dep = openssl_dep.partial_dependency(
    compile_args: true,
    includes: true,
  )
  cdata.set(
    'HAVE_OPENSSL_VERSION',
    cc.has_header_symbol(
      'openssl/crypto.h',
      'OpenSSL_version',
      dependencies: partial_openssl_dep,
    ),
  )
  cdata.set(
    'HAVE_RAND_EGD',
    cc.has_header_symbol(
      'openssl/rand.h',
      'RAND_egd',
      dependencies: partial_openssl_dep,
    ),
  )
  cdata.set(
    'HAVE_OPENSSL_SRP',
    cc.has_header_symbol(
      'openssl/ssl.h',
      'SSL_CTX_set_srp_password',
      dependencies: partial_openssl_dep,
    )
    and cc.has_header_symbol(
      'openssl/ssl.h',
      'SSL_CTX_set_srp_username',
      dependencies: partial_openssl_dep,
    ),
  )
  lib_deps += openssl_dep
endif

cdata.set('USE_OPENSSL', enable_openssl)

# }}}

enable_ssl = enable_openssl
get_option(
  'ssl',
).require(enable_ssl, error_message: 'no supported library found')

enable_tls_srp = get_option(
  'tls_srp',
).require(cdata.get('HAVE_OPENSSL_SRP', false)).allowed()
cdata.set('USE_TLS_SRP', enable_tls_srp)

# }}}

# Unix sockets. {{{

enable_unixsockets = get_option('unixsockets')
if enable_unixsockets.allowed() and host_machine.system() != 'windows'
  enable_unixsockets = enable_unixsockets.require(
    cc.has_member(
      'struct sockaddr_un',
      'sun_path',
      prefix: '#include<sys/un.h>',
    ),
    error_message: 'struct sockaddr_un not available',
  )
endif
enable_unixsockets = enable_unixsockets.allowed()

cdata.set('USE_UNIX_SOCKETS', enable_unixsockets)

# }}}

# Tests. {{{

enable_tests = get_option('tests')

# Absolute minimum for setting up & running the testsuite.
perl_exe = find_program('perl', required: enable_tests)
make_exe = find_program('make', required: enable_tests)

enable_tests = enable_tests.require(perl_exe.found() and make_exe.found()).allowed()

# }}}

# ZLIB. {{{

enable_libz = get_option('zlib')
zlib_dep = dependency('zlib', required: enable_libz)
enable_libz = (
  zlib_dep.found()
  and cc.has_header(
    'zlib.h',
    dependencies: zlib_dep.partial_dependency(includes: true),
    required: enable_libz,
  )
)
lib_deps += enable_libz ? zlib_dep : []

cdata.set('HAVE_LIBZ', enable_libz)
cdata.set('HAVE_ZLIB_H', enable_libz)

# }}}

# ZSTD. {{{

enable_zstd = get_option('zstd')
zstd_dep = dependency('libzstd', required: enable_zstd)
enable_zstd = (
  zstd_dep.found()
  and cc.has_header(
    'zstd.h',
    dependencies: zstd_dep.partial_dependency(includes: true),
    required: enable_zstd,
  )
)
lib_deps += enable_zstd ? zstd_dep : []

cdata.set('HAVE_ZSTD', enable_zstd)

# }}}

# }}}

# Advanced checks. {{{

_curl_tests = []

if cdata.has('HAVE_FSETXATTR')
  _curl_tests += ['HAVE_FSETXATTR_5', 'HAVE_FSETXATTR_6']
endif

_curl_tests += [
  'HAVE_FCNTL_O_NONBLOCK',
  'HAVE_IOCTLSOCKET',
  'HAVE_IOCTLSOCKET_CAMEL',
  'HAVE_IOCTLSOCKET_CAMEL_FIONBIO',
  'HAVE_IOCTLSOCKET_FIONBIO',
  'HAVE_IOCTL_FIONBIO',
  'HAVE_IOCTL_SIOCGIFADDR',
  'HAVE_SETSOCKOPT_SO_NONBLOCK',
  'TIME_WITH_SYS_TIME',
  'HAVE_O_NONBLOCK',
  'HAVE_GETHOSTBYNAME_R_3',
  'HAVE_GETHOSTBYNAME_R_5',
  'HAVE_GETHOSTBYNAME_R_6',
  'HAVE_GETHOSTBYNAME_R_3_REENTRANT',
  'HAVE_GETHOSTBYNAME_R_5_REENTRANT',
  'HAVE_GETHOSTBYNAME_R_6_REENTRANT',
  'HAVE_IN_ADDR_T',
  'HAVE_BOOL_T',
  'STDC_HEADERS',
  'HAVE_FILE_OFFSET_BITS',
  'HAVE_VARIADIC_MACROS_C99',
  'HAVE_VARIADIC_MACROS_GCC',
  'HAVE_ATOMIC',
  'HAVE_GLIBC_STRERROR_R',
  'HAVE_POSIX_STRERROR_R',
  'HAVE_CLOCK_GETTIME_MONOTONIC',
  'HAVE_BUILTIN_AVAILABLE',
]

foreach _test : _curl_tests
  cdata.set(
    _test,
    cc.links(
      files('CMake/CurlTests.c'),
      args: check_args + f'-D@_test@',
      dependencies: sys_deps,
      name: f'@_test@ test',
    ),
  )
endforeach

_signature_call_conv = ''
_source_epilogue = '#undef inline'

if host_machine.system() == 'windows'
  foreach _header : [
    'windows.h',
    'winsock2.h',
  ]
    if _header in check_headers
      _source_epilogue += f'\n#include<@_header@>'
    endif
  endforeach
  _source_epilogue += f'\n#ifndef WIN32_LEAN_AND_MEAN\n#define WIN32_LEAN_AND_MEAN\n#endif'
  _signature_call_conv = 'PASCAL'
else
  foreach _header : [
    'proto/bsdsocket.h',
    'sys/types.h',
    'sys/socket.h',
    'sys/time.h',
    'time.h',
  ]
    if _header in check_headers
      _source_epilogue += f'\n#include<@_header@>'
    endif
  endforeach
endif

if cdata.get('HAVE_STDATOMIC_H')
  enable_threadsafe = true
elif host_machine.system() == 'windows'
  enable_threadsafe = cc.compiles(
    '''
    #include <windows.h>
    #if (WINVER < 0x600) && (_WIN32_WINNT < 0x600)
    #error
    #endif
    ''',
    name: 'threadsafe',
  )
else
  enable_threadsafe = false
endif

cdata.set(
  'HAVE_GETADDRINFO_THREADSAFE',
  host_machine.system() == 'windows'
  or cc.compiles(
    '''
    #ifdef HAVE_SYS_SOCKET_H
    #  include<sys/socket.h>
    #endif
    #ifdef HAVE_NETDB_H
    #  include<netdb.h>
    #endif
    int main(void) {
      #ifndef h_errno
        force compilation error
      #endif
      #if defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 200809L)
      #elif defined(_XOPEN_SOURCE) && (_XOPEN_SOURCE >= 700)
      #else
        force compilation error
      #endif
      h_errno = 2;
      if(0 != h_errno)
        return 1;
      return 0;
    }
    ''',
    args: check_args,
    dependencies: sys_deps,
    name: 'HAVE_GETADDRINFO_THREADSAFE test',
  ),
)

cdata.set(
  'HAVE_RECV',
  cc.links(
    f'''
  @_source_epilogue@
  int main(void) {
    recv(0, 0, 0, 0);
    return 0;
  }
  ''',
    args: check_args,
    dependencies: sys_deps,
    name: 'HAVE_RECV test',
  ),
)

cdata.set(
  'HAVE_SEND',
  cc.links(
    f'''
  @_source_epilogue@
  int main(void) {
    send(0, 0, 0, 0);
    return 0;
  }
  ''',
    args: check_args,
    dependencies: sys_deps,
    name: 'HAVE_SEND test',
  ),
)

cdata.set(
  'HAVE_MSG_NOSIGNAL',
  cc.links(
    f'''
  @_source_epilogue@
  int main(void) {
    int flag = MSG_NOSIGNAL;
    (void)flag;
    return 0;
  }
  ''',
    name: 'HAVE_MSG_NOSIGNAL test',
  ),
)

cdata.set(
  'HAVE_STRUCT_TIMEVAL',
  cc.links(
    f'''
  @_source_epilogue@
  int main(void) {
    struct timeval ts;
    ts.tv_sec  = 0;
    ts.tv_usec = 0;
    (void)ts;
    return 0;
  }
  ''',
    name: 'HAVE_STRUCT_TIMEVAL test',
  ),
)

cdata.set(
  'HAVE_STRUCT_SOCKADDR_STORAGE',
  cc.sizeof(
    'struct sockaddr_storage',
    prefix: _source_epilogue,
  ) > 0,
)

cdata.set(
  'HAVE_POLL_FINE',
  meson.can_run_host_binaries()
  and cc.run(
    '''
  #include <stdlib.h>
  #include <sys/time.h>
  #ifdef HAVE_SYS_POLL_H
  #  include <sys/poll.h>
  #elif  HAVE_POLL_H
  #  include <poll.h>
  #endif
  int main(void)
  {
      if(0 != poll(0, 0, 10)) {
        return 1; /* fail */
      }
      else {
        /* detect the 10.12 poll() breakage */
        struct timeval before, after;
        int rc;
        size_t us;
        gettimeofday(&before, NULL);
        rc = poll(NULL, 0, 500);
        gettimeofday(&after, NULL);
        us = (after.tv_sec - before.tv_sec) * 1000000 +
          (after.tv_usec - before.tv_usec);
        if(us < 400000) {
          return 1;
        }
      }
      return 0;
  }
  ''',
    args: check_args,
    dependencies: sys_deps,
    name: 'HAVE_POLL_FINE test',
  ).returncode() == 0,
)

cdata.set(
  'HAVE_TIME_T_UNSIGNED',
  meson.is_cross_build()
  and meson.can_run_host_binaries()
  and cc.run(
    '''
  #include <time.h>
  #include <limits.h>
  int main(void) {
    time_t t = -1;
    return (t > 0);
  }
  ''',
    name: 'HAVE_TIME_T_UNSIGNED test',
  ).returncode() == 0,
)

# NEED_REENTRANT. {{{

_need_reentrant = false

_flaglist = [
  'HAVE_GETHOSTBYNAME_R_3',
  'HAVE_GETHOSTBYNAME_R_5',
  'HAVE_GETHOSTBYNAME_R_6',
]

foreach _flag : _flaglist
  if not cdata.get(_flag) and cdata.get(_flag + '_REENTRANT')
    _need_reentrant = true
  endif
endforeach

cdata.set('NEED_REENTRANT', _need_reentrant)

if _need_reentrant
  foreach _flag : _flaglist
    cdata.set(_flag, cdata.get(_flag + '_REENTRANT'))
  endforeach
endif

# }}}

# }}}.

# Finalize config. {{{

# OS {{{

# The testsuite rely on a particular formatting,
# e.g. for dectecting the Windows build.
_os = '-'.join(host_machine.cpu(), host_machine.system())
_os = {
  # 'x86_64-linux-gcc': 'x86_64-pc-linux-gnu',
  'x86_64-windows-gcc': 'x86_64-w64-mingw32',
}.get('-'.join(_os, cc.get_id()), _os)
cdata.set_quoted('OS', _os)

if (
  cc.get_id() == 'msvc'
  or (cc.get_id() == 'gcc'
  and cc.version().version_compare('>=3.4'))
)
  cdata.set(
    'CURL_EXTERN_SYMBOL',
    '__attribute__ ((__visibility__ ("default")))',
  )
endif
if cc.has_argument('-fvisibility=hidden')
  add_project_arguments('-fvisibility=hidden', language: 'c')
endif

# }}}

# CA. {{{

ca_bundle = get_option('ca_bundle')
if ca_bundle == 'auto'
  foreach _path : [
    '/etc/ssl/certs/ca-certificates.crt',
    '/etc/pki/tls/certs/ca-bundle.crt',
    '/usr/share/ssl/certs/ca-bundle.crt',
    '/usr/local/share/certs/ca-root-nss.crt',
    '/etc/ssl/cert.pem',
  ]
    if fs.is_file(_path)
      ca_bundle = _path
      break
    endif
  endforeach
  if ca_bundle == 'auto'
    error('CA bundle auto-detection failed')
  endif
endif
cdata.set_quoted('CURL_CA_BUNDLE', ca_bundle)

ca_path = get_option('ca_bundle')
if ca_path == 'auto'
  foreach _path : [
    '/etc/ssl/certs',
  ]
    if fs.is_dir(_path)
      ca_path = _path
      break
    endif
  endforeach
  if ca_path == 'auto'
    error('CA path auto-detection failed')
  endif
endif
cdata.set_quoted('CURL_CA_PATH', ca_path)

cdata.set('CURL_CA_FALLBACK', get_option('ca_fallback'))

# }}}

# Features. {{{

foreach _feat : [
  'alt_svc',
  'cookies',
  'crypto_auth',
  'getoptions',
  'http_auth',
  'hsts',
  'https_proxy',
  'libcurl_option',
  'netrc',
  'proxy',
  'mime',
  'parsedate',
  'progress_meter',
  'verbose_strings',
]
  set_variable('enable_' + _feat, _feat in get_option('features'))
endforeach
enable_https_proxy = enable_proxy and enable_ssl and enable_openssl

cdata.set('CURL_DISABLE_ALTSVC', not enable_alt_svc)
cdata.set('CURL_DISABLE_COOKIES', not enable_cookies)
cdata.set('CURL_DISABLE_CRYPTO_AUTH', not enable_crypto_auth)
cdata.set('CURL_DISABLE_DOH', false)
cdata.set('CURL_DISABLE_GETOPTIONS', not enable_getoptions)
cdata.set('CURL_DISABLE_HSTS', not enable_hsts)
cdata.set('CURL_DISABLE_HTTP_AUTH', not enable_http_auth)
cdata.set('CURL_DISABLE_LIBCURL_OPTION', not enable_libcurl_option)
cdata.set('CURL_DISABLE_MIME', not enable_mime)
cdata.set('CURL_DISABLE_NETRC', not enable_netrc)
cdata.set('CURL_DISABLE_NTLM', true)
cdata.set('CURL_DISABLE_OPENSSL_AUTO_LOAD_CONFIG', false)
cdata.set('CURL_DISABLE_PARSEDATE', not enable_parsedate)
cdata.set('CURL_DISABLE_PROGRESS_METER', not enable_progress_meter)
cdata.set('CURL_DISABLE_PROXY', not enable_proxy)
cdata.set('CURL_DISABLE_SHUFFLE_DNS', false)
cdata.set('CURL_DISABLE_SOCKETPAIR', false)
cdata.set('CURL_DISABLE_VERBOSE_STRINGS', not enable_verbose_strings)

# }}}.

# Protocols. {{{

foreach _proto : [
  'dict',
  'file',
  'ftp',
  'gopher',
  'imap',
  'http',
  'mqtt',
  'pop3',
  'rtsp',
  'smtp',
  'telnet',
  'tftp',
]
  set_variable('enable_' + _proto, _proto in get_option('protocols'))
endforeach
enable_ftps = enable_ssl and enable_ftp
enable_gophers = enable_ssl and enable_gopher
enable_https = enable_ssl and enable_http
enable_imaps = enable_ssl and enable_imap
enable_pop3s = enable_ssl and enable_pop3
enable_scp = enable_ssh
enable_sftp = enable_ssh
enable_smtps = enable_ssl and enable_smtp

cdata.set('CURL_DISABLE_DICT', not enable_dict)
cdata.set('CURL_DISABLE_FILE', not enable_file)
cdata.set('CURL_DISABLE_FTP', not enable_ftp)
cdata.set('CURL_DISABLE_GOPHER', not enable_gopher)
cdata.set('CURL_DISABLE_HTTP', not enable_http)
cdata.set('CURL_DISABLE_IMAP', not enable_imap)
cdata.set('CURL_DISABLE_LDAP', not enable_ldap)
cdata.set('CURL_DISABLE_LDAPS', not enable_ldaps)
cdata.set('CURL_DISABLE_MQTT', not enable_mqtt)
cdata.set('CURL_DISABLE_POP3', not enable_pop3)
cdata.set('CURL_DISABLE_RTSP', not enable_rtsp)
cdata.set('CURL_DISABLE_SMB', not enable_smb)
cdata.set('CURL_DISABLE_SMTP', not enable_smtp)
cdata.set('CURL_DISABLE_TELNET', not enable_telnet)
cdata.set('CURL_DISABLE_TFTP', not enable_tftp)

# }}}

# Reported features, protocols, and SSL backends. {{{

foreach _var, _namelist : {
  'features': [
    'Alt-Svc',
    'AsynchDNS',
    'Brotli',
    'HTTPS-proxy',
    'HSTS',
    'IPv6',
    'Largefile',
    'LibZ',
    'SSL',
    'TLS-SRP',
    'ThreadSafe',
    'UnixSockets',
    'ZSTD',
  ],
  'protocols': [
    'DICT',
    'FILE',
    'FTP',
    'FTPS',
    'GOPHER',
    'GOPHERS',
    'HTTP',
    'HTTPS',
    'IMAP',
    'IMAPS',
    'LDAP',
    'LDAPS',
    'MQTT',
    'POP3',
    'POP3S',
    'RTSP',
    'SCP',
    'SFTP',
    'SMB',
    'SMTP',
    'SMTPS',
    'TELNET',
    'TFTP',
  ],
  'ssl_backends': [
    'OpenSSL',
  ],
}
  _summary = {}
  _enabled = []
  _disabled = []
  foreach _name : _namelist
    _id = 'enable_' + _name.underscorify().to_lower()
    _summary += {_name: get_variable(_id)}
    if get_variable(_id)
      _enabled += _name
    else
      _disabled += _name
    endif
  endforeach
  set_variable(_var + '_summary', _summary)
  set_variable('enabled_' + _var, _enabled)
  set_variable('disabled_' + _var, _disabled)
endforeach

# }}}

# Other. {{{

cdata.set('CURL_WITH_MULTI_SSL', enabled_ssl_backends.length() > 1)

if fs.exists('/dev/urandom')
  cdata.set_quoted('RANDOM_FILE', '/dev/urandom')
endif

cdata.set('DEBUGBUILD', get_option('debug'))
cdata.set('CURLDEBUG', get_option('curldebug'))

# }}}

# `curl-config` variables. {{{

cdata.set_quoted('CURLVERSION', CURL_VERSION)
cdata.set_quoted('VERSIONNUM', CURL_VERSION_NUM.replace('0x', ''))

_link_args = get_option('c_link_args')
cdata.set('CC', ' '.join(cc.cmd_array()))
cdata.set(
  'LDFLAGS',
  _link_args.length() > 0 ? ('\'' + '\' \''.join(_link_args) + '\'') : '',
)
cdata.set_quoted(
  'CPPFLAG_CURL_STATICLIB',
  get_option('default_library') == 'static' ? '-DCURL_STATICLIB' : '',
)
cdata.set_quoted(
  'ENABLE_SHARED',
  get_option('default_library') in ['both', 'shared'] ? 'yes' : 'no',
)
cdata.set_quoted(
  'ENABLE_STATIC',
  get_option('default_library') in ['both', 'static'] ? 'yes' : 'no',
)
# FIXME
cdata.set('CONFIGURE_OPTIONS', '')
cdata.set('LIBCURL_LIBS', '')

cdata.set_quoted('prefix', get_option('prefix'))
cdata.set_quoted('exec_prefix', '${prefix}')
cdata.set_quoted('includedir', '${prefix}' / get_option('includedir'))
cdata.set_quoted('libdir', '${prefix}' / get_option('libdir'))
cdata.set_quoted('libext', 'a')

cdata.set('SUPPORT_FEATURES', ' '.join(enabled_features))
cdata.set('SUPPORT_PROTOCOLS', ' '.join(enabled_protocols))
cdata.set('SSL_BACKENDS', ' '.join(enabled_ssl_backends))

# }}}

# }}}

# Subdirs. {{{

subdir('lib')

if get_option('tool') or enable_tests
  subdir('src')
endif

if enable_tests
  subdir('tests')
endif

# }}}

# Targets. {{{

curl_config_script = configure_file(
  configuration: cdata,
  input: 'curl-config.in',
  output: 'curl-config',
)

# }}}

# Summary. {{{

summary(
  {
    'Path': cdata.get('CURL_CA_PATH'),
    'Bundle': cdata.get('CURL_CA_BUNDLE'),
    'Fallback': cdata.get('CURL_CA_FALLBACK'),
  },
  bool_yn: true,
  section: 'CA',
)

summary(
  features_summary,
  bool_yn: true,
  section: 'Features',
)

summary(
  protocols_summary,
  bool_yn: true,
  section: 'Protocols',
)

summary(
  ssl_backends_summary,
  bool_yn: true,
  section: 'SSL backends',
)

# }}}

# vim: foldmethod=marker foldlevel=0
