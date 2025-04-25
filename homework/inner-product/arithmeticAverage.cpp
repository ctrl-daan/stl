#include "arithmeticAverage.hpp"

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    double sum1 = std::accumulate(first.begin(), first.end(), 0);
    double sum2 = std::accumulate(second.begin(), second.end(), 0);

    double size = first.size() + second.size();
    double sumTotal = sum1 + sum2;

    return sumTotal / size;
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    double squareSum = std::inner_product(first.begin(), first.end(), second.begin(), 0,
                                          std::plus<double>(), [](int fnum, int snum) { return std::pow(fnum - snum, 2); });
    return std::sqrt(squareSum);
}