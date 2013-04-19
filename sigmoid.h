#ifndef SIGMOID_H
#define SIGMOID_H
#include "activationfunction.h"

/* Implementation of the activation function from FANN project.
 * see http://leenissen.dk/fann/wp/ for more details. */

class Sigmoid : public ActivationFunction
{
public:
    Sigmoid();
    ~Sigmoid();
    virtual double Calculate(double arg) const;
    virtual double GetDerivative(double arg) const;
    void SetSteepness(double steepness);
    double GetSteepness();
private:
    double steepness_;
};

#endif // SIGMOID_H
