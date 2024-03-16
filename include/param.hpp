
#ifndef _param_hpp
#define _param_hpp

#define atome 1.0E-10

enum Type_Optim {Minimization, Maximization};
enum Type_Selection {Tournoi, SUS, Truncation, RouletteBiase, Tournoi2, RangLineaire, Rangexp};
enum Type_croisement {unPoint, deuxPoint, uniforme, SBCrossover,deterministicCrowding};
enum Type_Mutation {unBit, aletoire, hamming};

class param {
    public:
        double badra;              // badra pour generation d'un nombre aléatoire
        int    lchrom;            // longueur chromosome 
        int    pop_taille;           // taille population 
        double pcross;
        double pression_selection;            // probabilité de crossover
        double remplacement_pourc;  // pourcentage de remplcacement
        // static int    tournament_taille;   // taille tournament
        double Proba_croisement;
        double proba_mutation; 
        int    stop_critere;     // arrêter le critère pour l'algorithme algorithm
        double stop_critere_arg; //  (ex: maxgens= x)
        int    taille_tournoi;
        char   *frm_chrom;
        bool   frm_stop;
        double frm_fit;
        bool   rapport_pop;
        bool   rapport_string;
        bool   rapport_fitness;
        int    type_selection;
        int    type_croisement;
        int    type_Mutation;
        int    Type_Optim;
        int    fonction_test;
        int    type_remplace;
    // ~param();
};


//
// définition des constantes pour arrêter le critère
//
const int ncopi_memeindividu          = 60;
const int MAX_GENERATIONS             = 61;


#endif