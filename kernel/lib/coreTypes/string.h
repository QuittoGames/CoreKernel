# pragma once

#include <types.h>

class String
{
private:
    uint64_t length;
    uint64_t capacity;
    char* data;

public:
    String();
    String(char* str);
    String(char* str,uint64_t length);
    String(char* str,uint64_t length , uint64_t capacity);

    void append(String str);
    void append(char* str);

    bool isEmpty();

    uint64_t getCapacity();

    uint64_t getLength() const;
    char* getData() const;

    //dinamic allocation
    uint64_t setCapacity();
    uint64_t setLenght(char* data);
};
