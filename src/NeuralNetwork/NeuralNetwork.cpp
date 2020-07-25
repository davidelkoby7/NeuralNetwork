#include "NeuralNetwork.h"

template <int numOfLayers>
NeuralNetwork<numOfLayers>::~NeuralNetwork()
{
}

template <int numOfLayers>
NeuralNetwork<numOfLayers>::NeuralNetwork(const Utils::DynamicArray<int>& numOfNeuronsForLayers, double (*newActivationFunction)(const double& x), double (*newActivationFunctionDerivative)(const double& x), const double& newLeariningRate)
{
    // Setting the activation function
    this->activationFunction = newActivationFunction;
    this->activationFunctionDerivative = newActivationFunctionDerivative;
    this->learningRate = newLeariningRate;

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
double NeuralNetwork<numOfLayers>::GetLearningRate()
{
    return this->learningRate;
}

template <int numOfLayers>
void NeuralNetwork<numOfLayers>::SetInputLayer(const Utils::DynamicArray<double>& inputs)
{
    if (this->layers[0]->GetLength() != inputs.GetLength())
    {
        throw "Input given not in the correct length!";
    }

    for (uint i = 0; i < this->layers[0]->GetLength(); i++)
    {
        this->layers[0]->GetItem(i)->SetValue(inputs[i]);
    }
}

template <int numOfLayers>
void NeuralNetwork<numOfLayers>::SetLearningRate(const double& newLearningRate)
{
    this->learningRate = newLearningRate;
}

template <int numOfLayers>
void NeuralNetwork<numOfLayers>::Print()
{
    std::cout << "|| Printing Neural Network ||\n";
    std::cout << "\n-- Learning Rate: " << this->learningRate << " --\n\n";
    // Running over the layers
    for (uint i = 0; i < this->layers.GetLength(); i++)
    {
        std::cout << "~~ Printing layer number: " << i << " ~~\n";

        // Running over each Neuron in that layer
        for (uint j = 0; j < this->layers[i]->GetLength(); j++)
        {
            std::cout << "@@ Printing neuron number: " << j << " @@\n";
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
                newCurrentNeuronValue += previousLayerNeuron->GetValue() * currentWeight;
            }
            newCurrentNeuronValue += currentNeuron->GetBias();
            currentNeuron->SetValue(newCurrentNeuronValue);
        }
    }
}

template <int numOfLayers>
void NeuralNetwork<numOfLayers>::BackPropagate(const Utils::DynamicArray<Utils::DynamicArray<double>>& inputs, const Utils::DynamicArray<Utils::DynamicArray<double>>& expectedOutputs)
{
    // Making sure the output is in the correct length
    if (expectedOutputs.GetLength() != inputs.GetLength())
        throw "Mismatch in the length of the inputs and the outputs";

    // Running over all the training data
    for (uint currentInput = 0; currentInput < inputs.GetLength(); currentInput++)
    {
        // Setting the input layer to the given data
        this->SetInputLayer(inputs[currentInput]);
        this->PropagateForward();

        // Running over all the neuron layers from the last layer to the first
        for (int i = numOfLayers - 1; i >= 0; i--)
        {
            // Running over each neuron in the current layer (i)
            for (uint j = 0; j < this->layers[i]->GetLength(); j++)
            {
                Neuron* currentNeuron = this->layers[i]->GetItem(j);

                // If the output layer neuron - check it's error with the expectedOutputs array
                if (i == numOfLayers - 1)
                {
                    // Updating the neuron's delta value (error value)
                    double newDelta = expectedOutputs[currentInput].GetItem(j) - currentNeuron->GetValue();
                    double activationDerivativeResult = this->activationFunctionDerivative(currentNeuron->GetValue());
                    newDelta *= activationDerivativeResult;
                    currentNeuron->SetDelta(newDelta);

                    // Improving the bias of that neuron
                    currentNeuron->SetBias(currentNeuron->GetBias() + this->learningRate * newDelta);
                }
                else // If the neuron is not in the output layer
                {
                    // Calculating the new delta (error) of the neuron
                    double newDelta = 0;

                    // Adding the influence of this neuron over the next layer neurons
                    for (uint k = 0; k < this->layers[i + 1]->GetLength(); k++)
                    {
                        double deltaAddition;
                        deltaAddition = this->layers[i + 1]->GetItem(k)->GetDelta();
                        deltaAddition *= this->GetWeight(i, j, k);
                        newDelta += deltaAddition;
                    }

                    newDelta *= this->ActivationFunctionDerivative(currentNeuron->GetValue());
                    currentNeuron->SetDelta(newDelta);

                    // Updating the bias of that neuron
                    currentNeuron->SetBias(currentNeuron->GetBias() + this->learningRate * newDelta);

                    // Running over all the weights connected to that neuron and improving them
                    for (uint k = 0; k < this->layers[i + 1]->GetLength(); k++)
                    {
                        double& currentWeight = this->weights[i]->GetItem(j)->GetItem(k);
                        currentWeight = currentNeuron->GetValue() * this->layers[i + 1]->GetItem(k)->GetDelta() * this->learningRate;
                    }
                }
            }
        }
    }
}

template <int numOfLayers>
double NeuralNetwork<numOfLayers>::ActivationFunction(const double& x)
{
    return this->activationFunction(x);
}

template <int numOfLayers>
double NeuralNetwork<numOfLayers>::ActivationFunctionDerivative(const double& x)
{
    return this->activationFunctionDerivative(x);
}

