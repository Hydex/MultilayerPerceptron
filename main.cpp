#include <iostream>


#include "layer.h"


using namespace std;


void test() {
    double vals[] = {1.0,2.0,3.0,4.0};
    Layer *l1 = new Layer(4,4);
    l1->SetInput(vals);
    l1->ForwardCalculate();
    Layer *l2 = new Layer(10, 4);
    unsigned int num_neurons = l1->NeuronsCount();
    //cout << "Sloy 1" << endl;
    //cout << "Input: " << endl;
    for (unsigned int i = 0; i < num_neurons; ++i) {
        Neuron *ni = l1->GetNeuron(i);
        //cout << "Neuron" << i << ": ";
        unsigned int input_num = ni->InputSize();
        for (unsigned int j = 0; j < input_num; ++j) {
            //cout << ni->GetInput(j) << ", ";
        }
        //cout << " ====> " << ni->GetOutput() << endl;
    }
    l2->SetInput(l1->GetOutput());
    l2->ForwardCalculate();
    num_neurons = l2->NeuronsCount();
    for (unsigned int i = 0; i < num_neurons; ++i) {
        Neuron *ni = l2->GetNeuron(i);
        //cout << "Neuron" << i << ": ";
        unsigned int input_num = ni->InputSize();
        for (unsigned int j = 0; j < input_num; ++j) {
            //cout << ni->GetInput(j) << ", ";
        }
        //cout << " ====> " << ni->GetOutput() << endl;
    }
    delete l1;
    delete l2;
}

int main()
{
    test();
    return 0;
}

