#include"string.h"
#include"types.h"

String::String(){
    char* data = "";
    this->data = data;
    this->length = 0;
    this->capacity = 8;
}

String::String(char* str){
    this->data = str;
    this->length = String::setLenght(data);
    this->capacity = String::setCapacity();
}

String::String(char* str,uint64_t length){
    this->data = str;
    this->length = length;
    this->capacity = String::setCapacity();
}

String::String(char* str,uint64_t length,uint64_t capacity){
    this->data = str;
    this->length = length;
    this->capacity = capacity;
}

uint64_t String::getCapacity(){
    return this->capacity;
}

char* String::getData() const{
    return this->data;
}

//dinamic alcation

uint64_t String::setLenght(char* str){
    uint64_t size = 0;

    for (uint64_t i = 0; str[i] != '\0'; i++) {
        size ++;
    }
    return size;
}

//capacity is basead in 2**n beacause is basead "Architecture bit width"
uint64_t String::setCapacity(){
    uint64_t capacity = 0;
    uint64_t len = this->length + 1; // size + \0

    if(len >= 0 && len >= 7){
        capacity = 8;
    }else if (len >= 8 && len <= 15){
        capacity = 16;
    }else if (len >=16 && len <= 31){
        capacity = 32;
    }else if (len >= 32 && len <= 63){
        capacity = 64;
    }

    return capacity;
}
