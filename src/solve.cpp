#include "solve.h"
#include <cmath>

std::vector<double> solve(double a, double b, double c, double epsilon) {
    if(!std::isfinite(a)) {
        throw a_is_special_double_exception();
    }
    if(!std::isfinite(b)) {
        throw b_is_special_double_exception();
    }
    if(!std::isfinite(c)) {
        throw c_is_special_double_exception();
    }
    if(!std::isfinite(epsilon)) {
        throw epsilon_is_special_double_exception();
    }
    if(std::abs(a)<epsilon) {
        throw a_is_almost_zero_exception();
    }
    double D=b*b-4.*a*c;
    if(D<-epsilon) {
        return std::vector<double>();
    }
    if(D<=epsilon) {
        return std::vector<double>(2, (-b)/(2.*a));
    }
    return std::vector<double>({ (-b-std::sqrt(D))/(2.*a), (-b+std::sqrt(D))/(2.*a) });
}
