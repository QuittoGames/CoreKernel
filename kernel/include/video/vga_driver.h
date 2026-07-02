#pragma once
#include <cstdint>
#include "../../lib/coreTypes/string.h"

class VGADriver {
private:
    volatile uint8_t* buffer;
    uint32_t cursor;

public:
    VGADriver();
    ~VGADriver();

    void clear();
    void print(String& str);
    void print(String str);
    void print(const char* str);
};
