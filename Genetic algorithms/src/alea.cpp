#include "../include/alea.hpp"

int alea::bernoulli( double prob ) {
    std::bernoulli_distribution distribution(prob);
    return distribution(generator);
}

int alea::flip( double prob ) {
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    return (distribution(generator) > prob);
}

double alea::uniform( double a, double b ) {
    std::uniform_real_distribution<double> distribution(a, b);
    return distribution(generator);
}

double alea::normal( double mean, double std ) {
    std::normal_distribution<double> distribution(mean, std);
    return distribution(generator);
}