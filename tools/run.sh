#!/bin/bash

set -e

echo "Starting QEMU..."

qemu-system-x86_64 \
    -cdrom build/kernel.iso \
    -m 512M \
    -no-reboot \
    -no-shutdown
