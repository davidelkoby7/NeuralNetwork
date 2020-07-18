#pragma once

#include "../Utils/StaticArray.cpp"
#include "../Utils/DynamicArray.cpp"

using namespace Utils;

template <int numOfLayers>
class NeuralNetwork
{
    private:
        StaticArray<DynamicArray<*Node> ,numOfLayers> layers;
        DynamicArray<DynamicArray<double>> weights;
    public:
        // Destructor and Constructors
        ~NeuralNetwork();
        NeuralNetwork();
        // TODO: Constructor with file input
        
        // Getters
        StaticArray<DynamicArray<*Node> ,numOfLayers>& GetLayers() const;
        DynamicArray<DynamicArray<double>>& GetWeights() const;

};

