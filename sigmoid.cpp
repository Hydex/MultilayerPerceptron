#include "sigmoid.h"
#include <math.h>

Sigmoid::Sigmoid():steepness_(1.0)
{
}

Sigmoid::~Sigmoid() {
    ;
}

double Sigmoid::Calculate(double arg) const{
    double calculated = 1.0 / (1.0 + exp(-2.0 * steepness_ * arg));
    return calculated;
}

double Sigmoid::GetDerivative(double arg) const{
    double derivative = 2.0 * steepness_ * arg * (1.0 - arg);
    return derivative;
}

void Sigmoid::SetSteepness(double steepness) {
    steepness_ = steepness;
}

double Sigmoid::GetSteepness() {
    return steepness_;
}
