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
    void SetInput(double* input_array); /// Задание массива входных значений
    void CalcOutput(); /// Вычисления прямого прохода
    void CalcDeltas(double delta_coeff); /// Вычисление массива локальных градиентов
    void UpdateWeights(); /// Обновление весовых коэффициентов нейронов слоя
    double* GetOutput(); /// Получение массива выходных значений
    Neuron* GetNeuron(const unsigned int index) const;
    unsigned int NeuronsCount();
    /// Заполнение весовых коэфф. случайными числами всех нейронов слоя
    void RndWeights();
    /// Обнуление весовых коэффициентов всех нейронов слоя
    void ResetWeights();
    /// Обнуление массива поправок весовых коэффициентов cлоя
    void ResetWeightDiffs();
    /// Метод возвращает коэффициент от градиентов всех нейронов слоя
    double GetDeltaCoeff(unsigned int index) const;




private:
    unsigned int num_neurons_; /// число нейронов слоя
    unsigned int num_inputs_; /// число входов в нейронах слоя
    double* input_values_; /// массив входных значений слоя
    double* output_values_; /// массив выходных значений слоя
    Neuron** neurons_;/// массив нейронов слоя;
    ActivationFunction* activation_function_; /// функция активации слоя
};

#endif // LAYER_H
