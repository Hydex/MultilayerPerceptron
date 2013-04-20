#include "neuron.h"
#include "sigmoid.h"
#include <cstdlib>
#include <cstring>
#include <ctime>

Neuron::Neuron():  inputs_(NULL), weights_(NULL), weight_diffs_(NULL), activation_function_(NULL) {
}

Neuron::Neuron(unsigned int num_inputs) : num_inputs_(num_inputs), inputs_(NULL), weights_(NULL),
    weight_diffs_(NULL), activation_function_(NULL) {
    InitWeights(num_inputs);
}

Neuron::~Neuron() {
    delete[] weights_;
    delete[] weight_diffs_;
}

void Neuron::InitWeights(unsigned int num_inputs) {
    if (weights_ == NULL) {
        weights_ = new double[num_inputs];
        RndWeights();
    }
    if (weight_diffs_ == NULL) {
        weight_diffs_ = new double[num_inputs];
        ResetWeightDiffs();
    }
}

void Neuron::SetInputs(double *input_array) {
    this->inputs_ = input_array;
}

double Neuron::GetInput(unsigned int index) const {
    return inputs_[index];
}

unsigned int Neuron::InputSize() {
    return num_inputs_;
}

void Neuron::SetWeights(double *input_array) {
    memcpy(weights_, input_array, num_inputs_ * sizeof(double));
}

void Neuron::SetWeight(unsigned int index, double input) {
    weights_[index] = input;
}

double Neuron::GetWeight(unsigned int index) const {
    return weights_[index];
}

void Neuron::SetActivationFunc(ActivationFunction *activation_function) {
    this->activation_function_ = activation_function;
}

void Neuron::RndWeights(){
    srand(time(0));
    for (unsigned int i = 0; i < num_inputs_; ++i) {
        weights_[i] = (double)rand() / (RAND_MAX + 1) - 0.5;
    }
}

void Neuron::ResetWeights() {
    for (unsigned int i = 0; i < num_inputs_; ++i) {
        weights_[i] = 0.0;
    }
}

void Neuron::ResetWeightDiffs() {
    for (unsigned int i = 0; i < num_inputs_; ++i) {
        weight_diffs_[i] = 0.0;
    }
}

void Neuron::CalcWeightedSum() {
    weighted_sum_ = 0.0;
    for (unsigned int i = 0; i < num_inputs_; ++i) {
        weighted_sum_ += inputs_[i] * weights_[i];
    }
}

void Neuron::Activation() {
    output_ = activation_function_->Calculate(weighted_sum_);
}

void Neuron::Process() {
    CalcWeightedSum();
    Activation();
}

double Neuron::GetOutput() const {
    return output_;
}

double Neuron::get_delta() const {
    return delta_;
}

double Neuron::set_delta(double input_delta) {
    delta_ = input_delta;
}

void Neuron::CalcDelta(double delta_coeff) {
    double derivative = activation_function_->GetDerivative(weighted_sum_);
    delta_ = derivative * delta_coeff;
}

void Neuron::UpdateWeights(double learning_momentum, double learning_rate) {
    for (unsigned int i = 0; i < num_inputs_; ++i) {
        weight_diffs_[i] = learning_momentum * weight_diffs_[i] + learning_rate * delta_;
        weights_[i] = weights_[i] + weight_diffs_[i];
    }
}







