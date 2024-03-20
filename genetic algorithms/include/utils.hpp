#ifndef _utils_hpp
#define _utils_hpp

#define permuter(A,B)    (A^=B^=A^=B) 

#define _USE_MATH_DEFINES

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include "param.hpp"
#include "alea.hpp"
#include "chromosome.hpp"

extern alea RANDOM;

int     hamming_distance(chromosome &C1, chromosome &C2);

// PROF's UTILS (MIGHT BE REFACTORED/DELETED LATER)
void    erreur( char *msg );
void    erreurcocher( char *str, bool condition );
double  sqr( double x );
double  min( double x );
int     min( int x, int y );
int     max( int x, int y );
double  max( double x, double y);
double  min( double x, double y);
long    decode( char *str, int lbits );
void    encode( int x, int nbits, char *str );
double  log( double x, double b );
void    mergeSort( int *A, int sizeA, int *B, int sizeB, int *C );
void    se_melange( int *tabmelange, const int n );
void    permutation(int& ii, int& jj);
double  shub(double x1,double x2);
double  rast(double x1,double x2);
double  De_Jong2(double x, double y);
double  Schwefel(double x, double y);
double  Mexican_Hat(double x, double y);
double  AB3(double x);

#endif