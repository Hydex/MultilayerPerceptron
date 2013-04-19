#ifndef NEURON_H
#define NEURON_H
#include "activationfunction.h"

class Neuron
{
public:
    Neuron();
    ~Neuron();
    Neuron(unsigned int num_inputs);
    void InitWeights(unsigned int num_inputs);
    /// Методы для доступа к значениям входных сигналов
    void SetInputs(double *input_array);
    double GetInput(unsigned int index) const;
    /// Методы для доступа к значениям весовых коэффициентов
    void SetWeight(unsigned int index, double input);
    void SetWeights(double *input_array);
    double GetWeight(unsigned int index) const;
    /// Метод задания функции активации
    void SetActivationFunc(ActivationFunction *activation_function);
    /// Заполнение весовых коэфф. случайными числами
    void RndWeights();
    /// Обнуление весовых коэффициентов
    void ResetWeights();
    /// Переработка входных значений в выходное
    void Process();
    /// Метод получения выходного значения
    double GetOutput() const;
    /// Метод получения производной от ф-ции активации
    double GetDerivative() const;
    /// Метод получения числа входов нейрона
    unsigned int InputSize();

private:
    /// Вычисление взвешенной суммы
    void CalcWeightedSum();
    /// Вычисление значения функции активации
    void Activation();
    unsigned int num_inputs_;
    double* inputs_;
    double* weights_;
    double weighted_sum_;
    ActivationFunction* activation_function_;
    double output_;
};

#endif // NEURON_H
