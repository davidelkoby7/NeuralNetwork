#pragma once

#include <iostream>

namespace Utils
{
    template <typename T, size_t length>
    class StaticArray
    {
        private:
            int array_length;
            T array[length];
        public:
            StaticArray();
            size_t GetLength();
            void ResetArray(T resetValue);
            void Print();

            T& operator [](int index);
            StaticArray& operator +(const StaticArray& another_array);
    };
}

