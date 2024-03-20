#include "fichier.hpp"

//extern alea RANDOM;

// returner l'identificateur du critère d'arrêt(60,61). returner -1 s'il n'est pas trouvé.
int trouve_critere_fin( char *s )
{
  if( strcmp( s, "ncopi_memeindividu" ) == 0 ) return ncopi_memeindividu;
  if( strcmp( s, "MAX_GENERATIONS" ) == 0 ) return MAX_GENERATIONS;
  return -1;
}

Type_Selection trans_selc(int rsel) {
    switch (rsel) {
        case 1 : return RouletteBiase ; break;
        case 2 : return SUS  ;break;    
        case 3:  return Tournoi  ;break ;   
        case 4: return Tournoi2 ;break ;   
        case 5: return Truncation ;break;    
        case 6: return RangLineaire; break;
        case 7: return Rangexp; break; 
        default: exit(0);
    } 
}

Type_croisement trans_cross(int rcros) {
    switch (rcros) {
        case 1 : return unPoint ; break;
        case 2 : return deuxPoint  ;break;    
        case 3:  return uniforme  ;break ;   
        case 4: return SBCrossover ;break ; 
        default: exit(0);
    } 
}

Type_Mutation trans_mut(int rmut) {
    switch (rmut) {
        case 1 : return unBit ; break;
        case 2 : return aletoire  ;break;    
        case 3:  return hamming  ;break;   
        default: exit(0);
    }
}

// 
// lire les paramétres du fichier d'entrée.
// 
void lire_parametres( std::ifstream &in, int &lc, double &b, int &pt, double &pc, int &tt, double &p_s, int &tselc, int &tcrois, int &tmuta, int &sc, double &sca, unsigned int &to, int &fo, unsigned int &re, bool &rp, bool &rs, bool &rf ) {
    //const int unset = -1;
    int op;
    char  s[200] = "";
    char  s2[200] = "";

    while( strcmp( s, "DEBUT" ) != 0 ) {
        in.getline( s, 200 );
        std::cout << s << std::endl;
    }

    in >> s >> lc;
    std::cout << s << "   " << lc << std::endl; 
    erreurcocher("choisir longueur du chromosome.", lc > 0 );

    in >> s >> b;
    std::cout << s << "   "  << b << std::endl;
    erreurcocher("badra doit être  0..1", b > 0 && b < 1 );

    in >> s >> pt;
    std::cout << s << "   "  << pt << std::endl;
    erreurcocher("taille de population doit être.", pt % 2 == 0 );
    erreurcocher("taille de population est positive.", pt > 0 );

    in >> s >> pc;
    std::cout << s << "   "  << pc << std::endl;
    erreurcocher("pcross doit être entre 0..1", pc >= 0 && pc <= 1 );

    in >> s >> tt;
    std::cout << s << "   "  << tt << std::endl;
    erreurcocher("la taille du tournoi", tt >= 0 && tt <= 16 );
    
    in >> s >> p_s;
    std::cout << s << "   "  << p_s << std::endl;
    erreurcocher("la pression du selection de remplacement", p_s >= 0 && p_s <= 1 );

    in >> s >> tselc;
    std::cout << s << "   "  << tselc << std::endl;
    erreurcocher("la selction est un nombre entre 1 et 7", tselc >= 1 && tselc <= 7 );
    
    in >> s >> tcrois;
    std::cout << s << "   "  << tcrois << std::endl;
    erreurcocher("le croisement est un nombre entre 1 et 5", tcrois >= 1 && tcrois <= 5 );

    in >> s >> tmuta;
    std::cout << s << "   "  << tmuta << std::endl;
    erreurcocher("la mutation est un nombre entre 1 et 3", tmuta >= 1 && tmuta <= 3 );

    in >> s >> s2; op = trouve_critere_fin( s2 );
    
    std::cout << s << "   "  << s2 << std::endl;
    sc = op;
    erreurcocher("critère n'est pas valable.", op != -1 );

    in >> s >> sca;
    std::cout << s << "   "  << sca << std::endl;

    in >> s >> to;
    std::cout << s << "   "  << to << std::endl;
    
    erreurcocher("Maximisation:1 Minimisation:0", to <= 1 );

    in >> s >> fo;
    std::cout << s << "   "  << fo << std::endl;
    
    erreurcocher("fonction de test 1..12 ", fo >= 1 && fo <= 12);
    in >> s >> re;
    std::cout << s << "   "  << re << std::endl;
    
    erreurcocher("1:remplacement avec pourcentage 0:remplacement avec Ellitiste ", re <= 1 );
    
    in.getline( s, 100 );

    in.getline( s, 100 );
    in.getline( s, 100 );
    in.getline( s, 100 );

    in >> s >> s2;
    rp = (strcmp(s2,"oui") == 0); 
    std::cout << s << "   "  << s2 << std::endl;
    in >> s >> s2;
    rs = (strcmp(s2,"oui") == 0);
    std::cout << s << "   "  << s2 << std::endl;
    in >> s >> s2; 
    rf = (strcmp(s2,"oui") == 0);
    std::cout << s << "   "  << s2 << std::endl;
    in >> s >> s2;

    std::cout << "**************************************************************************" << std::endl;
} 
/*
int main( int argc, char *argv[] )
{

 


  int tselc=1,tcrois=1,tmuta=1;
  // vérifier la commande en entrée du programme
  if( argc != 2 )   
    {
      std::cout << "Utilisation: " << argv[0] << " fichier_entrée fichier_sortie" << std::endl;
      std::cout << "       SVP lire le fichier lisezmoi." << std::endl;
      exit(1);
    }
  
  // lire les paramétres du fichier d'entrée
  std::ifstream infile( argv[1] ); 


  lire_parametres( infile,Para.lchrom,param::badra,Para.pop_taille,Para.pcross,Para.taille_tournoi,
Para.pression_selection,Para.type_selection,Para.type_croisement,Para.type_Mutation,
Para.stop_critere ,Para.stop_critere_arg,Para.rapport_pop,Para.rapport_string,
Para.rapport_fitness );

  infile.close();
std::cout <<"...badre......."<<(param::pression_selection)<< std::endl;
std::cout <<"...badre......."<<(param::badra)<< std::endl;

}
*/   




