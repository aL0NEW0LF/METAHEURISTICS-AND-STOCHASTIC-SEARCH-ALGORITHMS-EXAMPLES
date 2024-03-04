#include "../include/utils.hpp"

alea RANDOM;

// afficher le message erreur est arrêter le programme
void erreur( char *msg ) {
  std::cout << msg << std::endl;
  exit(1);
}

// si 'condition' est fausse, afficher un message d'erreur en  abondonnant le programme
void erreurcocher( char *str, bool condition ) {
  if( !condition ) {
        std::cout << "Erreur: " << str << std::endl;
        exit(1);
    }
}

double sqr( double x ) {
    return x * x;
}

int min( int x, int y ) {
    return(x < y ? x : y); 
}

double min( double x, double y) {
    return(x < y ? x : y); 
}

int max( int x, int y ) {
    return(x > y ? x : y); 
}

double max(double x, double y) {
    return(x > y ? x : y); 
}

// Decode les string comme entier binaire
long decode( char *str, int lbits ) {
    int j;
    long cumul, puiss2;

    cumul = 0; puiss2 = 1;
    for( j = lbits-1; j>= 0; j-- ){
        if( *(str+j)=='1' )
            cumul += puiss2;
        puiss2 *= 2;
    }

    return cumul;
}

// Encode x  comme entier binaire de 'nbits'
// ex: x=9, nbits=4  ===>  str="1001"
void encode( int x, int nbits, char *str ) {
    int i;
    for( i=0; i<nbits; i++ ) *(str+i) = '0';
    i = nbits-1;
    while( x != 0 && i >= 0 ) {
        if (x%2) * (str+i) = '1';
            x = x/2;
        i--;
    }
}
  
// returner log x de base b
double log( double x, double b ) {
    return log(x)/log(b); 
}


// C groupement de 2 tableau triés A et B.
//
void mergeSort( int *A, int sizeA, int *B, int sizeB, int *C ) {
    int sizeC = sizeA + sizeB;
    int a=0,b=0,c=0;

    while( c < sizeC ) {
        if( a >= sizeA || b >= sizeB ) 
            break;

        if( A[a] < B[b] ) {
            C[c] = A[a];
            a++;
        } else {
            C[c] = B[b];
            b++;
        }

        c++;
    }

    if( a >= sizeA )
        // copie de B
        for( int i=b; i< sizeB; i++ ) {
            C[c] = B[i];
            c++;
        }

    if( b >= sizeB )
        // copie de A
        for( int i=a; i< sizeA; i++ ) {
            C[c] = A[i];
            c++;
        }
}
  
// mettre n-permutation aléatoire des nombres 0,1,2,...,n-1
void se_melange( int *tabmelange, const int n ) {
    int i;

    // initialiser
    for( i=0; i<n; i++ ) 
        tabmelange[i] = i;
    // mélange
    for( i=0; i<n-1; i++ ) {
        int autre; 
        
        autre= RANDOM.uniform( i, n-1 );
        
        int temp = tabmelange[autre];
        tabmelange[autre] = tabmelange[i];
        tabmelange[i] = temp;
    }
}

bool paire(int num) {
    bool par;
    return((num % 2) == 0 ?1:0);
}

void permutation(int& i, int& j) {
    int temp;
    temp = j; j = i; i = temp;
}

double rast(double x1,double x2) {
    double s;
    int n;
    n=2;
    s=10.0*n+pow(x1,2)-10*cos(2.0*M_PI*x1)+0*n+pow(x2,2)-10*cos(2.0*M_PI*x2);
    return s;
}

double shub(double x1,double x2) {
    double s1, s2, s;
    s1 = s2 = 0;
    int n, i;

    for(i=1;i<6;i++) {
        s1 = s1 + i * cos((i+1.0) * x1 + i);
        s2 = s2 + i * cos((i+1.0) * x2 + i);
    }

    s=s1 * s2;

    return s;
}

/*****************************************************************************/
/* Type:        2D FUNCTION                                                  */
/* Name:        De_Jong2                                                     */
/* Description: Foxholes (25)                                                */
/* Boundaries:  -60 < x < 60                                                 */
/*              -60 < y < 60                                                 */
/* Source:      Shekel's Foxholes problem from De Jong's Diss.(1975)         */
/*              'GA in multimodal function optimazation' Masters thesis      */
/*		TCGA Rep. 89002 / U. of Alabama                                      */
/*****************************************************************************/
double De_Jong2(double x, double y) {
    int i;
    double ai[25], bi[25];

    for (i=0; i<25; i++) {
        ai[i] = 16 * ((i % 5) -2);
        bi[i] = 16 * ((i / 5) -2);
    }

    double sum = 0;
    
    for (i=0; i<25; i++) {
        sum += (1 / (1 + i + pow((x-ai[i]),6) + pow((y-bi[i]),6)));
    }

    double z = 100.0 - (1 / (0.02 + sum));
    
    return z;
}

/*****************************************************************************/
/* Type:        2D FUNCTION                                                  */
/* Name:        Schwefel                                                     */
/* Description: Schwefel's nasty (1 glob. Max bei (420.96/420.96)            */
/* Boundaries:  -500 < x < 500                                               */
/*              -500 < y < 500                                               */
/* Source:      Schwefel's function in Schoeneburg                           */
/*****************************************************************************/
double Schwefel(double x, double y) {
    //double z = fabs(x) * sin(sqrt(fabs(x))) + fabs(y) * sin(sqrt(fabs(y)));
    //double z = 100  *  ( sin(sqrt(fabs(x))) * sin(sqrt(fabs(y))) );
    double z = 837.9658 * sin(sqrt(fabs(x))) + fabs(y) * sin(sqrt(fabs(y)));
    return (z);
}

/*****************************************************************************/
/* Type:        2D FUNCTION                                                  */
/* Name:        Mexican_Hat                                                  */
/* Description: Mexican Hat                                                  */
/* Boundaries:  -10 < x < 10                                                 */
/*              -10 < y < 10                                                 */
/* Source:                                                                   */
/*****************************************************************************/
double Mexican_Hat(double x, double y) {
    double z = sin(sqrt(x*x + y*y))*sin(sqrt(x*x + y*y)) - 0.5;
    z /= ((1.0 + 0.001*(x*x + y*y))*(1.0 + 0.001*(x*x + y*y)));
    z = (0.5 - z);
    return (z);
}

/*****************************************************************************/
/* Type:        1D FUNCTION                                                  */
/* Name:        AB3                                                          */
/* Description: Mexican Hat                                                  */
/* Boundaries:  0 < x < 6                                                    */
/*                                                                           */
/* Source:                                                                   */
/*****************************************************************************/
double AB3(double x) {
    double accum;

    if((x<=1) && (x>=0))
        accum=1-x;
    else if((x<=3) && (x>=1))
        accum=0.3*(x-1);
    else if((x<=5) && (x>=3))
        accum=-0.3*(x-5);
    else if((x<=6) && (x>=5))
        accum=2*x-10;

    return accum;
}

int hamming_distance(chromosome &C1, chromosome &C2) {
    int distance = 0;
    for ( int i = 0; i < C1.longueur(); i++ ) {
        distance += C1.get_genes()[i].allele() ^ C2.get_genes()[i].allele();
    }

    return distance;
}