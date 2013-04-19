#ifndef LAYER_H
#define LAYER_H
#include "neuron.h"
#include "activationfunction.h"


class Layer
{
public:
    Layer();
    Layer(unsigned int num_neurons, unsigned int num_inputs);
    ~Layer();
    void Init(unsigned int num_neurons, unsigned int num_inputs);
    void SetInput(double* input_array);
    void ForwardCalculate();
    double* GetOutput();
    Neuron* GetNeuron(const unsigned int index) const;
    unsigned int NeuronsCount();
    /// Заполнение весовых коэфф. случайными числами всех нейронов слоя
    void RndWeights();
    /// Обнуление весовых коэффициентов всех нейронов слоя
    void ResetWeights();



private:
    unsigned int num_neurons_;
    unsigned int num_inputs_;
    double* input_values_; // массив входных значений слоя
    double* output_values_; // массив выходных значений слоя
    Neuron** neurons_;// массив нейронов слоя;
    ActivationFunction* activation_function_;
};

#endif // LAYER_H
