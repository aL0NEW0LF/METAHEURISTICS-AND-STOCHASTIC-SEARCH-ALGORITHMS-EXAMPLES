#ifndef _chromosome_hpp
#define _chromosome_hpp

#include <assert.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include "./gene.hpp"
#include "./alea.hpp"
#include "./param.hpp"

extern param *para;
extern alea RANDOM;

class chromosome
{
    private:
        // les genes du chromosome
        gene   *genes; 
        int    Longueur;
        // valeur de fitness du chromosome
        double Fitness;
    public:
        chromosome(int ell = para->lchrom);
        chromosome(const chromosome &chrom);
        ~chromosome() { delete[] genes; }

        /* getters */
        double fitness() { return Fitness; }
        int  longueur() { return Longueur; }
        gene *get_genes() { return genes; }

        /* setters */
        inline void set_valeur(const int &locus, const int &value) { genes[locus] = int(value); }
        void set_fitness(double fit) { Fitness = fit; }
        
        // evaluer Chromosome
        void evaluer();
        // initialisation aléatoire
        void random();
        // initialisation à partir d'un fichier
        void init(std::ifstream &in1);
        // mutation aléatoire des genes.
        void mutation(double pmut);
        // muter un seul bit de façon aléatoire
        void mutation1bit();
        // chercher dans le net
        void hamming_mutation(double pmut);
        
        // Convertir le chromosome en une chaîne de caractères.
        void bin2string( char *str );
        // copie 'n' genes specifiés par 'locus' de gene pour chromosome 'C' 
        void copieGene( chromosome &C, int *locus, int n );

        chromosome & operator=(const chromosome &chrom);
        gene & operator[](int loci) { return genes[loci]; }
        friend std::ostream &operator<< (std::ostream &out, chromosome &chrom);
};

#endif
