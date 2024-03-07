#include "../include/population.hpp"

param *para;
alea RANDOM;

population::population( int Pop_taille ) {
    this->Pop_taille = Pop_taille;
    Chromosomes = new chromosome[para->lchrom];
    MatingPool = new int[Pop_taille];
    Selectionner = new Selection();
    croiser = new Crossover();
    genes = new gene[para->lgenome];
}

population::population( population &pop ) {
    Pop_taille = pop.Pop_taille;
    Chromosomes = new chromosome[Pop_taille];
    MatingPool = new int[Pop_taille];
    Selectionner = new Selection();
    croiser = new Crossover();
    genes = new gene[para->lgenome];
    for ( int i = 0; i < Pop_taille; i++ ) {
        Chromosomes[i] = pop.Chromosomes[i];
    }
}

population::~population() {
    delete[] Chromosomes;
    delete[] MatingPool;
    delete Selectionner;
    delete croiser;
    delete[] genes;
}

void population::random() {
    for ( int i = 0; i < Pop_taille; i++ ) {
        Chromosomes[i].random();
    }
}

void population::init(std::ifstream &in1) {
}

void population::selection( population *npop ) {
    Selectionner->selection( this, npop );
}

void population::selectionnement( population *npop ) {
    Selectionner->selectionnement( this, npop );
}

void population::croisement() {
    croiser->croisement( this );
}

void population::mutate() {
    for ( int i = 0; i < Pop_taille; i++ ) {
        Chromosomes[i].mutate();
    }
}

void population::evaluer() {
    for ( int i = 0; i < Pop_taille; i++ ) {
        Chromosomes[i].evaluer();
    }
}

void population::statistique() {
    Best = 0;
    Worst = 0;
    MaxFit = Chromosomes[0].fitness();
    MinFit = Chromosomes[0].fitness();
    MoyFit = 0;
    for ( int i = 0; i < Pop_taille; i++ ) {
        MoyFit += Chromosomes[i].fitness();
        if ( Chromosomes[i].fitness() > MaxFit ) {
            MaxFit = Chromosomes[i].fitness();
            Best = i;
        }
        if ( Chromosomes[i].fitness() < MinFit ) {
            MinFit = Chromosomes[i].fitness();
            Worst = i;
        }
    }
    MoyFit /= Pop_taille;
}

chromosome & population::operator[]( int index ) {
    assert( index >= 0 && index < Pop_taille );
    return Chromosomes[index];
}

population & population::operator=( population &pop ) {
    Pop_taille = pop.Pop_taille;
    delete[] Chromosomes;
    delete[] MatingPool;
    delete Selectionner;
    delete croiser;
    delete[] genes;
    Chromosomes = new chromosome[Pop_taille];
    MatingPool = new int[Pop_taille];
    Selectionner = new Selection();
    croiser = new Crossover();
    genes = new gene[para->lgenome];
    for ( int i = 0; i < Pop_taille; i++ ) {
        Chromosomes[i] = pop.Chromosomes[i];
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, population &pop) {
    for ( int i = 0; i < pop.Pop_taille; i++ ) {
        out << pop.Chromosomes[i] << std::endl;
    }
    return out;
}

bool population::converge() {
    return ( Chromosomes[Best].fitness() - Chromosomes[Worst].fitness() < para->frm_fit );
}
