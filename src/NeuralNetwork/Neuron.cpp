#include "Neuron.h"

Neuron::~Neuron()
{
}

Neuron::Neuron()
{
    // In case of empty constructor - randomize values
    this->m_value = GeneralFunctions::RandomDouble(-1, 1);
    this->m_bias = GeneralFunctions::RandomDouble(-1, 1);
}

Neuron::Neuron(const double& newValue, const double& newBias, const Utils::DynamicArray<Neuron*>& nextLayerNeurons)
{
    this->m_value = newValue;
    this->m_bias = newBias;

    for (int i = 0; i < nextLayerNeurons.GetLength(); i++)
    {
        this->m_nextLayerNeurons.AddItem(nextLayerNeurons[i]);
    }
}

void Neuron::SetValue(const double& newValue)
{
    this->m_value = newValue;
}

void Neuron::SetBias(const double& newBias)
{
    this->m_bias = newBias;
}

double Neuron::GetValue() const
{
    return this->m_value;
}

double Neuron::GetBias() const
{
    return this->m_bias;
}

Utils::DynamicArray<Neuron*>& Neuron::GetNextLayerNeurons()
{
    return this->m_nextLayerNeurons;
}

std::string Neuron::ToString() const
{
    std::string neuronString = "{\nvalue: ";
    neuronString += std::to_string(this->GetValue());
    neuronString += ",\nbias: ";
    neuronString += std::to_string(this->GetBias());
    neuronString += ",\nnextLayerNeurons:\n{\n";

    size_t nextLayerLength = this->m_nextLayerNeurons.GetLength();

    for (size_t i = 0; i < nextLayerLength; i++)
    {
        neuronString += (this->m_nextLayerNeurons[i])->ToString();
        neuronString += ",\n";
    }

    neuronString += "}\n}";

    return neuronString;
}

void Neuron::Print()
{
    std::cout << this->ToString() << std::endl;
}

// Overloading the << operator so String will be accepted by std::cout
std::ostream &operator<<(std::ostream &os, Neuron const  &neuron) {
    return os << neuron.ToString();
}

