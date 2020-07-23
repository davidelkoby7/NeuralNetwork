#include <iostream>

#include "Utils/GeneralFunctions.cpp"
#include "NeuralNetwork/Neuron.h"

#define log(x) std::cout << x << std::endl;

int main()
{
    Neuron n1;
    Neuron n2;
    Neuron n3;
    Neuron n4;

    DynamicArray<Neuron*> hiddenLayer;
    hiddenLayer.AddItem(&n1);
    hiddenLayer.AddItem(&n2);
    hiddenLayer.AddItem(&n3);
    hiddenLayer.AddItem(&n4);

    Neuron inputNeuron(0, 0, hiddenLayer);
    std::cout << inputNeuron << std::endl;
}

