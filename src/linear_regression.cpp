// #include <algorithm>
//#include <chrono>
// #include <pybind11/pybind11.h>
// #include <iostream>
// #include <exception>
#include "linear_regression.h"

using namespace std;
// namespace py=pybind11;

LinearRegression::LinearRegression() {
    Matrix coeffs;
    this-> alpha = coeffs;
}

void LinearRegression::fit(Matrix X, Matrix y) {
    unsigned int n = X.rows();
    unsigned int m = X.cols();

    Matrix XNew(n, m + 1);

    Vector ones(n);
    ones.fill((double)1);
    XNew.col(0) = ones;

    for(unsigned int i = 0; i < m; i++) {
        XNew.col(i + 1) = X.col(i);
    }

    Matrix XTX = XNew.transpose() * XNew;
    Vector XTy = XNew.transpose() * y;

    alpha = XTX.inverse() * XTy;
}

Matrix LinearRegression::predict(Matrix X) {
    unsigned int n = X.rows();
    unsigned int m = X.cols();

    Matrix XNew(n, m + 1);

    Vector ones(n);
    ones.fill((double)1);
    XNew.col(0) = ones;

    for(unsigned int i = 0; i < m; i++) {
        XNew.col(i + 1) = X.col(i);
    }

    Matrix y = XNew * alpha;
    return y;
}
