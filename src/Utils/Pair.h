#pragma once

#include <iostream>

namespace Utils
{
    template <typename T, typename T2>
    class Pair
    {
        private:
            T m_firstItem;
            T2 m_secendItem;
        public:
            Pair() = delete;
            Pair(const T& firstItem, const T2& secendItem);

            void Print();
            void SetFirstItem(const T& firstItem);
            void SetSecendItem(const T2& secendItem);

            T& GetFirstItem();
            T2& GetSecendItem();
    };
}

#include "Pair.cpp"

