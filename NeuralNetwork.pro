TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    neuron.cpp \
    layer.cpp \
    multilayerperceptron.cpp \
    sigmoid.cpp

HEADERS += \
    neuron.h \
    activationfunction.h \
    layer.h \
    multilayerperceptron.h \
    sigmoid.h

