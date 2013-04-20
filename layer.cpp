#include "layer.h"
#include "sigmoid.h"
#include <cstdlib>

Layer::Layer() : input_values_(NULL), output_values_(NULL), neurons_(NULL), activation_function_(NULL) {
}

Layer::Layer(unsigned int num_neurons, unsigned int num_inputs): input_values_(NULL), output_values_(NULL), neurons_(NULL), activation_function_(NULL) {
    Init(num_neurons, num_inputs);
}

Layer::~Layer() {
    delete activation_function_;
    if (neurons_ != NULL) {
        for (unsigned int i = 0; i < num_neurons_; i++)
            delete neurons_[i];
        delete[] neurons_;
    }
    delete[] output_values_;
}

void Layer::Init(unsigned int num_neurons, unsigned int num_inputs) {
    num_neurons_ = num_neurons;
    num_inputs_ = num_inputs;
    if (activation_function_ == NULL)
        activation_function_ = new Sigmoid();
    if (neurons_ == NULL) {
        neurons_ = new Neuron*[num_neurons];
        for (unsigned int i = 0; i < num_neurons; ++i ) {
            neurons_[i] = new Neuron(num_inputs);
            neurons_[i]->SetActivationFunc(activation_function_);
        }
    }
    if (output_values_ == NULL)
        output_values_ = new double[num_neurons];
}

void Layer::SetInput(double *input_array) {
    input_values_ = input_array;
}

void Layer::CalcOutput() {
    for (unsigned int i = 0; i < num_neurons_; ++i) {
        neurons_[i]->SetInputs(input_values_);
        neurons_[i]->Process();
        output_values_[i] = neurons_[i]->GetOutput();
    }
}

double* Layer::GetOutput() {
    return output_values_;
}

Neuron* Layer::GetNeuron(const unsigned int index) const {
    return neurons_[index];
}

unsigned int Layer::NeuronsCount() {
    return num_neurons_;
}

void Layer::RndWeights() {
    for (unsigned int i = 0; i < num_neurons_; ++i ) {
        neurons_[i]->RndWeights();
    }
}

void Layer::ResetWeights() {
    for (unsigned int i = 0; i < num_neurons_; ++i ) {
        neurons_[i]->ResetWeights();
    }
}

void Layer::ResetWeightDiffs() {
    for (unsigned int i = 0; i < num_neurons_; ++i ) {
        neurons_[i]->ResetWeightDiffs();
    }
}

void Layer::CalcDeltas(double delta_coeff) {
    for (unsigned int neuro_num = 0; neuro_num < num_neurons_; ++neuro_num) {
        neurons_[neuro_num]->CalcDelta(delta_coeff);
    }
}

void Layer::UpdateWeights() {
    for (unsigned int neuro_num = 0; neuro_num < num_neurons_; ++neuro_num) {
        neurons_[neuro_num]->UpdateWeights();
    }
}

double Layer::GetDeltaCoeff(unsigned int index) const {
    double delta_coeff = 0.0;
    Neuron* curr_neuron;
    for (unsigned int neuro_num = 0; neuro_num < num_neurons_; ++neuro_num) {
        curr_neuron = neurons_[neuro_num];
        delta_coeff += curr_neuron->delta_ * curr_neuron->GetWeight(index);
    }
    return delta_coeff;
}

