#pragma once
#include <cstdint>

struct VGAConfig {
    static constexpr uint16_t width = 80;
    static constexpr uint16_t height = 25;
    static constexpr uintptr_t memory = 0xB8000;
};
