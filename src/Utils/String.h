#pragma once

#include <iostream>

namespace Utils
{
    class String
    {
        private:
            size_t m_length;
            char* m_string;
        public:
            // Constructos / Destructor
            ~String();
            String();
            String(const char* newString);

            // Setter
            void SetString(char* new_string);

            // Getters
            char* GetString() const;
            size_t GetLength() const;
            
            // Additional functionallities
            void Print() const;
            /* TODO:
             * Split
             */

            // Operators overloaded
            const char operator[](const int& index) const;
            String operator+(const String& otherString);
    };
}

