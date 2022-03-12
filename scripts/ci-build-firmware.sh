#!/usr/bin/env bash

# Usage: [PLATFORM=mac|win] ci-build-firmware.sh

set -e

: "${TAG:="$(date "+%Y%m%d%H%M%S")"}"

[[ "${PLATFORM:=mac}" = win ]] && _K6_WINDOWS=yes

rm -rf qmk_firmware/keyboards/keychron/k6/keymaps/ansi-josh
cp -rp keyboards/keychron/k6/keymaps/ansi-josh qmk_firmware/keyboards/keychron/k6/keymaps

(cd qmk_firmware &&
  make -j4 keychron/k6/rgb/ansi:ansi-josh COLOR=false _K6_WINDOWS="${_K6_WINDOWS-no}" &&
  mv keychron_k6_rgb_ansi_ansi-josh.bin ../build/"keychron-k6-ansi-josh-$PLATFORM-$TAG.bin")
