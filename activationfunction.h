#ifndef ACTIVATIONFUNCTION_H
#define ACTIVATIONFUNCTION_H

class ActivationFunction
{
public:
    virtual ~ActivationFunction() {}
    virtual double Calculate(double arg) const = 0;
    virtual double GetDerivative(double arg) const = 0;
};

#endif // ACTIVATIONFUNCTION_H
