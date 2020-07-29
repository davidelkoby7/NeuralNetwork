#pragma once

#include <iostream>

namespace Utils
{
    template <typename T>
    class DynamicArray
    {
        private:
            size_t array_length;
            T* array;
        public:
            ~DynamicArray();
            DynamicArray();
            DynamicArray(const int& initialLength);
            void Print();
            size_t GetLength() const;
            void AddItem(const T& newItem);
            // TODO: void AddItems(const T* newItemsArray);
            void RemoveItem(int index);
            T& GetItem(int index);
            void SetItem(const int& index, const T& newValue);
            T& operator [](int index) const;
            void ResetArray(T resetValue);
    };
}

#include "DynamicArray.cpp"

