#ifndef _alea_hpp
#define _alea_hpp

#include <random>
#include <iostream>
#include <fstream>

class alea
{   
    private:
        std::default_random_engine generator;
    public:
        alea() {}
        ~alea() {}
        int bernoulli( double prob );
        int flip( double prob );
        double uniform( double a, double b );
        double normal( double mean, double std );
};

#endif