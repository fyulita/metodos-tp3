#include <algorithm>
//#include <chrono>
#include <pybind11/pybind11.h>
#include <iostream>
#include <exception>
#include "linear_regression.h"

using namespace std;
namespace py=pybind11;

LinearRegression::LinearRegression() {
}

void LinearRegression::fit(Vector x, Vector y) {
    int n = x.size();

    Vector ones(n);
    ones.fill((double)1);

    Matrix X(n, 2);
    X.col(0) = x;
    X.col(1) = ones;

    Matrix X_new = X.transpose() * X;
    Vector y_new = X.transpose() * y;

    Vector coeffs = X_new.inverse() * y_new;

    this-> alpha = coeffs;
}

Matrix LinearRegression::predict(Vector x) {
    Vector y(x.size());
    for (unsigned int i = 0; i < x.size(); i++) {
        y(i) = alpha(0) * x(i) + alpha(1);
    }

    return y;

    //auto ret = MatrixXd::Zero(X.rows(), 1);

    //return ret;
}



void LinearRegression::fit2(Matrix X, Vector y) {
    Matrix XNew = Matrix(X.rows(), X.cols() + 1);    //Asumiendo que X es una matriz
    
    Vector ones(n);
    ones.fill((double)1); 
    X.col(0) = ones;

    for(int i = 0;i<X.cols(),i++){
        XNew.col(i+1) = X.col(i);
    }
    

    x = XNew.transpose()*XNew  //x la matriz de la parte privada.
}


