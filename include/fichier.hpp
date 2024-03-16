#ifndef _fichier_hpp
#define _fichier_hpp

#include <assert.h>
#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "param.hpp"
#include "utils.hpp"     
#include "alea.hpp" 
#include "param.hpp"
//#include "gaitem.hpp"

//extern param Para; 
//extern alea RANDOM;
 
// returner l'identificateur du critère d'arrêt(60,61). returner -1 s'il n'est pas trouvé.
int trouve_critere_fin( char *s );
Type_Selection trans_selc(int rsel);
// 
// lire les paramétres du fichier d'entrée.
// 
void lire_parametres( std::ifstream &in,int &lc,double &b,int &pt,double &pc,int &tt,double  &p_s,int &tselc,int &tcrois,int &tmuta,int &sc,double &sca,unsigned int &to,int &fo,unsigned int &re,bool &rp,bool &rs,bool &rf );

#endif