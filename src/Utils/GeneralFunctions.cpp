#pragma once

#include <stdlib.h>
#include <chrono>

namespace GeneralFunctions
{
    size_t StringLength(const char* string)
    {
        size_t length = 0;
        while (string[length] != '\x00')
            length++;
        return length;
    }

    int RandomInt(const int& minValue, const int& maxValue)
    {
        // Getting current time in microsecends
        std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
        auto duration = now.time_since_epoch();
        auto micros = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();

        // Initializing random's seed
        srand(micros);

        // Getting a rand number in the given range
        int randNum = rand() % (maxValue - minValue);
        randNum += minValue;
        return randNum;
    }

    double RandomDouble(double minValue, double maxValue)
    {
       const int precision = 1000000;
       const int randInt = RandomInt(0, precision);
       const double randFactor = static_cast<double>(randInt) / static_cast<double>(precision);
       const double randDouble = minValue + randFactor * (maxValue - minValue);
       return randDouble;
    }
}
