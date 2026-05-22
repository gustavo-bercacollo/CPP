#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data* original = new Data();
    original->id = 42;
    original->name = "hello";

    std::cout << "Original pointer:    " << original << std::endl;

    uintptr_t number = Serializer::serialize(original);
    std::cout << "Serialized number:   " << number << std::endl;

    Data* recovered = Serializer::deserialize(number);
    std::cout << "Recovered pointer:   " << recovered << std::endl;

    std::cout << "Are they equal? " << (original == recovered ? "YES" : "NO") << std::endl;

    delete original;
    return 0;
}