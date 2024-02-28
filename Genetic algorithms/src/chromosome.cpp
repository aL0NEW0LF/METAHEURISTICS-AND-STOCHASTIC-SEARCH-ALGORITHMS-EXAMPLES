#include "../include/chromosome.hpp"

alea RANDOM;

chromosome::chromosome( int ell ) {
    Longueur = ell;
    genes = new gene[Longueur];
    Fitness = 0;
}

chromosome::chromosome( const chromosome &chrom ) {
    Longueur = chrom.Longueur;
    genes = new gene[Longueur];
    for ( int i = 0; i < Longueur; i++ ) {
        genes[i] = chrom.genes[i];
    }
    Fitness = chrom.Fitness;
}

/* evaluate function pseudocode, until we implemente the parameters class  */
/* void chromosome::evaluer() {
    if(para->type_option){
        Fitness = objfunc(*this);
    } else {
        Fitness = -objfonc(*this);
    }
} */

void chromosome::evaluer() {
    Fitness = 0;
    for ( int i = 0; i < Longueur; i++ ) {
        Fitness += genes[i].allele();
    }
}

void chromosome::random() {
    for ( int i = 0; i < Longueur; i++ ) {
        genes[i].random();
    }
}

void chromosome::init( std::ifstream &in1 ) {
    for ( int i = 0; i < Longueur; i++ ) {
        char bit;
        in1 >> bit;
        genes[i].init(bit);
    }
}

void chromosome::mutation( double pmut ) {
    for ( int i = 0; i < Longueur; i++ ) {
        if ( RANDOM.flip(pmut) ) {
            genes[i].mutation();
        }
    }
}

void chromosome::mutation1bit() {
    int i = RANDOM.uniform(0, Longueur - 1);
    genes[i].mutation();
}

void chromosome::hamming_mutation( double pmut ) {
    
}

void chromosome::bin2string( char *str ) {
    for ( int i = 0; i < Longueur; i++ ) {
        str[i] = genes[i].allele() + '0';
    }
    str[Longueur] = '\0';
}

void chromosome::copieGene( chromosome &C, int *locus, int n ) {
    for ( int i = 0; i < n; i++ ) {
        genes[locus[i]] = C.genes[locus[i]];
    }
}

chromosome & chromosome::operator=(const chromosome &chrom) {
    if ( this == &chrom ) {
        return *this;
    }
    Longueur = chrom.Longueur;
    delete[] genes;
    genes = new gene[Longueur];
    for ( int i = 0; i < Longueur; i++ ) {
        genes[i] = chrom.genes[i];
    }
    Fitness = chrom.Fitness;
    return *this;
}

std::ostream &operator<<(std::ostream &out, chromosome &chrom) {
    for ( int i = 0; i < chrom.Longueur; i++ ) {
        out << chrom.genes[i];
    }
    return out;
}