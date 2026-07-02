#pragma once
#include "video/vga_driver.h"

class Kernel {
private:
    VGADriver videoService;

public:
    Kernel();

    void run();
};

extern "C" void kernel_main();
