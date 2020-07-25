#include <iostream>

#include "Utils/GeneralFunctions.cpp"
#include "NeuralNetwork/NeuralNetwork.h"
#include "Utils/ActivationFunctions.h"

#define log(x) std::cout << x << std::endl;

int main()
{
    Utils::DynamicArray<int> numOfNeuronsPerLayer;
    numOfNeuronsPerLayer.AddItem(3);
    numOfNeuronsPerLayer.AddItem(2);
    numOfNeuronsPerLayer.AddItem(2);
    NeuralNetwork<3> nn(numOfNeuronsPerLayer, ActivationFunctions::Sigmoid, ActivationFunctions::SigmoidDerivative);
    Utils::DynamicArray<Utils::DynamicArray<double>> inputs;
    Utils::DynamicArray<double> singleInput;
    singleInput.AddItem(-0.8);
    singleInput.AddItem(0.2);
    singleInput.AddItem(0.4);
    inputs.AddItem(singleInput);
    Utils::DynamicArray<Utils::DynamicArray<double>> outputs;
    Utils::DynamicArray<double> singleOutput;
    singleOutput.AddItem(0);
    singleOutput.AddItem(1);
    outputs.AddItem(singleOutput);
    nn.Print();
    for (int i = 0; i < 200; i++)
    {
        nn.BackPropagate(inputs, outputs);
        log(" ~~~~~~~~~~~~~~~~~~~~~~~~~ ");
        nn.Print();
    }
}

