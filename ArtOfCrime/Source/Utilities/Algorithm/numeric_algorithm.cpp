#include "algorithm_aoc.h"

using namespace algorithm_aoc;

template NumericAlgorithm<int>;
template NumericAlgorithm<float>;
template NumericAlgorithm<double>;

template<typename T>
T NumericAlgorithm<T>::Clamp(T val, T max, T min)
{
    return val > max ? max : (val < min ? min : val);
}