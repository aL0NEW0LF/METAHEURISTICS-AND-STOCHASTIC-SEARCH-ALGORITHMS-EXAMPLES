#include "../include/alea.hpp"

int alea::bernoulli( double prob ) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::bernoulli_distribution distribution(prob);
    return distribution(generator);
}

int alea::flip( double prob ) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    return (distribution(generator) > prob);
}

int alea::uniform( int a, int b ) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(a, b);
    return distribution(generator);
}

double alea::uniform( double a, double b ) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<double> distribution(a, b);
    return distribution(generator);
}

double alea::normal( double mean, double std ) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::normal_distribution<double> distribution(mean, std);
    return distribution(generator);
}