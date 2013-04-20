#include "multilayerperceptron.h"
#include <cstdlib>

MultiLayerPerceptron::MultiLayerPerceptron() : layers_(NULL), error_signals_(NULL), optimal_output_(NULL)
{
}

MultiLayerPerceptron::MultiLayerPerceptron(unsigned int layers_num, unsigned int first_count, unsigned int internal_count, unsigned int last_count) :
    layers_(NULL), optimal_output_(NULL) {
    Init(layers_num, first_count, internal_count,  last_count);
}

void MultiLayerPerceptron::Init(unsigned int layers_num, unsigned int first_count, unsigned int internal_count, unsigned int last_count) {
    if (layers_ == NULL) {
        layers_ = new Layer*[layers_num];
        /// Создаем первый скрытый слой
        layers_[0] = new Layer(last_count, first_count);
        layers_[0]->SetInput(input_values_);
        /// Создаем внутренний слой
        layers_[1] = new Layer(internal_count, last_count);
        layers_[1]->SetInput(layers_[0]->GetOutput());
        /// Создаем внутренние слои
        for (unsigned int layer_num = 2; layer_num < layers_num - 1; ++layernum) {
            layers_[layer_num] = new Layer(internal_count, internal_count);
            layers_[layer_num]->SetInput(layers_[layer_num - 1]->GetOutput());
        }
        /// Создаем последний скрытый слой
        layers_[layers_num - 1] = new Layer(last_count, internal_count);
        layers_[layers_num - 1]->SetInput(layers_[layers_num - 2]->GetOutput());
    }
    if (error_signals_ == NULL)
        error_signals_ = new double[last_count];
}

MultiLayerPerceptron::~MultiLayerPerceptron() {
    if (layers_ != NULL) {
        for (unsigned int i = 0; i < num_layers_; ++i) {
            delete layers_[i];
        }
        delete layers_;
    }
    delete error_signals_;
}

void MultiLayerPerceptron::Save(const char *file_path) {
    /// Будет реализовано позднее
}

bool MultiLayerPerceptron::Load(const char *file_path) {
    /// Будет реализовано позднее
    return true;
}

void MultiLayerPerceptron::ForwardCalculate() {
    for (unsigned int num_layer = 0; num_layer < num_layers_; ++num_layer) {
        layers_[num_layer]->CalcOutput();
    }
}

void MultiLayerPerceptron::BackwardCalculate() {
    //layers_[num_layers_ - 1]
    for (unsigned int num_layer = num_layers_ - 2; num_layer > -1; --num_layer) {
        layers_[num_layer]->CalcDeltas(layers_[num_layer + 1]);
    }
}

void MultiLayerPerceptron::RndWeights() {
    for (unsigned int num_layer = 0; num_layer < num_layers_; ++num_layer) {
        layers_[num_layer]->RndWeights();
    }
}

void MultiLayerPerceptron::ResetWeights() {
    for (unsigned int num_layer = 0; num_layer < num_layers_; ++num_layer) {
        layers_[num_layer]->ResetWeights();
    }
}

void MultiLayerPerceptron::ResetWeightDiffs() {
    for (unsigned int num_layer = 0; num_layer < num_layers_; ++num_layer) {
        layers_[num_layer]->ResetWeightDiffs();
    }
}

void MultiLayerPerceptron::SetInput(double *input_array) {
    this->input_values_ = input_array;
}

double* MultiLayerPerceptron::GetOutput() {
    return layers_[num_layers_ - 1]->GetOutput();
}

double MultiLayerPerceptron::get_learing_rate() {
    return learing_rate_;
}

void MultiLayerPerceptron::set_learning_rate(double rate) {
    learing_rate_ = rate;
}

double MultiLayerPerceptron::get_learning_momentum() {
    return learning_momentum_;
}

void MultiLayerPerceptron::set_learning_momentum(double momentum) {
    learning_momentum_ = momentum;
}

void MultiLayerPerceptron::SetOptimalOutput(double *optimal_output) {
    this->optimal_output_ = optimal_output;
}

void MultiLayerPerceptron::CalcErrorSignals() {
    Layer* lastLayer = layers_[num_layers_ - 1];
    int num_neurons = lastLayer->NeuronsCount();
    double* out_vals = lastLayer->GetOutput();
    for (unsigned int num = 0; num < num_neurons; ++num) {
        error_signals_[num] = optimal_output_[num] - out_vals[num];
    }
}

void MultiLayerPerceptron::CalcLastDeltas() {
    Layer* lastLayer = layers_[num_layers_ - 1];
    int num_neurons = lastLayer->NeuronsCount();
    for (unsigned int num = 0; num < num_neurons; ++num) {
        error_signals_[num] = optimal_output_[num] - out_vals[num];
    }
}
