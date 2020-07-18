#include <iostream>

#include "Utils/GeneralFunctions.cpp"

#define log(x) std::cout << x << std::endl;

int main()
{
    for (int i = 0; i < 1000; i++)
        log(GeneralFunctions::RandomDouble(-1, 1));
}

