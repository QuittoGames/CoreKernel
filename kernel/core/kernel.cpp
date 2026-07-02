#include "kernel.h"
#include "video/vga_driver.h"

Kernel::Kernel() {
}

void Kernel::run() {
    videoService.clear();
    videoService.print("Kernel RUN");
}

extern "C" void kernel_main() {
    Kernel kernel;
    kernel.run();
}
