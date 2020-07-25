#include "DynamicArray.h"

template<typename T>
Utils::DynamicArray<T>::~DynamicArray()
{
    if (this->array_length > 0)
        delete[] this->array;
}

template<typename T>
Utils::DynamicArray<T>::DynamicArray()
{
    this->array_length = 0;
}

template<typename T>
void Utils::DynamicArray<T>::Print()
{
    for (size_t i = 0; i < this->array_length; i++)
        std::cout << this->array[i] << std::endl;
}

template<typename T>
size_t Utils::DynamicArray<T>::GetLength() const
{
    return this->array_length;
}

template<typename T>
void Utils::DynamicArray<T>::AddItem(const T& newItem)
{
    T* new_array = new T[this->array_length + 1];

    for (size_t i = 0; i < this->array_length; i++)
        new_array[i] = this->array[i];

    new_array[array_length] = newItem;

    // Releasing the memory of array
    if (this->array_length != 0)
    {
        delete this->array;
        this->array = nullptr;
    }

    this->array_length += 1;
    this->array = new_array;
}

template<typename T>
void Utils::DynamicArray<T>::RemoveItem(int index)
{
    T* new_array = new T[this->array_length - 1];

    int temp_index = 0;
    for (size_t i = 0; i < this->array_length; i++)
    {
        if (i != index)
        {
            new_array[temp_index] = this->array[i];
            temp_index++;
        }
    }

    // Releasing the memory of array
    delete this->array;
    this->array = nullptr;

    this->array_length -= 1;
    this->array = new_array;
}

template <typename T>
T& Utils::DynamicArray<T>::GetItem(int index)
{
    return this->array[index];
}

template<typename T>
T& Utils::DynamicArray<T>::operator[](int index) const
{
    return this->array[index];
}

template <typename T>
void Utils::DynamicArray<T>::ResetArray(T resetValue)
{
    for (int i = 0; i < this->array_length; i++)
        this->array[i] = resetValue;
}

