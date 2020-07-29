#pragma once

namespace Constants
{
    /* ~~~ Math constants ~~~ */
    static const double e = 2.718281828459;
    /* ~~~ Math constants ~~~ */

    /* ~~~ Neural Network file reading constants ~~~ */
    static const int LEARNING_RATE_LINE = 0;
    static const int NUM_OF_LAYERS_LINE = 1;
    static const int NUM_OF_NEURONS_PER_LAYER_LINE = 2;
    static const int NEURONS_BIASES_STARTING_LINE = 3;
    /* ~~~ Neural Network file reading constants ~~~ */

    /* ~~~ MNIST Constants ~~~ */
    // Data file paths
    static const char* MNIST_TRAIN_DATA_FILE_PATH = "src/Datasets/MNIST/trainingData/train-images-idx3-ubyte";
    static const char* MNIST_TRAIN_LABELS_FILE_PATH = "src/Datasets/MNIST/trainingData/train-labels-idx1-ubyte";

    static const char* MNIST_TEST_DATA_FILE_PATH = "src/Datasets/MNIST/testingData/t10k-images-idx3-ubyte";
    static const char* MNIST_TEST_LABELS_FILE_PATH = "src/Datasets/MNIST/testingData/t10k-labels-idx1-ubyte";

    // Offset from the start of the file to where the images/labels actually start
    static const int MNIST_TRAIN_DATA_START_OFFSET = 16;
    static const int MNIST_TRAIN_LABELS_START_OFFSET = 8;
    static const int MNIST_TEST_DATA_START_OFFSET = 16;
    static const int MNIST_TEST_LABELS_START_OFFSET = 8;

    // Number of images/labels for the training and testing data sets.
    static const int MNIST_TRAIN_DATA_LENGTH = 60000;
    static const int MNIST_TEST_DATA_LENGTH = 10000;

    static const int MNIST_IMAGE_SIZE = 784;
    /* ~~~ MNIST Constants ~~~ */
}
