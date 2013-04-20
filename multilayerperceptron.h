#ifndef MULTILAYERPERCEPTRON_H
#define MULTILAYERPERCEPTRON_H
#include "layer.h"



class MultiLayerPerceptron
{
public:
    MultiLayerPerceptron();
    MultiLayerPerceptron(unsigned int layers_num, unsigned int first_count, unsigned int internal_count, unsigned int last_count);
    ~MultiLayerPerceptron();
    void Init(unsigned int layers_num, unsigned int first_count, unsigned int internal_count, unsigned int last_count);
    /// Загрузка сети из конфигурационного файла
    void Save(const char* file_path);
    /// Сохранение сети в конфигурационный файл
    bool Load(const char* file_path);
    /// Прямой проход
    void ForwardCalculate();
    /// Обратный проход
    void BackwardCalculate();
    /// Заполнение весовых коэфф. случайными числами всех нейронов сети
    void RndWeights();
    /// Обнуление весовых коэффициентов всех нейронов сети
    void ResetWeights();
    /// Обнуление массива поправок весовых коэффициентов cлоя
    void ResetWeightDiffs();
    /// Метод задания входных значений
    void SetInput(double* input_array);
    /// Метод получения результата
    double* GetOutput() const;
    /// Методы доступа к параметру скорости обучения
    double get_learing_rate();
    void set_learning_rate(double rate);
    /// Методы доступа к параметру постоянной момента
    double get_learning_momentum();
    void set_learning_momentum(double momentum);
    /// Методы доступа к массиву сигналов ошибки
    void CalcErrorSignals();
    /// Расчет локальных градиентов последнего слоя
    void CalcLastDeltas();
    void SetOptimalOutput(double* optimal_output);

private:
    Layer** layers_; /// массив нейронных слоев
    double num_layers_; /// число слоев
    double *input_values_; /// массив входных значений
    double learing_rate_; /// параметр скорости обучения сети
    double learning_momentum_; /// параметр постоянной моменты обучения
    double* error_signals_; /// массив сигналов ошибки
    double *optimal_output_; /// эталонный выход
};

#endif // MULTILAYERPERCEPTRON_H
