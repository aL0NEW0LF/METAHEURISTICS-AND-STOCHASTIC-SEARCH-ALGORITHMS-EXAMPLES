#ifndef _alea_hpp
#define _alea_hpp

#include <random>
#include <iostream>
#include <fstream>

class alea
{   
    public:
        alea() {}
        ~alea() {}
        int bernoulli( double prob );
        int flip( double prob );
        int uniform( int a, int b );
        double uniform( double a, double b );
        double normal( double mean, double std );
};

#endif