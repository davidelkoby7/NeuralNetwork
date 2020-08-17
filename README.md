# Neural Networks Implementation from scratch

## General Notes
The main goal of the project was to build from the ground up an implementation of the neural networks algorithms. 

To make sure the implementation worked - I tested it on the MNIST dataset, and tried to make it classify images of hand written digits.

The program is made up from scratch, with no use of any external libraries (with the exception of std::string).

Classes like std::vector, std::array etc. are implemented under the Utils of this project.

## How it was tested
To test the NeuralNetwork implementation, I downloaded the MNIST dataset of hand written digits.

I constructed a network with 784 neurons, 200 hidden neurons, and 10 output neurons to indicate the output.

The final result (of that setup, probably can make it better with a different setup / learning rate) was 7.63% error.

## Using the NeuralNetwork Class:
### Step One: Creating the Neural Network object
In order to use the class, include the `NeuralNetwork.h` file in to your cpp file.

Then - create a dynamic array of integers, with each value representing the number of neurons in a given layer.

After that you can create your neural network with a simple constructor call :)

The constructor takes only one parameter as a must (the DynamicArray containing the number of neurons per layer), but also have some optional parameters:

* activationFunction: You can choose any activation function you'd like (By default - ReLU). You can find a few activation functions in the Utils/ActivationFunctions.h file

* activationFunctionDerivative: When choosing an activation function, you also need to supply a function fo it's derivative.
    
* learningRate: You can choose your learning rate for your network (By default - 0.1).

#### Example:

```c++
#include "NeuralNetwork/NeuralNetwork.h"
#include "Utils/ActivationFunctions.h"

int main()
{
    // Creating a nn for that data set (input - 784 neurons, output - 10 neurons, hidden layer of 200 neurons)
    Utils::DynamicArray<int> numOfNeuronsPerLayer;
    numOfNeuronsPerLayer.AddItem(784);
    numOfNeuronsPerLayer.AddItem(200);
    numOfNeuronsPerLayer.AddItem(10);
    NeuralNetwork* nn = new NeuralNetwork(numOfNeuronsPerLayer, ActivationFunctions::Sigmoid, ActivationFunctions::SigmoidDerivative, 0.12);
}
```

### Step Two: Making the network learn
In order to have the network learn from given data, we will use the `BackPropagate()` function.

That fuction expects two parameter:

* An array of inputs: Will be of type `Utils::DynamicArray<Utils::DynamicArray<double>>`. Each item in the array will represent an input. Each item in each input is a number corresponding to the value of a neuron in the input layer.
    
* An array of outputs: Will be of type `Utils::DynamicArray<Utils::DynamicArray<double>>`. Each item in the array will represent an output. Each item in each output is a number corresponding to the value of a neuron in the output layer.
    
The BackPropagate() function will run over each of the inputs, and learn from it's mistake relative to the given desired output.

Given enough data, the network should predict fairly well any behavior.

#### Example: Making it learn with the MNIST dataset.

```c++
#include "NeuralNetwork/NeuralNetwork.h"
#include "Utils/ActivationFunctions.h"

int main()
{
    // Getting the inputs and outputs of the MNIST Dataset
    Utils::DynamicArray<Utils::DynamicArray<double>>* trainInputs = MNISTParser::GetTrainInputs();
    Utils::DynamicArray<Utils::DynamicArray<double>>* trainOutputs = MNISTParser::GetTrainOutputs();

    // Creating a nn for that data set (input - 784 neurons, output - 10 neurons, hidden layer of 200 neurons)
    Utils::DynamicArray<int> numOfNeuronsPerLayer;
    numOfNeuronsPerLayer.AddItem(784);
    numOfNeuronsPerLayer.AddItem(200);
    numOfNeuronsPerLayer.AddItem(10);
    NeuralNetwork* nn = new NeuralNetwork(numOfNeuronsPerLayer, ActivationFunctions::Sigmoid, ActivationFunctions::SigmoidDerivative, 0.12);

    # Starting the learning process
    nn->BackPropagate(*trainInputs, *trainOutputs);

    # Saving the network to a file (recommended, no real need for extention)
    nn->SaveToFile("./MyMNISTNeuralNetwork.nn");
}
```

In the example above - the MNIST Parser returns an array with the inputs (pixel's grey scale values for each image, for 60000 images) and outputs (each output is of length 10, with only one of the neurons having the value 1 and the others 0, to represent the digit written).

### Step 3: Using the trained network to predict data
After the network learned from the data, it's super simple to predict output for a given input.

To do that, just:

* Use the `SetInputLayer()` function to set the input you want to perdict it's output (expects a parameter of type `Utils::DynamicArray<Utils::DynamicArray<double>>`, with each item representing a value in the input layer).
* Use the ForwardPropagate() function. That function will take the input you set before and feed it forward in the network. No need for any parameters.
* To get the result, just call the `GetOutputLayer()` function. This will return a `Utils::DynamicArray<Utils::DynamicArray<double>>`, where each item is the output of a neuron in the output layer.

## That's it!
With those easy 3 steps you created your neural network, trained it, and got predictions from it.
