#include "StaticArray.h"

template <typename T, size_t length>
Utils::StaticArray<T, length>::~StaticArray()
{
    // No need to delete[] the mem of the array because it was allocated on the stack
}

template <typename T, size_t length>
Utils::StaticArray<T, length>::StaticArray()
{
    this->array_length = length;
}

template <typename T, size_t length>
size_t Utils::StaticArray<T, length>::GetLength()
{
    return length;
}

template <typename T, size_t length>
void Utils::StaticArray<T, length>::Fill(T resetValue)
{
    for (size_t i = 0; i < length; i++)
        this->array[i] = resetValue;
}

template <typename T, size_t length>
void Utils::StaticArray<T, length>::Print()
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
T& Utils::StaticArray<T, length>::operator[](int index)
{
    if (index >= length)
        throw "Invalid Index!";
    
    return this->array[index];
}

