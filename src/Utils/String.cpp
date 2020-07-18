#include "String.h"

#include "GeneralFunctions.cpp"

using namespace Utils;

String::~String()
{
    delete[] this->m_string;
}

String::String()
{
    this->m_length = 0;
}

String::String(const char* newString)
{
    this->m_length = GeneralFunctions::StringLength(newString) + 1;
    this->m_string = new char[this->m_length];

    for (uint i = 0; i < this->m_length - 1; i++)
        this->m_string[i] = newString[i];

    m_string[this->m_length - 1] = '\x00';
}

void String::Print() const
{
    std::cout << this->m_string << std::endl;
}

void String::SetString(char* newString)
{
    uint newLength = GeneralFunctions::StringLength(newString);
    char* new_char_array = new char[newLength];
    for (uint i = 0; i < newLength; i++)
        new_char_array[i] = newString[i];

    delete this->m_string;
    this->m_string = nullptr;
    this->m_string = new_char_array;
    this->m_length = newLength;
}

char* String::GetString() const
{
    return this->m_string;
}

size_t String::GetLength() const
{
    return this->m_length;
}

const char String::operator [](const int& index) const
{
    return this->m_string[index];
}

String String::operator +(const String& otherString)
{
    size_t newLength = this->m_length + otherString.m_length - 1;
    char* newString = new char[newLength];

    for (uint i = 0; i < this->m_length - 1; i++)
        newString[i] = this->m_string[i];

    for (uint i = 0; i < otherString.m_length - 1; i++)
        newString[i + this->m_length - 1] = otherString[i];

    return newString;
}

// Overloading the << operator so String will be accepted by std::cout
std::ostream &operator<<(std::ostream &os, String const  &string) {
    return os << string.GetString();
}

