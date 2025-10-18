#ifndef SOLVE_H
#define SOLVE_H

#include<vector>

class a_is_almost_zero_exception: public std::exception {};
class a_is_special_double_exception: public std::exception {};
class b_is_special_double_exception: public std::exception {};
class c_is_special_double_exception: public std::exception {};
class epsilon_is_special_double_exception: public std::exception {};

std::vector<double> solve(double a, double v, double c, double epsilon) ;

#endif // SOLVE_H
