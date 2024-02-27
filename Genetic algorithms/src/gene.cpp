#include "../include/gene.hpp"

// générer un allele aléatoire avec la fonction de Bernoulli
void gene::random( double prob ) { 
    if( RANDOM.flip( prob ) )
        Allele=1;
    else
        Allele=0;
}

void gene::init( char bit ) { 
    Allele = (bit =='1' ? 1 : 0);
}

// affiche le gene
std::ostream &operator<< (std::ostream &out, const gene &g) {
    out << g.Allele; 
    return out;
}

// assigner l'operateur = (pour gene entre eux
gene & gene::operator=(const gene &g) {
    if (this== &g) return *this;
        Allele = g.Allele;
    return *this;
}

// assigner l'operateur= (pour gene et int)
gene & gene::operator=(const int v) {
    Allele = v;
    return *this;
}

// mettre 0 à 1 ou 1 à 0.
void gene::mutation() {
    Allele = !Allele;
}
