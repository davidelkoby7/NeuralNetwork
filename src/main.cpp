#include <iostream>

#include "Utils/GeneralFunctions.cpp"
#include "NeuralNetwork/NeuralNetwork.h"
#include "Utils/ActivationFunctions.h"
#include "Datasets/MNIST/MNISTParser.h"

#define log(x) std::cout << x << std::endl;

int main()
{
    // Getting the inputs and outputs of the MNIST Dataset
    Utils::DynamicArray<Utils::DynamicArray<double>>* trainInputs = MNISTParser::GetTrainInputs();
    Utils::DynamicArray<Utils::DynamicArray<double>>* trainOutputs = MNISTParser::GetTrainOutputs();

    /*
    // Creating a nn for that data set (input - 784 neurons, output - 10 neurons, 2 hidden layers of 200 neurons)
    Utils::DynamicArray<int> numOfNeuronsPerLayer;
    numOfNeuronsPerLayer.AddItem(784);
    numOfNeuronsPerLayer.AddItem(200);
    numOfNeuronsPerLayer.AddItem(10);
    NeuralNetwork* nn = new NeuralNetwork(numOfNeuronsPerLayer, ActivationFunctions::Sigmoid, ActivationFunctions::SigmoidDerivative);
    nn->SaveToFile("./untrainedMNIST.nn");
    nn->BackPropagate(*trainInputs, *trainOutputs);
    nn->SaveToFile("./trainedMNIST.nn");
    std::cout << trainInputs->GetLength() << "\n";
    std::cout << trainOutputs->GetLength() << "\n";
    */

    NeuralNetwork* nn = new NeuralNetwork("/home/davidalk/Documents/neuralNetwork/trainedMNIST.nn", ActivationFunctions::Sigmoid, ActivationFunctions::SigmoidDerivative);
    int mismatchCount = 0;
    for (size_t currIn = 0; currIn < trainInputs->GetLength(); currIn++)
    {
        if (currIn % 100 == 0)
        {
            std::cout << "currIn: " << currIn << "\nCurrent mismatchCount: " << mismatchCount << "\n";
        }
        nn->SetInputLayer(trainInputs->GetItem(currIn));
        nn->PropagateForward();
        int mostActiveIndex = nn->GetMostActiveNeuronIndex();
        int desiredIndexOutput;
        for (size_t item = 0; item < trainOutputs->GetItem(currIn).GetLength(); item++)
        {
            if (trainOutputs->GetItem(currIn).GetItem(item) == 1)
                desiredIndexOutput = item;
        }
        if (desiredIndexOutput != mostActiveIndex)
            mismatchCount++;
    } 
    std::cout << "mismatchCount: " << mismatchCount << "\n";
}

