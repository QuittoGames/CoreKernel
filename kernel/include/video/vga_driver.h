#pragma once
#include <cstdint>

class VGADriver {
private:
    volatile uint8_t* buffer;
    uint32_t cursor;

public:
    VGADriver();
    ~VGADriver();

    void clear();
    void print(const char* str);
};
