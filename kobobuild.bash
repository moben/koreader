#!/usr/bin/env bash

#
# podman run --volume=${PWD%/*}/:${PWD%/*}/:rw --rm -ti --uidmap '+1000:0:1' koreader/kokobo:0.3.0 /usr/bin/bash "${PWD}/kobobuild.bash"
#

set -uex

source ~/.bashrc

sudo apt update -y
sudo apt install -y chrpath python3.9{,-venv} # gcc-10-multilib 

python3.9 -m venv --clear --symlinks /tmp/venv
source /tmp/venv/bin/activate

python3.9 -m pip install meson

cd "${0%/*}"

# sudo rm -f meson/ccache.ini
# sudo git config --global --add safe.directory "${PWD}"

# env

# envvars=(
#   HOME
#   PATH
#   LUA_PATH
#   LUA_CPATH
# )

# envset=()
# for v in "${envvars[@]}"; do
#   envset+=( "${v}=${!v}" )
# done

# sudo env "${envset[@]}"

ANDROID_ARCH=arm64 ./kodev "${@}" |& cat # release kobo
