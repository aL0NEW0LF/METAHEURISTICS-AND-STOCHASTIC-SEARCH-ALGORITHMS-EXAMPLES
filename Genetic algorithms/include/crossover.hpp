#ifndef _CROSSOVER_HPP
#define _CROSSOVER_HPP

#include "chromosome.hpp"

class Crossover {
    public:
        void croiser( chromosome &pere, chromosome &mere );
};

class crossover1_2point : public Crossover {
    private:
        int pointCrossover;
    
    public:
        crossover1_2point( int nbrCrossover );
        void croiser( chromosome &pere, chromosome &mere );
};

#endif