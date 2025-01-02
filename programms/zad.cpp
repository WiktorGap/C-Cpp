#include "zad.hpp"

Complex::Complex(double _re, double _im) : re(_re), im(_im) {}
Complex::Complex(double _re) : re(_re), im(0){}

double Complex::real(){
    return re;
}

double Complex::imag(){
    return im;
}

do