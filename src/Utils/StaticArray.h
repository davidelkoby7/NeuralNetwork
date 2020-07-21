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
            ~StaticArray();
            StaticArray();
            size_t GetLength();
            void Fill(T resetValue);
            void Print();

            T& operator [](int index);
            StaticArray& operator +(const StaticArray& another_array);
    };
}

#include "StaticArray.cpp"

