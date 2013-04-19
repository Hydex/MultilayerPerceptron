#ifndef MULTILAYERPERCEPTRON_H
#define MULTILAYERPERCEPTRON_H
#include "layer.h"
#include <list>

class MultiLayerPerceptron
{
public:
    MultiLayerPerceptron();
    MultiLayerPerceptron(unsigned int layers_num, unsigned int* layer_capacity);
    ~MultiLayerPerceptron();
    void InitLayers();
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
    /// Метод задания входных значений
    void SetInput(double* input_array);
    /// Метод получения результата
    double* GetOutput() const;
    /// Методы доступа к параметру скорости обучения
    double get_learing_rate();
    void set_learing_rate();
    /// Методы доступа к параметру постоянной момента
    double get_learning_momentum_();
    double set_learning_momentum_();
    /// Методы доступа к массиву сигналов ошибки
    void SetErrorSignals(double* er);



private:
    void CreateInputLayer();
    void CreateHiddenLayers();
    void CreateOutPutLayer();
    unsigned int numInputs_; /// число входов
    unsigned int numOutputs_; /// число выходов
    //unsigned int numHiddenNeurons_; /// число нейронов в скрытых слоях
    Layer** layers_; /// массив слоев
    double *input_values_; /// массив входных значений
    double *output_values_; /// массив выходных значений
    double learing_rate_; /// параметр скорости обучения сети
    double learning_momentum_; /// параметр постоянной моменты обучения
    double* error_signals_; /// массив сигналов ошибки

};

#endif // MULTILAYERPERCEPTRON_H
