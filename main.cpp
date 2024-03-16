#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "./include/chromosome.hpp"

using namespace std;

/*
Exercice 1:
Étant donné une chaîne source (donnée par l’utilisateur), le but est de produire une chaîne cible de même longueur à partir d'une chaîne aléatoire.
Exemple: “Master Intelligence Artificielle” l’AG va trouver une chaîne cible identique.
*/

// a) Choisir la taille de population=100, la définir comme constante
const int Pop_taille = 100;

// b) Définir une constante qui contient les différents Allèles (GENE Value)
const string Allèles = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 1234567890, .-;:_!\"#%&/()=?@${[]}";

int main()
{   
    /*
    Dans la fonction main()
    g) générer les nombres aléatoires à partir de de la fonction time(0)
    h)générer la population à partir de template vector
    i)utiliser la selection Elitism avec 10%
    j) pour le remplacement choisir 90%
    k) Afficher les résultats: Generation: string: fitness:
    */

    // g) générer les nombres aléatoires à partir de de la fonction time(0)
    srand(time(0));

    // h)générer la population à partir de template vector
    vector<chromosome> population;
    for (int i = 0; i < Pop_taille; i++) {
        population.push_back(random_chromosome());
    }

    // i)utiliser la selection Elitism avec 10%
    sort(population.begin(), population.end());

    // j) pour le remplacement choisir 90%
    for (int i = 0; i < Pop_taille * 0.9; i++) {
        population[i] = population[random(0, Pop_taille / 10)];
    }

    // k) Afficher les résultats: Generation: string: fitness:
    for (int i = 0; i < Pop_taille; i++) {
        cout << "Generation: " << i << " string: " << population[i].get_genes() << " fitness: " << population[i].get_fitness() << endl;
    }
    
    return 0;
}

// c) Créer une fonction qui returne un nombre aléatoire (de type int) entre 2 valeurs
int random(int a, int b) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(a, b);
    return distribution(generator);
}

// d)Donner une fonction qui retourne un gene d’une façon aléatoire en utilisant la question c)
gene random_gene() {
    gene g;
    g = Allèles[random(0, Allèles.size())];
    return g;
}

// e)Donner une fonction qui retourne un chromosome
chromosome random_chromosome() {
    chromosome c;
    for (int i = 0; i < Allèles.size(); i++) {
        c.get_genes()[i] = random_gene();
    }
    return c;
}

/*
f) Créer une classe individual contenant:
- 2 attributs: fitness (int) et chromosome(string)
- 1 constructeur :Individual(string chromosome)
- 1 methode qui produit un nouveau individual suivant:
    ◦si p<0.4 gene est inséré à partir de parent 1
    ◦sinon si p<0.9 gene est inséré à partir de parent 2
    ◦sinon gene est inséré d’une façon aléatoire
- 1 methode qui calcule la fitness si la valeur de gene est différente de la chaine choisie la fitness s’incrémente
- définir l’operator < qui compare deux individus
*/

class Individual {
    private:
        int fitness;
        string chromosome;
    public:
        Individual(string chromosome) {
            this->chromosome = chromosome;
            this->fitness = 0;
        }

        Individual crossover(Individual parent2) {
            Individual child = Individual("");
            double p;
            for (int i = 0; i < chromosome.size(); i++) {
                p = random(0, 100) / 100;
                if (p < 0.4) {
                    child.chromosome[i] = chromosome[i];
                } else if (p < 0.9) {
                    child.chromosome[i] = parent2.chromosome[i];
                } else {
                    child.chromosome[i] = Allèles[random(0, Allèles.size())];
                }
            }
            return child;
        }

        void calc_fitness(string target) {
            for (int i = 0; i < chromosome.size(); i++) {
                if (chromosome[i] != target[i]) {
                    fitness++;
                }
            }
        }

        bool operator < (const Individual &ind) {
            return fitness < ind.fitness;
        }
};

// Donner une fonction qui génére aléatoirement une permutation de n points
vector<int> random_permutation(int n) {
    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(i);
    }
    random_shuffle(v.begin(), v.end());
    return v;
}