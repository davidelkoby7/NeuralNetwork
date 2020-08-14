#include "../../Utils/GeneralFunctions.cpp"
#include "../../Utils/Constants.h"
#include "../../Utils/DynamicArray.h"

namespace MNISTParser
{
    const char* ReadTrainFileData()
    {
        return GeneralFunctions::ReadBinaryFile(Constants::MNIST_TRAIN_DATA_FILE_PATH);
    }

    const char* ReadTrainLabelsFileData()
    {
        return GeneralFunctions::ReadBinaryFile(Constants::MNIST_TRAIN_LABELS_FILE_PATH);
    }

    const char* ReadTestFileData()
    {
        return GeneralFunctions::ReadBinaryFile(Constants::MNIST_TEST_DATA_FILE_PATH);
    }

    const char* ReadTestLabelsFileData()
    {
        return GeneralFunctions::ReadBinaryFile(Constants::MNIST_TEST_LABELS_FILE_PATH);
    }

    // Returns a dynamic array of size 60000, where each of the items is an image of a number
    // stored in the train data file image of a number
    Utils::DynamicArray<Utils::DynamicArray<double>>* GetTrainInputs()
    {
        const char* trainData = ReadTrainFileData();
        Utils::DynamicArray<Utils::DynamicArray<double>>* trainInputs = new Utils::DynamicArray<Utils::DynamicArray<double>>(Constants::MNIST_TRAIN_DATA_LENGTH);

        // Going over all the images
        for (int i = 0; i < Constants::MNIST_TRAIN_DATA_LENGTH; i++)
        {
            Utils::DynamicArray<double>* currentImage = new Utils::DynamicArray<double>(Constants::MNIST_IMAGE_SIZE);
            for (size_t j = 0; j < Constants::MNIST_IMAGE_SIZE; j++)
            {
                //double newValue = static_cast<double>(trainData[i * Constants::MNIST_IMAGE_SIZE + j + Constants::MNIST_TRAIN_DATA_START_OFFSET]);
                double newValue = static_cast<double>(trainData[i * Constants::MNIST_IMAGE_SIZE + j + Constants::MNIST_TRAIN_DATA_START_OFFSET]);
                if (newValue < 0)
                    newValue = 256 + newValue;
                newValue = newValue / 255;
                currentImage->SetItem(j, newValue);
            }

            trainInputs->SetItem(i, *currentImage);
        }

        return trainInputs;
    }

    // Returns a dynamic array of size 60000, where each of it's item
    // is a dynamic array containing one element - the output (number)
    // the network should give to the same item index on the training data
    Utils::DynamicArray<Utils::DynamicArray<double>>* GetTrainOutputs()
    {
        const char* trainLabels = ReadTrainLabelsFileData();
        Utils::DynamicArray<Utils::DynamicArray<double>>* trainOutputs = new Utils::DynamicArray<Utils::DynamicArray<double>>(Constants::MNIST_TRAIN_DATA_LENGTH);

        // Running over all the images
        for (size_t i = 0; i < Constants::MNIST_TRAIN_DATA_LENGTH; i++)
        {
            // Creating a dynamic array for the outputs.
            Utils::DynamicArray<double>* currentImage = new Utils::DynamicArray<double>(10);
            
            // Parse the current desired output, and build an array 
            // where all the values are 0 except the value we want as output
            double currValue = static_cast<double>(trainLabels[i + Constants::MNIST_TRAIN_LABELS_START_OFFSET]);
            for (size_t j = 0; j < 10; j ++) // loop of 10 - as the 10 possible digits (0-9)
            {
                if (currValue == j)
                    currentImage->SetItem(j, 1);
                else
                    currentImage->SetItem(j, 0);
            }
            trainOutputs->SetItem(i, *currentImage);
        }

        return trainOutputs;
    }
}

