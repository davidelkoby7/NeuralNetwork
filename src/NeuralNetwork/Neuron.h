#pragma once

#include "../Utils/DynamicArray.h"
#include "../Utils/GeneralFunctions.cpp"

class Neuron
{
    private:
        double m_value;
        double m_bias;
        Utils::DynamicArray<Neuron*> m_nextLayerNeurons;
    public:
        // Constructos and Destructor
        ~Neuron();
        Neuron();
        Neuron(const double& newValue, const double& newBias, const Utils::DynamicArray<Neuron*>& nextLayerNeurons);
        
        // Setters
        void SetValue(const double& newValue);
        void SetBias(const double& newBias);
        
        // Getters
        double GetValue() const;
        double GetBias() const;
        Utils::DynamicArray<Neuron*>& GetNextLayerNeurons();

        // Additional Functionallities
        std::string ToString() const;
        std::string ToStringNoNextLayer() const;
        void Print();
        void PrintNoNextLayer();
};

#include "Neuron.cpp"

