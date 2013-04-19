#ifndef MULTILAYERPERCEPTRON_H
#define MULTILAYERPERCEPTRON_H
#include "layer.h"

class MultiLayerPerceptron
{
public:
    MultiLayerPerceptron();
    MultiLayerPerceptron(unsigned int layers_num, unsigned int* layer_capacity);
    ~MultiLayerPerceptron();
    void ForwardCalculate();
    void BackwardCalculate();
private:
    unsigned int numInputs; /// число входов
    unsigned int numOutputs; /// число выходов
    unsigned int numHiddenNeurons; /// число нейронов в скрытых слоях
    Layer** layers;
};

#endif // MULTILAYERPERCEPTRON_H
