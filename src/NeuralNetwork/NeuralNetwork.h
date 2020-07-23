#pragma once

#include "../Utils/StaticArray.h"
#include "../Utils/DynamicArray.h"

#include "Neuron.h"

template <int numOfLayers>
class NeuralNetwork
{
    private:
        Utils::StaticArray<Utils::DynamicArray<Neuron*>* ,numOfLayers> layers;

        // Weight is order as follows: weights[layer][src_neuron][dst_neuron]
        Utils::DynamicArray<Utils::DynamicArray<Utils::DynamicArray<double>*>*> weights;
    public:

        // Destructor and Constructors
        ~NeuralNetwork();
        NeuralNetwork() = delete;
        NeuralNetwork(const Utils::DynamicArray<int>& numOfNeuronsForLayers);
        // TODO: Constructor with file input
        
        // Getters
        Utils::StaticArray<Utils::DynamicArray<Neuron*> ,numOfLayers>& GetLayers() const;
        Utils::DynamicArray<Utils::DynamicArray<Utils::DynamicArray<double>>>& GetWeights() const;
        Utils::DynamicArray<Neuron*>& GetInputLayer() const;
        Utils::DynamicArray<Neuron*>& GetOutputLayer() const;
        double GetWeight(const int& layer_num, const int& src_neuron_number, const int& dst_neuron_number);
        
        // Setters
        void SetInputLayer(const DynamicArray<double>& inputs);

        // Network Functionallity
        void Print();
        void PropagateForward();
};

#include "NeuralNetwork.cpp"

