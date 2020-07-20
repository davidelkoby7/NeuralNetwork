#pragma once

#include "../Utils/DynamicArray.cpp"
#include "../Utils/GeneralFunctions.cpp"

using namespace Utils;

class Neuron
{
    private:
        double m_value;
        double m_bias;
        DynamicArray<Neuron*> m_nextLayerNeurons;
    public:
        // Constructos and Destructor
        ~Neuron();
        Neuron();
        Neuron(const double& newValue, const double& newBias, const DynamicArray<Neuron*>& nextLayerNeurons);
        
        // Setters
        void SetValue(const double& newValue);
        void SetBias(const double& newBias);
        
        // Getters
        double GetValue() const;
        double GetBias() const;
        DynamicArray<Neuron*>& GetNextLayerNeurons();

        // Additional Functionallities
        std::string ToString() const;
        void Print();
};

