#include "../include/crossover.hpp"


crossover1_2point::crossover1_2point( int nbrCrossover ) {
    pointCrossover = nbrCrossover;
}

void crossover1_2point::croiser( chromosome &pere, chromosome &mere ) {
    int pt1, temp;
    chromosome enfant1, enfant2;

    pt1 = RANDOM.uniform(0, para->lchrom - 1);
    enfant1 = pere;
    enfant2 = mere;

    for ( int i = pointCrossover; i < para->lchrom; i++ ) {
        temp = enfant1.get_genes()[i].allele();
        enfant1.set_valeur(i, enfant2.get_genes()[i].allele());
        enfant2.set_valeur(i, temp);
    }
}
