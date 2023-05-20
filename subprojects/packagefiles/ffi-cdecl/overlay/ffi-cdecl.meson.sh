#!/bin/bash

set -eo pipefail

CC=(@CC@)
CXX=(@CXX@)
PREFIX=@PREFIX@
BINDIR=@BINDIR@
INCDIR=@INCDIR@
LIBDIR=@LIBDIR@
LUA_PATH=@LUA_PATH@

prog="${0##*/}"
prefix="$(realpath "${0%"${BINDIR}"/"${prog}"}")"
sysroot="${prefix%"${PREFIX}"}"

usage() {
    cat 1>&2 <<-EOF
usage: ${prog} [-c compiler] [-d dependency] [-o output.lua] [-D…|-I…|-U…]* input.c

    -c compiler    Select compiler: c or c++ (otherwise determined by the input extension)
    -d dependency  Add additional cflags from specified pkg-config dependency
    -o output      Set output file (instead of stdout)

    -D/-I/-U       Those flags are forwarded to the compiler
EOF
    exit 1
}

[[ $# -gt 0 ]] || usage

pkg-config() {
    env \
        PKG_CONFIG_PATH="${prefix}/${LIBDIR}/pkgconfig" \
        PKG_CONFIG_SYSROOT_DIR="${sysroot}" \
        pkg-config --env-only --cflags "$@"
}

compiler=''
output='/proc/self/fd/1'

read -ra cflags < <(pkg-config --cflags ffi-cdecl)

while getopts 'c:d:o:D:I:U:h' opt; do
    case "${opt}" in
        c)
            case "${OPTARG}" in
                c | c++)
                    compiler="${OPTARG}"
                    ;;
                *)
                    usage
                    ;;
            esac
            ;;
        d)
            read -ra a < <(pkg-config --cflags "${OPTARG}")
            cflags+=("${a[@]}")
            ;;
        o)
            output="${OPTARG}"
            ;;
        [DIU])
            cflags+=("-${opt}${OPTARG}")
            ;;
        [h?])
            usage
            ;;
    esac
done

shift $((OPTIND - 1))

# echo "OPTIND: ${OPTIND}"
# echo "$#: $@"
# echo "output: ${output}"
# echo "cflags: ${cflags[@]}"
# exit

[[ $# -eq 1 ]] || usage

if [[ -z "${compiler}" ]]; then
    case "$1" in
        *.C | *.cc | *.cpp | *.CPP | *.c++ | *.cp | *.cxx)
            compiler='c++'
            ;;
        *)
            compiler='c'
            ;;
    esac
fi

case "${compiler}" in
    c)
        compiler=("${CC[@]}")
        ;;
    c++)
        compiler=("${CXX[@]}")
        ;;
esac

exec env LUA_PATH="${prefix}/${LUA_PATH}/?.lua" \
    "${compiler[@]}" "${cflags[@]}" -I"${sysroot}/${INCDIR}" \
    -fplugin-arg-gcclua-output="${output}" -S -o /dev/null "$1"

# vim: sw=4
