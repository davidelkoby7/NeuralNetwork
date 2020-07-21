#include <iostream>

#include "Utils/GeneralFunctions.cpp"
#include "Utils/StaticArray.h"

#define log(x) std::cout << x << std::endl;

int main()
{
    Utils::StaticArray<int, 4> sa;
    sa.Print();
    sa.Fill(23);
    sa.Print();
}

