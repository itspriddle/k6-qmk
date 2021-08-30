# Keychron K6 QMK

This repo is for me to compile QMK firmware for my Keychron K6 keyboard. It
uses GitHub actions to build and upload compiled .bin files suitable for
flashing with Sonix Flasher.

## Updates

Update `keymaps/keymap.c` and commit. Tag a new version with `git tag v$(date
"+%Y%m%d%H%M%S")-josh` and `git push --tags`. Download the latest release at
<https://github.com/itspriddle/k6-qmk/releases>
