#pragma once

#include "../Utils/DynamicArray.cpp"
#include "../Utils/GeneralFunctions.cpp"

class Neuron
{
    private:
        double m_value;
        double m_bias;
        DynamicArray<*Neuron> m_nextLayerNeurons;
    public:
        // Constructos and Destructor
        ~Neuron();
        Neuron();
        Neuron(const double& newValue, const double& newBias, Neuron* nextLayerNeurons);
        
        // Setters
        void SetValue(const double& newValue);
        void SetBias(const double& newBias);
        
        // Getters
        double GetValue();
        double GetBias();
        DynamicArray<*Neuron>& GetNextLayerNeurons;
};

