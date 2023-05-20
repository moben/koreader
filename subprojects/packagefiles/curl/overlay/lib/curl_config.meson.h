/* lib/curl_config.h.in.  Generated from configure.ac by autoheader.  */

/* to enable curl debug memory tracking */
#mesondefine CURLDEBUG

/* Location of default CA bundle */
#mesondefine CURL_CA_BUNDLE

/* define to use built-in CA store of TLS backend */
#mesondefine CURL_CA_FALLBACK

/* Location of default CA path */
#mesondefine CURL_CA_PATH

/* Default SSL backend */
#mesondefine CURL_DEFAULT_SSL_BACKEND

/* disable Alt-Svc */
#mesondefine CURL_DISABLE_ALTSVC

/* disables cookies support */
#mesondefine CURL_DISABLE_COOKIES

/* disables cryptographic authentication */
#mesondefine CURL_DISABLE_CRYPTO_AUTH

/* disables DICT */
#mesondefine CURL_DISABLE_DICT

/* disables DNS-over-HTTPS */
#mesondefine CURL_DISABLE_DOH

/* disables FILE */
#mesondefine CURL_DISABLE_FILE

/* disables FTP */
#mesondefine CURL_DISABLE_FTP

/* disables curl_easy_options */
#mesondefine CURL_DISABLE_GETOPTIONS

/* disables GOPHER */
#mesondefine CURL_DISABLE_GOPHER

/* disables alt-svc */
#mesondefine CURL_DISABLE_HSTS

/* disables HTTP */
#mesondefine CURL_DISABLE_HTTP

/* disables HTTP authentication */
#mesondefine CURL_DISABLE_HTTP_AUTH

/* disables IMAP */
#mesondefine CURL_DISABLE_IMAP

/* disables LDAP */
#mesondefine CURL_DISABLE_LDAP

/* disables LDAPS */
#mesondefine CURL_DISABLE_LDAPS

/* disables --libcurl option from the curl tool */
#mesondefine CURL_DISABLE_LIBCURL_OPTION

/* disables MIME support */
#mesondefine CURL_DISABLE_MIME

/* disables MQTT */
#mesondefine CURL_DISABLE_MQTT

/* disables netrc parser */
#mesondefine CURL_DISABLE_NETRC

/* disables NTLM support */
#mesondefine CURL_DISABLE_NTLM

/* if the OpenSSL configuration won't be loaded automatically */
#mesondefine CURL_DISABLE_OPENSSL_AUTO_LOAD_CONFIG

/* disables date parsing */
#mesondefine CURL_DISABLE_PARSEDATE

/* disables POP3 */
#mesondefine CURL_DISABLE_POP3

/* disables built-in progress meter */
#mesondefine CURL_DISABLE_PROGRESS_METER

/* disables proxies */
#mesondefine CURL_DISABLE_PROXY

/* disables RTSP */
#mesondefine CURL_DISABLE_RTSP

/* disable DNS shuffling */
#mesondefine CURL_DISABLE_SHUFFLE_DNS

/* disables SMB */
#mesondefine CURL_DISABLE_SMB

/* disables SMTP */
#mesondefine CURL_DISABLE_SMTP

/* disables use of socketpair for curl_multi_poll */
#mesondefine CURL_DISABLE_SOCKETPAIR

/* disables TELNET */
#mesondefine CURL_DISABLE_TELNET

/* disables TFTP */
#mesondefine CURL_DISABLE_TFTP

/* disables verbose strings */
#mesondefine CURL_DISABLE_VERBOSE_STRINGS

/* to make a symbol visible */
#mesondefine CURL_EXTERN_SYMBOL
/* Ensure using CURL_EXTERN_SYMBOL is possible */
#if !defined(CURL_EXTERN_SYMBOL)
#define CURL_EXTERN_SYMBOL
#endif

/* built with multiple SSL backends */
#mesondefine CURL_WITH_MULTI_SSL

/* enable debug build options */
#mesondefine DEBUGBUILD

/* your Entropy Gathering Daemon socket pathname */
#mesondefine EGD_SOCKET

/* Define if you want to enable IPv6 support */
#mesondefine ENABLE_IPV6

/* Define to the type of arg 2 for gethostname. */
#mesondefine GETHOSTNAME_TYPE_ARG2

/* Define if you have `ADDRESS_FAMILY' type. */
#mesondefine HAVE_ADDRESS_FAMILY

/* Define if you have the alarm function. */
#mesondefine HAVE_ALARM

/* Define if you have the <arpa/inet.h> header file. */
#mesondefine HAVE_ARPA_INET_H

/* Define if you have the <arpa/tftp.h> header file. */
#mesondefine HAVE_ARPA_TFTP_H

/* Define if you have the <assert.h> header file. */
#mesondefine HAVE_ASSERT_H

/* Define if you have _Atomic support. */
#mesondefine HAVE_ATOMIC

/* Define if you have the basename function. */
#mesondefine HAVE_BASENAME

/* Define if bool is an available type. */
#mesondefine HAVE_BOOL_T

/* Define if using BoringSSL. */
#mesondefine HAVE_BORINGSSL

/* if BROTLI is in use */
#mesondefine HAVE_BROTLI

/* Define if you have the __builtin_available function. */
#mesondefine HAVE_BUILTIN_AVAILABLE

/* Define if you have the clock_gettime function and monotonic timer. */
#mesondefine HAVE_CLOCK_GETTIME_MONOTONIC

/* Define if you have the `closesocket` function. */
#mesondefine HAVE_CLOSESOCKET

/* Define if you have the `CloseSocket` function. */
#mesondefine HAVE_CLOSESOCKET_CAMEL

/* Define if you have the <crypto.h> header file. */
#mesondefine HAVE_CRYPTO_H

/* Define if you have the <errno.h> header file. */
#mesondefine HAVE_ERRNO_H

/* Define if you have the fcntl function. */
#mesondefine HAVE_FCNTL

/* Define if you have the `fchmod' function. */
#mesondefine HAVE_FCHMOD

/* Define if you have the <fcntl.h> header file. */
#mesondefine HAVE_FCNTL_H

/* Define if you have a working fcntl O_NONBLOCK function. */
#mesondefine HAVE_FCNTL_O_NONBLOCK

/* Define if you have the `fnmatch' function. */
#mesondefine HAVE_FNMATCH

/* Define if you have the freeaddrinfo function. */
#mesondefine HAVE_FREEADDRINFO

/* Define if you have the fsetxattr function. */
#mesondefine HAVE_FSETXATTR

/* fsetxattr() takes 5 args */
#mesondefine HAVE_FSETXATTR_5

/* fsetxattr() takes 6 args */
#mesondefine HAVE_FSETXATTR_6

/* Define if you have the ftruncate function. */
#mesondefine HAVE_FTRUNCATE

/* Define if you have a working getaddrinfo function. */
#mesondefine HAVE_GETADDRINFO

/* Define if the getaddrinfo function is threadsafe. */
#mesondefine HAVE_GETADDRINFO_THREADSAFE

/* Define if you have the `geteuid' function. */
#mesondefine HAVE_GETEUID

/* Define if you have the gethostbyname_r function. */
#mesondefine HAVE_GETHOSTBYNAME_R

/* gethostbyname_r() takes 3 args */
#mesondefine HAVE_GETHOSTBYNAME_R_3

/* gethostbyname_r() takes 5 args */
#mesondefine HAVE_GETHOSTBYNAME_R_5

/* gethostbyname_r() takes 6 args */
#mesondefine HAVE_GETHOSTBYNAME_R_6

/* Define if you have the gethostname function. */
#mesondefine HAVE_GETHOSTNAME

/* Define if you have a working getifaddrs function. */
#mesondefine HAVE_GETIFADDRS

/* Define if you have the `getpass_r' function. */
#mesondefine HAVE_GETPASS_R

/* Define if you have the `getppid' function. */
#mesondefine HAVE_GETPPID

/* Define if you have the `getpeername` function. */
#mesondefine HAVE_GETPEERNAME

/* Define if you have the getsockname function. */
#mesondefine HAVE_GETSOCKNAME

/* Define if you have the `getpwuid' function. */
#mesondefine HAVE_GETPWUID

/* Define if you have the `getpwuid_r' function. */
#mesondefine HAVE_GETPWUID_R

/* Define if `getpwuid_r` declaration is missing. */
#mesondefine HAVE_DECL_GETPWUID_R_MISSING

/* Define if you have the `getrlimit' function. */
#mesondefine HAVE_GETRLIMIT

/* Define if you have the `gettimeofday' function. */
#mesondefine HAVE_GETTIMEOFDAY

/* Define if you have a working glibc-style strerror_r function. */
#mesondefine HAVE_GLIBC_STRERROR_R

/* Define if you have a working gmtime_r function. */
#mesondefine HAVE_GMTIME_R

/* if you have the function gnutls_srp_verifier */
#mesondefine HAVE_GNUTLS_SRP

/* if you have GSS-API libraries */
#mesondefine HAVE_GSSAPI

/* Define if you have the <gssapi/gssapi_generic.h> header file. */
#mesondefine HAVE_GSSAPI_GSSAPI_GENERIC_H

/* Define if you have the <gssapi/gssapi.h> header file. */
#mesondefine HAVE_GSSAPI_GSSAPI_H

/* Define if you have the <gssapi/gssapi_krb5.h> header file. */
#mesondefine HAVE_GSSAPI_GSSAPI_KRB5_H

/* if you have GNU GSS */
#mesondefine HAVE_GSSGNU

/* if you have Heimdal */
#mesondefine HAVE_GSSHEIMDAL

/* if you have MIT Kerberos */
#mesondefine HAVE_GSSMIT

/* Define if you have the <idn2.h> header file. */
#mesondefine HAVE_IDN2_H

/* Define if you have the <ifaddrs.h> header file. */
#mesondefine HAVE_IFADDRS_H

/* Define if you have the `if_nametoindex' function. */
#mesondefine HAVE_IF_NAMETOINDEX

/* Define if you have a IPv6 capable working inet_ntop function. */
#mesondefine HAVE_INET_NTOP

/* Define if you have a IPv6 capable working inet_pton function. */
#mesondefine HAVE_INET_PTON

/* Define if you have the <inttypes.h> header file. */
#mesondefine HAVE_INTTYPES_H

/* Define if you have the ioctlsocket function. */
#mesondefine HAVE_IOCTLSOCKET

/* Define if you have the IoctlSocket camel case function. */
#mesondefine HAVE_IOCTLSOCKET_CAMEL

/* Define if you have a working IoctlSocket camel case FIONBIO function.
   */
#mesondefine HAVE_IOCTLSOCKET_CAMEL_FIONBIO

/* Define if you have a working ioctlsocket FIONBIO function. */
#mesondefine HAVE_IOCTLSOCKET_FIONBIO

/* Define if you have a working ioctl FIONBIO function. */
#mesondefine HAVE_IOCTL_FIONBIO

/* Define if you have a working ioctl SIOCGIFADDR function. */
#mesondefine HAVE_IOCTL_SIOCGIFADDR

/* Define if you have the <io.h> header file. */
#mesondefine HAVE_IO_H

/* Define if you have the lber.h header file. */
#mesondefine HAVE_LBER_H

/* Use LDAPS implementation */
#mesondefine HAVE_LDAP_SSL

/* Define if you have the ldap_ssl.h header file. */
#mesondefine HAVE_LDAP_SSL_H

/* Define if you have the `ldap_url_parse' function. */
#mesondefine HAVE_LDAP_URL_PARSE

/* Define if you have the <libgen.h> header file. */
#mesondefine HAVE_LIBGEN_H

/* Define if you have the `idn2' library (-lidn2). */
#mesondefine HAVE_LIBIDN2

/* Define if you have the <libssh2.h> header file. */
#mesondefine HAVE_LIBSSH2_H

/* Define if you have the <libssh/libssh.h> header file. */
#mesondefine HAVE_LIBSSH_LIBSSH_H

/* Define if you have the `wolfssh' library (-lwolfssh). */
#mesondefine HAVE_LIBWOLFSSH

/* if zlib is available */
#mesondefine HAVE_LIBZ

/* Define if you have the <linux/tcp.h> header file. */
#mesondefine HAVE_LINUX_TCP_H

/* Define if you have the <locale.h> header file. */
#mesondefine HAVE_LOCALE_H

/* Define if the compiler supports the 'long long' data type. */
#mesondefine HAVE_LONGLONG

/* Define if you have the `mach_absolute_time' function. */
#mesondefine HAVE_MACH_ABSOLUTE_TIME

/* Define if you have the memrchr function or macro. */
#mesondefine HAVE_MEMRCHR

/* Define if you have the MSG_NOSIGNAL flag. */
#mesondefine HAVE_MSG_NOSIGNAL

/* Define if you have the <netdb.h> header file. */
#mesondefine HAVE_NETDB_H

/* Define if you have the <netinet/in6.h> header file. */
#mesondefine HAVE_NETINET_IN6_H

/* Define if you have the <netinet/in.h> header file. */
#mesondefine HAVE_NETINET_IN_H

/* Define if you have the <netinet/tcp.h> header file. */
#mesondefine HAVE_NETINET_TCP_H

/* Define if you have the <net/if.h> header file. */
#mesondefine HAVE_NET_IF_H

/* Define if you have the <nghttp3/nghttp3.h> header file. */
#mesondefine HAVE_NGHTTP3_NGHTTP3_H

/* Define if you have the <ngtcp2/ngtcp2_crypto.h> header file. */
#mesondefine HAVE_NGTCP2_NGTCP2_CRYPTO_H

/* Define if you have the <ngtcp2/ngtcp2.h> header file. */
#mesondefine HAVE_NGTCP2_NGTCP2_H

/* if you have an old MIT Kerberos version, lacking GSS_C_NT_HOSTBASED_SERVICE
   */
#mesondefine HAVE_OLD_GSSMIT

/* Define if you have the `SSL_CTX_set_srp_password` and `SSL_CTX_set_srp_username' functions. */
#mesondefine HAVE_OPENSSL_SRP

/* Define if you have the `OpenSSL_version' function. */
#mesondefine HAVE_OPENSSL_VERSION

/* Define if you have the <pem.h> header file. */
#mesondefine HAVE_PEM_H

/* Define if you have the `pipe' function. */
#mesondefine HAVE_PIPE

/* if you have the PK11_CreateManagedGenericObject function */
#mesondefine HAVE_PK11_CREATEMANAGEDGENERICOBJECT

/* Define if you have a working poll function. */
#mesondefine HAVE_POLL

/* If you have a fine poll */
#mesondefine HAVE_POLL_FINE

/* Define if you have the <poll.h> header file. */
#mesondefine HAVE_POLL_H

/* Define if you have a working POSIX-style strerror_r function. */
#mesondefine HAVE_POSIX_STRERROR_R

/* Define if you have the <proto/bsdsocket.h> header file. */
#mesondefine HAVE_PROTO_BSDSOCKET_H

/* if you have <pthread.h> */
#mesondefine HAVE_PTHREAD_H

/* Define if you have the <pwd.h> header file. */
#mesondefine HAVE_PWD_H

/* Define if you have the `quiche_conn_set_qlog_fd' function. */
#mesondefine HAVE_QUICHE_CONN_SET_QLOG_FD

/* Define if you have the <quiche.h> header file. */
#mesondefine HAVE_QUICHE_H

/* Define if you have the `RAND_egd' function. */
#mesondefine HAVE_RAND_EGD

/* Define if you have the recv function. */
#mesondefine HAVE_RECV

/* Define if you have the <rsa.h> header file. */
#mesondefine HAVE_RSA_H

/* Define if you have the sa_family_t type. */
#mesondefine HAVE_SA_FAMILY_T

/* Define if you have the select function. */
#mesondefine HAVE_SELECT

/* Define if you have the send function. */
#mesondefine HAVE_SEND

/* Define if you have the <setjmp.h> header file. */
#mesondefine HAVE_SETJMP_H

/* Define if you have the `setlocale' function. */
#mesondefine HAVE_SETLOCALE

/* Define if you have the `setmode' function. */
#mesondefine HAVE_SETMODE

/* Define if you have the `setrlimit' function. */
#mesondefine HAVE_SETRLIMIT

/* Define if you have the setsockopt function. */
#mesondefine HAVE_SETSOCKOPT

/* Define if you have a working setsockopt SO_NONBLOCK function. */
#mesondefine HAVE_SETSOCKOPT_SO_NONBLOCK

/* Define if you have the sigaction function. */
#mesondefine HAVE_SIGACTION

/* Define if you have the siginterrupt function. */
#mesondefine HAVE_SIGINTERRUPT

/* Define if you have the signal function. */
#mesondefine HAVE_SIGNAL

/* Define if you have the <signal.h> header file. */
#mesondefine HAVE_SIGNAL_H

/* Define if you have the sigsetjmp function or macro. */
#mesondefine HAVE_SIGSETJMP

/* Define if struct sockaddr_in6 has the sin6_scope_id member */
#mesondefine HAVE_SOCKADDR_IN6_SIN6_SCOPE_ID

/* Define if you have the socket function. */
#mesondefine HAVE_SOCKET

/* Define if you have the socketpair function. */
#mesondefine HAVE_SOCKETPAIR

/* Define if you have the <stdatomic.h> header file. */
#mesondefine HAVE_STDATOMIC_H

/* Define if you have the <stdbool.h> header file. */
#mesondefine HAVE_STDBOOL_H

/* Define if you have the <stdint.h> header file. */
#mesondefine HAVE_STDINT_H

/* Define if you have the <stdio.h> header file. */
#mesondefine HAVE_STDIO_H

/* Define if you have the <stdlib.h> header file. */
#mesondefine HAVE_STDLIB_H

/* Define if you have the strcasecmp function. */
#mesondefine HAVE_STRCASECMP

/* Define if you have the strcmpi function. */
#mesondefine HAVE_STRCMPI

/* Define if you have the strdup function. */
#mesondefine HAVE_STRDUP

/* Define if you have the strerror_r function. */
#mesondefine HAVE_STRERROR_R

/* Define if you have the stricmp function. */
#mesondefine HAVE_STRICMP

/* Define if you have the <strings.h> header file. */
#mesondefine HAVE_STRINGS_H

/* Define if you have the <string.h> header file. */
#mesondefine HAVE_STRING_H

/* Define if you have the strncmpi function. */
#mesondefine HAVE_STRNCMPI

/* Define if you have the strnicmp function. */
#mesondefine HAVE_STRNICMP

/* Define if you have the <stropts.h> header file. */
#mesondefine HAVE_STROPTS_H

/* Define if you have the strstr function. */
#mesondefine HAVE_STRSTR

/* Define if you have the strtok_r function. */
#mesondefine HAVE_STRTOK_R

/* Define if you have the strtoll function. */
#mesondefine HAVE_STRTOLL

/* if struct sockaddr_storage is defined */
#mesondefine HAVE_STRUCT_SOCKADDR_STORAGE

/* Define if you have the timeval struct. */
#mesondefine HAVE_STRUCT_TIMEVAL

/* Define if suseconds_t is an available type. */
#mesondefine HAVE_SUSECONDS_T

/* Define if you have the <sys/filio.h> header file. */
#mesondefine HAVE_SYS_FILIO_H

/* Define if you have the <sys/ioctl.h> header file. */
#mesondefine HAVE_SYS_IOCTL_H

/* Define if you have the <sys/param.h> header file. */
#mesondefine HAVE_SYS_PARAM_H

/* Define if you have the <sys/poll.h> header file. */
#mesondefine HAVE_SYS_POLL_H

/* Define if you have the <sys/resource.h> header file. */
#mesondefine HAVE_SYS_RESOURCE_H

/* Define if you have the <sys/select.h> header file. */
#mesondefine HAVE_SYS_SELECT_H

/* Define if you have the <sys/socket.h> header file. */
#mesondefine HAVE_SYS_SOCKET_H

/* Define if you have the <sys/sockio.h> header file. */
#mesondefine HAVE_SYS_SOCKIO_H

/* Define if you have the <sys/stat.h> header file. */
#mesondefine HAVE_SYS_STAT_H

/* Define if you have the <sys/time.h> header file. */
#mesondefine HAVE_SYS_TIME_H

/* Define if you have the <sys/types.h> header file. */
#mesondefine HAVE_SYS_TYPES_H

/* Define if you have the <sys/uio.h> header file. */
#mesondefine HAVE_SYS_UIO_H

/* Define if you have the <sys/un.h> header file. */
#mesondefine HAVE_SYS_UN_H

/* Define if you have the <sys/utime.h> header file. */
#mesondefine HAVE_SYS_UTIME_H

/* Define if you have the <sys/wait.h> header file. */
#mesondefine HAVE_SYS_WAIT_H

/* Define if you have the <termios.h> header file. */
#mesondefine HAVE_TERMIOS_H

/* Define if you have the <termio.h> header file. */
#mesondefine HAVE_TERMIO_H

/* Define this if time_t is unsigned */
#mesondefine HAVE_TIME_T_UNSIGNED

/* Define if you have the <unistd.h> header file. */
#mesondefine HAVE_UNISTD_H

/* Define if you have the `utime' function. */
#mesondefine HAVE_UTIME

/* Define if you have the `utimes' function. */
#mesondefine HAVE_UTIMES

/* Define if you have the <utime.h> header file. */
#mesondefine HAVE_UTIME_H

/* Define if compiler supports C99 variadic macro style. */
#mesondefine HAVE_VARIADIC_MACROS_C99

/* Define if compiler supports old gcc variadic macro style. */
#mesondefine HAVE_VARIADIC_MACROS_GCC

/* Define if you have the windows.h header file. */
#mesondefine HAVE_WINDOWS_H

/* Define if you have the winsock2.h header file. */
#mesondefine HAVE_WINSOCK2_H

/* if you have wolfSSL_DES_ecb_encrypt */
#mesondefine HAVE_WOLFSSL_DES_ECB_ENCRYPT

/* Define if you have the `wolfSSL_get_peer_certificate' function. */
#mesondefine HAVE_WOLFSSL_GET_PEER_CERTIFICATE

/* Define if you have the `wolfSSL_UseALPN' function. */
#mesondefine HAVE_WOLFSSL_USEALPN

/* Define this symbol if your OS supports changing the contents of argv */
#mesondefine HAVE_WRITABLE_ARGV

/* Define if you have the ws2tcpip.h header file. */
#mesondefine HAVE_WS2TCPIP_H

/* if you have the zlib.h header file */
#mesondefine HAVE_ZLIB_H

/* if libzstd is in use */
#mesondefine HAVE_ZSTD

/* Define if you need the malloc.h header file even with stdlib.h */
#mesondefine NEED_MALLOC_H

/* Define if you need the memory.h header file even with stdlib.h */
#mesondefine NEED_MEMORY_H

/* Define if _REENTRANT preprocessor symbol must be defined. */
#mesondefine NEED_REENTRANT

// FIXME: AIX only.
/* Define if _THREAD_SAFE preprocessor symbol must be defined. */
#mesondefine NEED_THREAD_SAFE

/* Define to enable NTLM delegation to winbind's ntlm_auth helper. */
#mesondefine NTLM_WB_ENABLED

/* Define absolute filename for winbind's ntlm_auth helper. */
#mesondefine NTLM_WB_FILE

/* cpu-machine-OS */
#mesondefine OS

/* a suitable file to read random data from */
#mesondefine RANDOM_FILE

/* The number of bytes in type curl_off_t */
#mesondefine SIZEOF_CURL_OFF_T

/* The number of bytes in type int */
#mesondefine SIZEOF_INT

/* The number of bytes in type long */
#mesondefine SIZEOF_LONG

/* The number of bytes in type off_t */
#mesondefine SIZEOF_OFF_T

/* The number of bytes in type short */
#mesondefine SIZEOF_SHORT

/* The number of bytes in type size_t */
#mesondefine SIZEOF_SIZE_T

/* The number of bytes in type time_t */
#mesondefine SIZEOF_TIME_T

/* Define if all of the C90 standard headers exist (not just the ones
   required in a freestanding environment). This macro is provided for
   backward compatibility; new code need not use it. */
#mesondefine STDC_HEADERS

/* Define to the type of arg 3 for strerror_r. */
#mesondefine STRERROR_R_TYPE_ARG3

/* if AmiSSL is in use */
#mesondefine USE_AMISSL

/* Define to enable c-ares support */
#mesondefine USE_ARES

/* if BearSSL is enabled */
#mesondefine USE_BEARSSL

/* if ECH support is available */
#mesondefine USE_ECH

/* if GnuTLS is enabled */
#mesondefine USE_GNUTLS

/* GSASL support enabled */
#mesondefine USE_GSASL

/* if hyper is in use */
#mesondefine USE_HYPER

/* PSL support enabled */
#mesondefine USE_LIBPSL

/* if librtmp is in use */
#mesondefine USE_LIBRTMP

/* if libSSH is in use */
#mesondefine USE_LIBSSH

/* if libSSH2 is in use */
#mesondefine USE_LIBSSH2

/* If you want to build curl with the built-in manual */
#mesondefine USE_MANUAL

/* if mbedTLS is enabled */
#mesondefine USE_MBEDTLS

/* if MesaLink is enabled */
#mesondefine USE_MESALINK

/* if nghttp2 is in use */
#mesondefine USE_NGHTTP2

/* if nghttp3 is in use */
#mesondefine USE_NGHTTP3

/* if ngtcp2 is in use */
#mesondefine USE_NGTCP2

/* if ngtcp2_crypto_gnutls is in use */
#mesondefine USE_NGTCP2_CRYPTO_GNUTLS

/* if ngtcp2_crypto_openssl is in use */
#mesondefine USE_NGTCP2_CRYPTO_OPENSSL

/* if NSS is enabled */
#mesondefine USE_NSS

/* Use OpenLDAP-specific code */
#mesondefine USE_OPENLDAP

/* if OpenSSL is in use */
#mesondefine USE_OPENSSL

/* if quiche is in use */
#mesondefine USE_QUICHE

/* if rustls is enabled */
#mesondefine USE_RUSTLS

/* to enable Windows native SSL/TLS support */
#mesondefine USE_SCHANNEL

/* enable Secure Transport */
#mesondefine USE_SECTRANSP

/* if you want POSIX threaded DNS lookup */
#mesondefine USE_THREADS_POSIX

/* if you want Win32 threaded DNS lookup */
#mesondefine USE_THREADS_WIN32

/* Use TLS-SRP authentication */
#mesondefine USE_TLS_SRP

/* Use Unix domain sockets */
#mesondefine USE_UNIX_SOCKETS

/* Define if you are building a Windows target with crypto API support.
   */
#mesondefine USE_WIN32_CRYPTO

/* Define if you have the `normaliz' (WinIDN) library (-lnormaliz). */
#mesondefine USE_WIN32_IDN

/* Define if you are building a Windows target with large file support.
   */
#mesondefine USE_WIN32_LARGE_FILES

/* Use Windows LDAP implementation */
#mesondefine USE_WIN32_LDAP

/* Define if you are building a Windows target without large file
   support. */
#mesondefine USE_WIN32_SMALL_FILES

/* to enable SSPI support */
#mesondefine USE_WINDOWS_SSPI

/* if wolfSSH is in use */
#mesondefine USE_WOLFSSH

/* if wolfSSL is enabled */
#mesondefine USE_WOLFSSL

/* Define to provide own prototypes. */
#mesondefine WANT_IDN_PROTOTYPES

/* Define if OS is AIX. */
#ifndef _ALL_SOURCE
#  undef _ALL_SOURCE
#endif

/* Define for large files, on AIX-style hosts. */
#mesondefine _LARGE_FILES

/* Define to empty if `const' does not conform to ANSI C. */
#mesondefine const

/* Type to use in place of in_addr_t when system does not provide it. */
#mesondefine in_addr_t

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
#mesondefine inline
#endif

/* Define to `unsigned int' if <sys/types.h> does not define. */
#mesondefine size_t

/* the signed version of size_t */
#mesondefine ssize_t
