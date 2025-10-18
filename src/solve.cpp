#include "solve.h"

std::vector<double> solve(double a, double b, double c, double epsilon) {
    double D=b*b-4.*a*c;
    if(D<-epsilon) {
        return std::vector<double>();
    }
    return std::vector<double>();
}
