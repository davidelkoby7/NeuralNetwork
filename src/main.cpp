#include <iostream>

#include "Utils/GeneralFunctions.cpp"
#include "NeuralNetwork/NeuralNetwork.h"

#define log(x) std::cout << x << std::endl;

int main()
{
    Utils::DynamicArray<int> numOfNeuronsPerLayer;
    numOfNeuronsPerLayer.AddItem(3);
    numOfNeuronsPerLayer.AddItem(2);
    numOfNeuronsPerLayer.AddItem(1);
    NeuralNetwork<3> nn(numOfNeuronsPerLayer);
    nn.Print();
    nn.PropagateForward();
    log(" ~~~~~~~~~~~~~~~~~~~~~~~~~ ");
    nn.Print();
}

