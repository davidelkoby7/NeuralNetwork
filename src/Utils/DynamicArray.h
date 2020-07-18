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
            DynamicArray();
            void Print();
            size_t GetLength();
            void AddItem(const T& newItem);
            void RemoveItem(int index);
            T& operator [](int index);
            void ResetArray(T resetValue);
    };
}

