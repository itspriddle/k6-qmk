# Keychron K6 QMK

This repo is for me to compile [QMK][] firmware for my [Keychron K6][]
keyboard. Actually it uses the [Sonix QMK][] fork to work on the K6's
SN32F248B chip.

It uses GitHub actions to build and upload compiled `.bin` files suitable for
flashing with [Sonix Flasher][].

## K6 Keymap

My K6 keymap is at [`keymaps/keymap.c`](./keymaps/keymap.c). It is a copy of
the [`keychron/k6:ansi`][Sonix QMK K6 Keymap] targeting macOS.

See the [releases](https://github.com/itspriddle/k6-qmk/releases)

## GitHub Workflow

Make changes to `keymap.c` and then commit/push them to GitHub. If a build
passes, the compiled firmware will be uploaded as a build artifact. It can be
downloaded from the view build page on GitHub. These uploads will be deleted
eventually, so do not rely on being able to download them forever.

When the firmware reaches a good saving point, uploading a git tag will
trigger a build and upload the compiled firmware as a release asset. These
files stay on GitHub for the life of the project.

To see how to do this locally on macOS or Linux, see
[`.github/workflows/build.yml`](./.github/workflows/build.yml).

Huge thanks to [QMK-on-K6][] for outlining this process!

[QMK]: https://qmk.fm
[Sonix QMK]: https://github.com/SonixQMK/qmk_firmware
[Sonix QMK K6 Keymap]: https://github.com/SonixQMK/qmk_firmware/tree/697eca0c/keyboards/keychron/k6/keymaps/ansi
[Sonix Flasher]: https://github.com/SonixQMK/sonix-flasher/releases/tag/v0.2.1
[QMK-on-K6]: https://github.com/CanUnesi/QMK-on-K6/blob/main/README.md
[Keychron K6]: https://www.keychron.com/products/keychron-k6-wireless-mechanical-keyboard
