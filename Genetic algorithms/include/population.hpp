#ifndef _population_hpp
#define _population_hpp

#include <assert.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <math.h>
#include "param.hpp"
#include "chromosome.hpp"
#include "selection.hpp" // TO ADD
#include "crossover.hpp" // TO ADD
#include "gene.hpp"
#include "alea.hpp"
#include "utils.hpp"   

class Selection;

extern param *para;
extern alea RANDOM;

class population {
    protected:
        int        Pop_taille;          // taille population size
        chromosome *Chromosomes;        // Chromosomes constituant la population
        int        *MatingPool;         // Generation intermediaire
        
        int        Best, Worst;         // index pour le meilleur Chromosome
        double     MaxFit;              // maximum fitness
        double     MinFit;              // minimum fitness
        double     MoyFit;              // moyenne fitness    

        int        tournoi_gagnant ( int *melangetab, int &pick, int s );
        Selection *Selectionner;           // 
        Crossover *croiser;
        gene *genes;

    public:
        population( int Pop_taille );
        population( population &pop );
        ~population();
        void random();
        void init(std::ifstream &in1);
        void selection( population *npop );   
        void selectionnement( population *npop );
        void croisement(void);
        void mutate(void);
        void evaluer();   
        void statistique(); 
        int pop_taille(){ return Pop_taille; }
        int best() { return Best; }
        int worst() { return Worst; }
        double maxfit() { return MaxFit; }
        double minfit() { return MinFit; }
        double moyfit() { return MoyFit; }
        inline double donnefitness(const int index) const {return Chromosomes[index].fitness();}
        chromosome & operator[]( int index );
        population & operator=( population &pop );
        friend std::ostream &operator<< ( std::ostream &out, population &pop );
        bool converge();
    
        //
        // selection des schemes
        // 
        friend void tselect_sans_remplacement( population &pop );  
        
        //
        // arrêter les critères
        //
        friend bool critere_maxgen( population &pop, int gen );
        friend bool critere_n_meme_chrom( population &pop, int gen );
};

#endif
