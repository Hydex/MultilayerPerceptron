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
    /// Метод получения числа входов нейрона
    unsigned int InputSize();
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
    /// Обнуление массива поправок весовых коэффициентов
    void ResetWeightDiffs();
    /// Переработка входных значений в выходное
    void Process();
    /// Метод получения выходного значения
    double GetOutput() const;
    /// Методы доступа к значениям локального градиента
    void set_delta(double input_delta);
    double get_delta() const;
    /// Метод вычисления локального градиента
    void CalcDelta(double delta_coeff);
    /// Обновление весовых коээффициентов с учетом корректировки
    void UpdateWeights();


private:
    /// Вычисление взвешенной суммы
    void CalcWeightedSum();
    /// Вычисление значения функции активации
    void Activation();
    unsigned int num_inputs_;
    double* inputs_;
    double delta_;
    double* weights_;
    double* weight_diffs_;
    double weighted_sum_;
    ActivationFunction* activation_function_;
    double output_;
};

#endif // NEURON_H
