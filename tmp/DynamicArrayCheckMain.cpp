#include <iostream>

#include "Utils/GeneralFunctions.cpp"
#include "Utils/DynamicArray.h"

#define log(x) std::cout << x << std::endl;

int main()
{
    Utils::DynamicArray<double> da;
    da.Print();
    da.AddItem(1);
    da.AddItem(2);
    da.AddItem(-1.23);
    da.Print();
}

