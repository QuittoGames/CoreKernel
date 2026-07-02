# CoreKernel

A 32-bit freestanding experimental kernel built for learning, control, and deep systems understanding.

---

## Overview

CoreKernel is a freestanding 32-bit kernel built from scratch for studying operating systems internals: boot process, memory layout, drivers, and hardware interaction.

It runs without libc, without OS support, and without runtime dependencies.

---

## Features

- Multiboot v1 (GRUB2)
- NASM bootloader
- C / C++ freestanding kernel
- VGA text driver (0xB8000)
- ELF32 linking
- QEMU execution
- Custom linker script
- Build automation (bash)

---

## Architecture

BIOS -> GRUB -> boot.asm -> kernel_main -> VGA driver -> idle loop (hlt)

---

## Project Structure

boot/
  boot.asm
  grub/grub.cfg

kernel/
  arch/
  core/
  drivers/
  include/
  lib/
  memory/

linker/
  linker.ld

tools/
  build.sh
  run.sh

---

## VGA Driver

Direct memory mapped VGA text mode.

- Memory: 0xB8000
- Format: [char][color]
- Supports clear and print

---

## Build

./tools/build.sh

What it does:
- Compiles ASM (NASM)
- Compiles C++ (-m32 -ffreestanding)
- Links ELF kernel
- Builds ISO via GRUB
- Prepares QEMU image

---

## Run

./tools/run.sh

Launches kernel inside QEMU emulator.

---

## Dependencies

- gcc multilib
- nasm
- binutils
- grub2
- xorriso
- qemu

---

## Philosophy

This project is focused on understanding OS internals by building everything manually. No abstractions, no shortcuts.

---

** "Tudo o que fizerem, façam de todo o coração, como para o Senhor, e não para os homens, sabendo que receberão do Senhor a recompensa da herança. É a Cristo, o Senhor, que vocês estão servindo." **

**Colossenses 3:23–24**

---

## License

MIT
