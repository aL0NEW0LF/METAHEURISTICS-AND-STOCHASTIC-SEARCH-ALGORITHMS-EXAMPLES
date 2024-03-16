#ifndef _gene_hpp
#define _gene_hpp

#include <assert.h>
#include <iostream>
#include <random>
#include "./alea.hpp"

extern alea RANDOM;

class gene {
    private:
        int Allele;  
    public:
        gene() {}
        gene(const int v) { Allele = v; }
        gene(const gene &g) { Allele = g.Allele; }
        ~gene() {}
        void random(double prob=0.5);
        void init(char bit);
        int allele() { return Allele; }
        gene & operator=(const gene &g);
        gene & operator=(const int v);
        int operator==(const gene &g) { return Allele == g.Allele; }
        int operator==(const int v)   { return Allele == v; }
        int operator!=(const gene &g) { return Allele != g.Allele; }
        int operator!=(const int v)   { return Allele != v; }
        void mutation();
        friend std::ostream &operator<< (std::ostream &out, const gene &g);
};

#endif
