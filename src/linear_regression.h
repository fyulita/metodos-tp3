#pragma once

#include "types.h"

class LinearRegression {
public:
    LinearRegression();

    void fit(Vector x, Vector y); // Cambie de matrices a vectores.

    Matrix predict(Vector X); // Cambie de matriz a vector.
private:
    Vector alpha;
};
