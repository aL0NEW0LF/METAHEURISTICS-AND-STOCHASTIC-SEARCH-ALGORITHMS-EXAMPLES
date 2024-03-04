#ifndef _fonc_hpp_
#define _fonc_hpp_

#define _USE_MATH_DEFINES

#include "./chromosome.hpp"
#include "./param.hpp"
#include "./utils.hpp"
//#include "./codage.hpp"
#include <math.h>
#include <cmath>
#include <stdio.h>

extern param *para;
using namespace std;

int unitation( char *chrom, int debutBit, int finBit );
double trap( int k, int ones );
long double objective_fonc( char *chrom, int lchrom );
long double objective_Mich1( char *chrom, int lchrom );
long double objective_Mich2( char *chrom, int lchrom );
long double objective_Shubert( char *chrom, int lchrom );
long double objective_Rastrigin( char *chrom, int lchrom );
long double objective_De_Jong2( char *chrom, int lchrom );
long double objective_Schwefel( char *chrom, int lchrom );
long double objective_Mexican_Hat( char *chrom, int lchrom );
long double objective_Modal1( char *chrom, int lchrom );
long double objective_AB1( char *chrom, int lchrom );
long double objective_AB2( char *chrom, int lchrom );
long double objective_AB3( char *chrom, int lchrom );
long double objective_AB4( char *chrom, int lchrom );

#endif