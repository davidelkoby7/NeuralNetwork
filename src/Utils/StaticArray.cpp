#include "StaticArray.h"

using namespace Utils;

template <typename T, size_t length>
StaticArray<T, length>::StaticArray()
{
    this->array_length = length;
    std::cout << "DavidlkCreated!\n";
}

template <typename T, size_t length>
size_t StaticArray<T, length>::GetLength()
{
    return length;
}

template <typename T, size_t length>
void StaticArray<T, length>::ResetArray(T resetValue)
{
    for (size_t i = 0; i < length; i++)
        this->array[i] = resetValue;
}

template <typename T, size_t length>
void StaticArray<T, length>::Print()
{
    std::cout << "[";
    for (size_t i = 0; i < length; i++)
    {
        std::cout << this->array[i];
        if (i != length - 1)
            std::cout << ", ";
    }
    std::cout << "]\n";
}

template <typename T, size_t length>
T& StaticArray<T, length>::operator[](int index)
{
    if (index >= length)
        throw "Invalid Index!";
    
    return this->array[index];
}

