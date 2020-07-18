#include <Neuron.h>

Neuron::~Neuron()
{
    delete[] this->m_nextLayerNeurons;
}

Neuron::Neuron()
{
    // In case of empty constructor - randomize values
    this->m_value = GeneralFunctions::RandomDouble(-1, 1);
    this->m_bias = GeneralFunctions::RandomDouble(-1, 1);
}

Neuron::Neuron(const double& newValue, const double& newBias, Neuron* nextLayerNeurons)
{
    this->m_value = newValue;
    this->m_bias = newBias;
    this->m_nextLayerNeurons = nextLayerNeurons;
}

void Neuron::SetValue(const double& newValue)
{
    this->m_value = newValue;
}

void Neuron::SetBias(const double& newBias)
{
    this->m_bias = newBias;
}

double Neuron::GetValue()
{
    return this->m_value;
}

double Neuron::GetBias()
{
    return this->m_bias;
}

DynamicArray<*Neuron>& Neuron::GetNextLayerNeurons()
{
    return this->m_nextLayerNeurons;
}

