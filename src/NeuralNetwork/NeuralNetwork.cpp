#include "NeuralNetwork.h"

template <int numOfLayers>
NeuralNetwork<numOfLayers>::~NeuralNetwork()
{
}

template <int numOfLayers>
NeuralNetwork<numOfLayers>::NeuralNetwork(const DynamicArray<int>& numOfNeuronsForLayers)
{
    // Initializing a random valued layers for the network
    for (int i = 0; i < numOfLayers; i++)
    {
        // Creating the new layer
        Utils::DynamicArray<Neuron*>* newLayer = new Utils::DynamicArray<Neuron*>();

        // Filling the layer with random nodes
        for (int j = 0; j < numOfNeuronsForLayers[i]; j++)
        {
            Neuron *n = new Neuron();
            newLayer->AddItem(n);
        }

        this->layers[i] = newLayer;
    }

    // Initializing the weights array with randomized values
    for (int i = 0; i < numOfLayers - 1; i++)
    {
        Utils::DynamicArray<Utils::DynamicArray<double>*>* currLayerWeights = new Utils::DynamicArray<Utils::DynamicArray<double>*>();

        // Running over each of the neurons of the next layer
        for (int j = 0; j < numOfNeuronsForLayers[i]; j++)
        {
            Utils::DynamicArray<double>* currNeuronWeights = new Utils::DynamicArray<double>();

            // For each of the neurons in the current layer - add a random weight to the next layer's neuron's DynamicArray.
            for (int k = 0; k < numOfNeuronsForLayers[i + 1]; k++)
            {
                double randWeight = GeneralFunctions::RandomDouble(-1, 1);
                currNeuronWeights->AddItem(randWeight);
            }
            currNeuronWeights->Print();
            currLayerWeights->AddItem(currNeuronWeights);
        }
        this->weights.AddItem(currLayerWeights);
    }
}

template <int numOfLayers>
Utils::StaticArray<Utils::DynamicArray<Neuron*> ,numOfLayers>& NeuralNetwork<numOfLayers>::GetLayers() const
{
    return this->layers;
}

template <int numOfLayers>
Utils::DynamicArray<Utils::DynamicArray<Utils::DynamicArray<double>>>& NeuralNetwork<numOfLayers>::GetWeights() const
{
    return this->weight;
}

template <int numOfLayers>
Utils::DynamicArray<Neuron*>& NeuralNetwork<numOfLayers>::GetInputLayer() const
{
    return this->layers[0];
}

template <int numOfLayers>
Utils::DynamicArray<Neuron*>& NeuralNetwork<numOfLayers>::GetOutputLayer() const
{
    return this->layers[this->layer.GetLength() - 1];
}

template <int numOfLayers>
double NeuralNetwork<numOfLayers>::GetWeight(const int& layer_num, const int& src_neuron_number, const int& dst_neuron_number)
{
    return this->weights[layer_num]->GetItem(src_neuron_number)->GetItem(dst_neuron_number);
}

template <int numOfLayers>
void NeuralNetwork<numOfLayers>::SetInputLayer(const DynamicArray<double>& inputs)
{
    for (int i = 0; i < this->layers[0].GetLength(); i++)
    {
        this->layers[0][i] = inputs[i];
    }
}

template <int numOfLayers>
void NeuralNetwork<numOfLayers>::Print()
{
    // Running over the layers
    for (uint i = 0; i < this->layers.GetLength(); i++)
    {
        std::cout << "~~ Printing layer number: " << i << " ~~" << std::endl;

        // Running over each Neuron in that layer
        for (uint j = 0; j < this->layers[i]->GetLength(); j++)
        {
            std::cout << "@@ Printing neuron number: " << j << " @@" << std::endl;
            this->layers[i]->GetItem(j)->PrintNoNextLayer();
        }
    }

    // Running over all the weightsi (Layers Loop)
    for (uint i = 0; i < this->weights.GetLength(); i++)
    {
        Utils::DynamicArray<Utils::DynamicArray<double>*>* currentLayerWeights = this->weights.GetItem(i);

        // Running over the current layer neuron array
        for (uint j = 0; j < currentLayerWeights->GetLength(); j++)
        {
            Utils::DynamicArray<double>* currentNeuronWeights = currentLayerWeights->GetItem(j);

            // Running over all the weights of that neuron
            for (uint k = 0; k < currentNeuronWeights->GetLength(); k++)
            {
                std::cout << "[ layer: " << i << ", srcNeuron: " << j << ", dstNeuron: " << k << " ]:" << currentNeuronWeights->GetItem(k) << "\n";
            }
        }
    }
}

template <int numOfLayers>
void NeuralNetwork<numOfLayers>::PropagateForward()
{
    // Running over all the layers from the secend layer (the first layer is the input layer)
    for (uint i = 1; i < this->layers.GetLength(); i++)
    {
        Utils::DynamicArray<Neuron*>* currentLayer = this->layers.GetItem(i);
        Utils::DynamicArray<Neuron*>* previousLayer = this->layers.GetItem(i - 1);

        // Running over each neuron in the layer to update it's value
        for (uint j = 0; j < currentLayer->GetLength(); j++)
        {
            Neuron* currentNeuron = currentLayer->GetItem(j);
            currentNeuron->SetValue(0);
            double newCurrentNeuronValue = 0;

            // Running over each neuron in the previous layer to propagate it forward
            for (uint k = 0; k < previousLayer->GetLength(); k++)
            {
                Neuron* previousLayerNeuron = previousLayer->GetItem(k);
                double currentWeight = this->GetWeight(i - 1, k, j);
                std::cout << "currWeight: " << currentWeight << ", currValue: " << previousLayerNeuron->GetValue() << std::endl;
                newCurrentNeuronValue += previousLayerNeuron->GetValue() * currentWeight;
            }
            newCurrentNeuronValue += currentNeuron->GetBias();
            std::cout << newCurrentNeuronValue << std::endl;
            currentNeuron->SetValue(newCurrentNeuronValue);
        }
    }
}

