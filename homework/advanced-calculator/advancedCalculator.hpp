#pragma once
#include <algorithm>
#include <cctype>
#include <cmath>
#include <map>
#include <regex>
#include <sstream>
#include <string>
#include <unordered_set>
#include <utility>

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

long double float_factorial(double& n);
bool isInteger(double& num);
std::map<ErrorCode, double> advancedCalculator(const std::string& input, double& out);
ErrorCode process(std::string input, double* out);