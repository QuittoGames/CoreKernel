#include "video/vga_driver.h"
#include "video/vga_config.h"
#include "video/colors.h"
#include "../../lib/coreTypes/string.h"

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

void VGADriver::print(String& str) {
    uint8_t color = (BLACK << 4) | LIGHT_GRAY;
    const char* data = str.getData();

    for (const char* p = data; *p; p++) {
        if (*p == '\n') {
            uint32_t bytes_per_line = VGAConfig::width * 2;
            cursor = ((cursor / bytes_per_line) + 1) * bytes_per_line;
        } else {
            buffer[cursor] = *p;
            buffer[cursor + 1] = color;
            cursor += 2;
        }

        if (cursor >= VGAConfig::width * VGAConfig::height * 2) {
            cursor = 0;
        }
    }

}

void VGADriver::print(String str) {
    uint8_t color = (BLACK << 4) | LIGHT_GRAY;
    const char* data = str.getData();

    for (const char* p = data; *p; p++) {
        if (*p == '\n') {
            uint32_t bytes_per_line = VGAConfig::width * 2;
            cursor = ((cursor / bytes_per_line) + 1) * bytes_per_line;
        } else {
            buffer[cursor] = *p;
            buffer[cursor + 1] = color;
            cursor += 2;
        }

        if (cursor >= VGAConfig::width * VGAConfig::height * 2) {
            cursor = 0;
        }
    }

}

void VGADriver::print(const char* str) {
    uint8_t color = (BLACK << 4) | LIGHT_GRAY;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            uint32_t bytes_per_line = VGAConfig::width * 2;
            cursor = ((cursor / bytes_per_line) + 1) * bytes_per_line;
        } else {
            buffer[cursor] = str[i];
            buffer[cursor + 1] = color;
            cursor += 2;
        }

        if (cursor >= VGAConfig::width * VGAConfig::height * 2) {
            cursor = 0;
        }
    }
}
