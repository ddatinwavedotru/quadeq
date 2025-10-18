#include "solve.h"
#include <cmath>

std::vector<double> solve(double a, double b, double c, double epsilon) {
    if(std::abs(a)<epsilon) {
        throw a_is_almost_zero_exception();
    }
    double D=b*b-4.*a*c;
    if(D<-epsilon) {
        return std::vector<double>();
    }
    return std::vector<double>({ (-b-std::sqrt(D))/(2.*a), (-b+std::sqrt(D))/(2.*a) });
}
