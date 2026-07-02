#!/bin/bash

set -e
cd "$(dirname "$0")/.."

echo "Verificando toolchain 32-bit..."

if ! echo "int main(){return 0;}" | gcc -m32 -x c - -o /dev/null 2>/dev/null; then
    echo "ERRO: toolchain 32-bit quebrada"
    exit 1
fi

echo "OK: toolchain 32-bit funcional"

BUILD_DIR="build"
OBJ_DIR="$BUILD_DIR/obj"
ISO_DIR="boot"

mkdir -p "$OBJ_DIR"
mkdir -p "$ISO_DIR/grub"

CXXFLAGS="-m32 -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -Ikernel/include"

echo "Compilando bootloader (ASM)..."
nasm -f elf32 boot/boot.asm -o $OBJ_DIR/boot.o

echo "Compilando kernel..."
g++ $CXXFLAGS -c kernel/core/kernel.cpp -o $OBJ_DIR/kernel.o
g++ $CXXFLAGS -c kernel/drivers/video/vga_driver.cpp -o $OBJ_DIR/vga.o

echo "Linkando kernel..."
ld -m elf_i386 -nostdlib -T linker/linker.ld \
-o $BUILD_DIR/kernel.bin \
$OBJ_DIR/boot.o \
$OBJ_DIR/kernel.o \
$OBJ_DIR/vga.o

echo "Preparando ISO..."
cp $BUILD_DIR/kernel.bin $ISO_DIR/kernel.bin

cat > $ISO_DIR/grub/grub.cfg << EOF
set timeout=0
set default=0

menuentry "ProtonQ Kernel" {
    multiboot /boot/kernel.bin
    boot
}
EOF

echo "Construindo ISO..."
echo "Preparando ISO..."

rm -rf iso_root
mkdir -p iso_root/boot/grub

cp build/kernel.bin iso_root/boot/kernel.bin
cp boot/grub/grub.cfg iso_root/boot/grub/grub.cfg

echo "Construindo ISO..."
grub2-mkrescue -o build/kernel.iso iso_root

echo "Build finalizada: $BUILD_DIR/kernel.iso"
