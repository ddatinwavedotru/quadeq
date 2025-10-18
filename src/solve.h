#ifndef SOLVE_H
#define SOLVE_H

#include<vector>

class a_is_almost_zero_exception: public std::exception {};
class a_is_special_double_exception: public std::exception {};
class b_is_special_double_exception: public std::exception {};
class c_is_special_double_exception: public std::exception {};
class epsilon_is_special_double_exception: public std::exception {};

/**
 * @brief solve решает квадратное уравнение
 * @param a коэффициент при x^2
 * @param b коэффициент при x^1
 * @param c коэффициент при x^0
 * @param epsilon малое значение для сравнения double с нулём
 * @return решения уравнения
 */
std::vector<double> solve(double a, double b, double c, double epsilon) ;

#endif // SOLVE_H
