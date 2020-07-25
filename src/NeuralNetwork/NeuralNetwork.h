#pragma once

#include "../Utils/StaticArray.h"
#include "../Utils/DynamicArray.h"
#include "../Utils/ActivationFunctions.h"

#include "Neuron.h"

template <int numOfLayers>
class NeuralNetwork
{
    private:
        Utils::StaticArray<Utils::DynamicArray<Neuron*>* ,numOfLayers> layers;

        // Weight is order as follows: weights[layer][src_neuron][dst_neuron]
        Utils::DynamicArray<Utils::DynamicArray<Utils::DynamicArray<double>*>*> weights;
        double (*activationFunction)(const double& x);
        double (*activationFunctionDerivative)(const double& x);
        double learningRate;
    public:

        // Destructor and Constructors
        ~NeuralNetwork();
        NeuralNetwork() = delete;
        NeuralNetwork(const Utils::DynamicArray<int>& numOfNeuronsForLayers, double (*newActivationFunction)(const double& x) = ActivationFunctions::ReLU, double (*newActivationFunctionDerivative)(const double& x) = ActivationFunctions::ReLUDerivative, const double& newLeariningRate = 0.1);
        // TODO: Constructor with file input
        
        // Getters
        Utils::StaticArray<Utils::DynamicArray<Neuron*> ,numOfLayers>& GetLayers() const;
        Utils::DynamicArray<Utils::DynamicArray<Utils::DynamicArray<double>>>& GetWeights() const;
        Utils::DynamicArray<Neuron*>& GetInputLayer() const;
        Utils::DynamicArray<Neuron*>& GetOutputLayer() const;
        double GetWeight(const int& layer_num, const int& src_neuron_number, const int& dst_neuron_number);
        double GetLearningRate();
        
        // Setters
        void SetInputLayer(const Utils::DynamicArray<double>& inputs);
        void SetLearningRate(const double& newLeariningRate);

        // General Functionallity
        void Print();
        double ActivationFunction(const double& x);
        double ActivationFunctionDerivative(const double& x);
        // TODO: Add a save network to file function

        // Network Functionallity
        void PropagateForward();
        void BackPropagate(const Utils::DynamicArray<Utils::DynamicArray<double>>& inputs, const Utils::DynamicArray<Utils::DynamicArray<double>>& expectedOutputs);
};

#include "NeuralNetwork.cpp"

