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
        DynamicArray<*Neuron> newLayer;

        // Filling the layer with random nodes
        for (int j = 0; j < numOfNeuronsForLayers[i]; j++)
        {
            Neuron* n = Neuron();
            newLayer.AddItem(n);
        }
    }

    // Initializing the weights array with randomized values
    for (int i = 0; i < numOfLayers - 1; i++)
    {
        DynamicArray<DynamicArray<double>> currLayerWeights;

        // Running over each of the neurons of the next layer
        for (int j = 0; j < numOfNeuronsForLayers[i + 1]; j++)
        {
            DynamicArray<double> currNeuronWeights;

            // For each of the neurons in the current layer - add a random weight to the next layer's neuron's DynamicArray.
            for (int k = 0; k < numOfNeuronsForLayers[i]; k++)
            {
                double randWeight = GeneralFunctions::RandomDouble(-1, 1);
                currNeuronWeights.AddItem(randWeight);
            }
            currLayerWeights.AddItem(currNeuronWeights);
        }
        this->weights.AddItem(currLayerWeights);
    }
}

template <int numOfLayers>
StaticArray<DynamicArray<*Neuron> ,numOfLayers>& NeuralNetwork<numOfLayers>::GetLayers() const
{
    return this->layers;
}

template <int numOfLayers>
DynamicArray<DynamicArray<double>>& NeuralNetwork<numOfLayers>::GetWeights() const
{
    return this->weight;
}

template <int numOfLayers>
DynamicArray<*Neuron>& GetInputLayer() const
{
    return this->layers[0];
}

template <int numOfLayers>
DynamicArray<*Neuron>& GetOutputLayer() const
{
    return this->layers[this->layer.GetLength() - 1];
}

template <int numOfLayers>
void SetInputLayer(const DynamicArray<double>& inputs)
{
    for (int i = 0; i < this->layers[0].GetLength(); i++)
    {
        this->layers[0][i] = inputs[i];
    }
}

template <int numOfLayers>
void PropagateForward()
{

}

