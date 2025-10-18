#ifndef SOLVE_H
#define SOLVE_H

#include<vector>

class a_is_almost_zero_exception: public std::exception {};

std::vector<double> solve(double a, double v, double c, double epsilon) ;

#endif // SOLVE_H
