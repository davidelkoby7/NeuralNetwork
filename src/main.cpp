#include <iostream>

#include "Utils/GeneralFunctions.cpp"
#include "NeuralNetwork/NeuralNetwork.h"
#include "Utils/ActivationFunctions.h"
#include "Datasets/MNIST/MNISTParser.h"

#define log(x) std::cout << x << std::endl;

int main()
{
    /*
    Utils::DynamicArray<int> numOfNeuronsPerLayer;
    numOfNeuronsPerLayer.AddItem(3);
    numOfNeuronsPerLayer.AddItem(2);
    numOfNeuronsPerLayer.AddItem(2);
    NeuralNetwork nn(3, numOfNeuronsPerLayer, ActivationFunctions::Sigmoid, ActivationFunctions::SigmoidDerivative);
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
    }
    nn.Print();
    nn.SaveToFile("./myFirstNeuralNetwork.nn");
    NeuralNetwork nn("./tmp/myFirstNeuralNetwork.nn", ActivationFunctions::Sigmoid, ActivationFunctions::SigmoidDerivative);
    nn.Print();
    */
    // Getting the inputs and outputs of the MNIST Dataset
    Utils::DynamicArray<Utils::DynamicArray<double>>* trainInputs = MNISTParser::GetTrainInputs();
    Utils::DynamicArray<Utils::DynamicArray<double>>* trainOutputs = MNISTParser::GetTrainOutputs();

    /*
    // Creating a nn for that data set (input - 784 neurons, output - 10 neurons, 2 hidden layers of 200 neurons)
    Utils::DynamicArray<int> numOfNeuronsPerLayer;
    numOfNeuronsPerLayer.AddItem(784);
    numOfNeuronsPerLayer.AddItem(200);
    numOfNeuronsPerLayer.AddItem(200);
    numOfNeuronsPerLayer.AddItem(10);
    NeuralNetwork* nn = new NeuralNetwork(4, numOfNeuronsPerLayer, ActivationFunctions::Sigmoid, ActivationFunctions::SigmoidDerivative);
    nn->SaveToFile("./untrainedMNIST.nn");
    nn->BackPropagate(*trainInputs, *trainOutputs);
    nn->SaveToFile("./trainedMNIST.nn");
    std::cout << trainInputs->GetLength() << "\n";
    std::cout << trainOutputs->GetLength() << "\n";
    */

    NeuralNetwork* nn = new NeuralNetwork("/home/davidalk/Documents/neuralNetwork/trainedMNIST.nn", ActivationFunctions::Sigmoid, ActivationFunctions::SigmoidDerivative);
    for (size_t currIn = 0; currIn < 10; currIn++)
    {
        nn->SetInputLayer(trainInputs->GetItem(currIn));
        nn->PropagateForward();
        Utils::DynamicArray<Neuron*>* outputLayer = nn->GetOutputLayer();
        for (size_t i = 0; i < outputLayer->GetLength(); i++)
        {
            std::cout << "i: " << i << std::endl;
            std::cout << "Value: " << outputLayer->GetItem(i)->GetValue() << "\n";
        }
        trainOutputs->GetItem(currIn).Print();
    } 
}

