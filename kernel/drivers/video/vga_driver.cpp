#include "video/vga_driver.h"
#include "video/vga_config.h"
#include "video/colors.h"

VGADriver::VGADriver() {
    buffer = (uint8_t*)VGAConfig::memory;
    cursor = 0;
}

VGADriver::~VGADriver() {}

void VGADriver::clear() {
    uint8_t color = (BLACK << 4) | LIGHT_GRAY;

    for (uint32_t i = 0; i < VGAConfig::width * VGAConfig::height * 2; i += 2) {
        buffer[i] = ' ';
        buffer[i + 1] = color;
    }

    cursor = 0;
}

void VGADriver::print(const char* str) {
    uint8_t color = (BLACK << 4) | LIGHT_GRAY;

    for (int i = 0; str[i] != '\0'; i++) {
        buffer[cursor] = str[i];
        buffer[cursor + 1] = color;
        cursor += 2;
    }
}
