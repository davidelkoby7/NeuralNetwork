#pragma once

#include "../Utils/StaticArray.cpp"
#include "../Utils/DynamicArray.cpp"

#include "Neuron.cpp"

using namespace Utils;

template <int numOfLayers>
class NeuralNetwork
{
    private:
        StaticArray<DynamicArray<*Neuron> ,numOfLayers> layers;
        DynamicArray<DynamicArray<DynamicArray<double>>> weights;
    public:
        // Destructor and Constructors
        ~NeuralNetwork();
        NeuralNetwork(const DynamicArray<int>& numOfNeuronsForLayers);
        // TODO: Constructor with file input
        
        // Getters
        StaticArray<DynamicArray<*Neuron> ,numOfLayers>& GetLayers() const;
        DynamicArray<DynamicArray<double>>& GetWeights() const;
        DynamicArray<*Neuron>& GetInputLayer() const;
        DynamicArray<*Neuron>& GetOutputLayer() const;
        
        // Setters
        void SetInputLayer(const DynamicArray<double>& inputs);

        // Network Functionallity
        void PropagateForward();
};

