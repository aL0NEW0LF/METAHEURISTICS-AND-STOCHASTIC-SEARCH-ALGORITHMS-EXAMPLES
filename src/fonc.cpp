#include "../include/fonc.hpp"


//------------------------------------------------------------


//  returner le nombre des '1'
int unitation( char *chrom, int debutBit, int finBit ) {
    int ones = 0;

    for( int i = debutBit; i <= finBit; i++ )
        if( chrom[i] == '1' ) ones++;

    return ones;
}


//  fonction de Harrik
double trap( int k, int ones ) {
    if( ones == 0 ) 
        return k + 1;
    else 
        return ones;
}


//
// 
// Changer cette fonction pour essayer d'autres problèmes
//

long double objective_fonc( char *chrom, int lchrom ) {
    switch (para->fonction_test) {
        case 1: return objective_Mich1( chrom, lchrom ); break;
        case 2: return objective_Mich2( chrom, lchrom ); break;    
        case 3: return objective_Shubert( chrom, lchrom ); break;  
        case 4: return objective_Rastrigin( chrom, lchrom ); break;   
        case 5: return objective_De_Jong2( chrom, lchrom ); break; 
        case 6: return objective_Schwefel( chrom, lchrom ); break;    
        case 7: return objective_Mexican_Hat( chrom, lchrom ); break; 
        case 8: return objective_Modal1( chrom, lchrom ); break; 
        case 9: return objective_AB1( chrom, lchrom ); break; 
        case 10: return objective_AB2( chrom, lchrom ); break; 
        case 11: return objective_AB3( chrom, lchrom ); break;    
        case 12: return objective_AB4( chrom, lchrom ); break;              
        default: exit(0);
    } 
}

//f(x)= x*sin(10*π*x)+1
// avec -1<x<2
long double objective_Mich1( char *chrom, int lchrom ) {
    long x, y, accum1;
    int i, j, l1, l2;
    char *str1;
    char *str2;
    long double X, Y, X1, X2, Y1, Y2, X11, X22, accum = 0.0;
    unsigned int w;

    X1=decode(chrom, lchrom);

    X=3.0/(pow(2.0,22.0)-1.0);
    Y= -1.0 + X*X1; 
    
    accum= (long double)1.0+Y* sin(10.0 * 3.14159L * Y);

    return accum;
}

//fonction f(x1,x2)=21.5 + X11*sin(4*M_PI*X11) + X22*sin(20*M_PI*X22)
// avec -3.0 < x1 < 12.1 and 4.1 < x2 < 5.8. 
long double objective_Mich2( char *chrom, int lchrom ) {
    long x, y, accum1;
    int i, j, l1, l2;
    char *str1;
    char *str2;
    long double X, Y, X1, X2, Y1, Y2, X11, X22, accum = 0.0;
    unsigned int w;

    l1 = lchrom+1-int(lchrom/2);
    l2 = int(lchrom/2)-1;

    str1 = new char[l1];
    str2 = new char[l2];

    for (i = 0;i < l1;i++)
        str1[i] = chrom[i];

    for (i = 0;i < l2;i++)
        str2[i] = chrom[i + l1];

    X1 = decode(str1,l1);

    X2 = decode(str2,l2);
    //fonction f(x1,x2) = 21.5 + X11*sin(4*M_PI*X11) + X22*sin(20*M_PI*X22)
    // avec -3.0 < x1 < 12.1 and 4.1 < x2 < 5.8.
    X = 15.0 / (pow(2.0,18.0) - 1.0);
    Y = 1.7 / (pow(2.0,15.0) - 1.0);
    X11 = -3.0+X1*X;
    X22 = 4.1+X2*Y;
    accum = (long double)21.5 + X11 * sin(4 * M_PI * X11) + X22 * sin(20 * M_PI * X22);
    delete [] str1;
    delete [] str2;
    
    return accum;
}

// Shubert fonction 
//f(x1,x2)=(som1,5(i*cos((i+1)*x1+i))*som1,5(i*cos((i+1)*x2+i))
long double objective_Shubert( char *chrom, int lchrom ) {
    long x, y, accum1;
    int i, j, l1, l2;
    char *str1;
    char *str2;
    long double X, Y, X1, X2, Y1, Y2, X11, X22, accum = 0.0;
    unsigned int w;

    l1 = lchrom - int(lchrom / 2);
    l2 = int(lchrom / 2);

    str1 = new char[l1];
    str2 = new char[l2];

    for (i = 0;i < l1;i++)
        str1[i] = chrom[i];

    for (i = 0;i < l2;i++)
        str2[i] = chrom[i + l1];

    X1 = decode(str1,l1);

    X2 = decode(str2,l2);

    X = 20.0/(pow(2.0,25.0)-1.0);
    Y = 20.0/(pow(2.0,25.0)-1.0);
    X11 = -10.0 + X1 * X;
    X22 = -10.0+ X2 * X;
    
    accum = (long double)shub(X11,X22);
    
    delete [] str1;
    delete [] str2;
    
    return accum;
}
//Rastrigin fonction
//f(x1,x2)=10.0*n+pow(x1,2)-10*cos(2.0*M_PI*x1)+0*n+pow(x2,2)-10*cos(2.0*M_PI*x2)

long double objective_Rastrigin( char *chrom, int lchrom ) {
    long x, y, accum1;
    int i, j, l1, l2;
    char *str1;
    char *str2;
    long double X, Y, X1, X2, Y1, Y2, X11, X22, accum = 0.0;
    unsigned int w;

    l1 = lchrom - int(lchrom / 2);
    l2 = int(lchrom / 2);

    str1 = new char[l1];
    str2 = new char[l2];

    for (i = 0;i < l1;i++)
        str1[i] = chrom[i];



    for (i = 0;i < l2;i++)
        str2[i] = chrom[i + l1];



    X1 = decode(str1,l1);

    X2 = decode(str2,l2);
    X = 10.24/(pow(2.0,24.0)-1.0);
    Y = 10.24/(pow(2.0,24.0)-1.0);
    X11 = -5.12+X1*X;
    X22 = -5.12+X2*X;
    accum = (long double)rast(X11,X22);
    delete [] str1;
    delete [] str2;
    
    return accum;
}

/* Source:      Shekel's Foxholes problem from De Jong's Diss.(1975)         */
/*              'GA in multimodal function optimazation' Masters thesis      */
/* Boundaries:  -60 < x < 60                                                 */
/*              -60 < y < 60                                                 */
/*		TCGA Rep. 89002 / U. of Alabama                              */
/*****************************************************************************/

long double objective_De_Jong2( char *chrom, int lchrom ) {
    long x, y, accum1;
    int i, j, l1, l2;
    char *str1;
    char *str2;
    long double X, Y, X1, X2, Y1, Y2, X11, X22, accum = 0.0;
    unsigned int w;

    l1 = lchrom - int(lchrom / 2);
    l2 = int(lchrom / 2);

    str1 = new char[l1];
    str2 = new char[l2];

    for (i = 0;i < l1;i++)
        str1[i] = chrom[i];

    for (i = 0;i < l2;i++)
        str2[i] = chrom[i + l1];



    X1 = decode(str1,l1);

    X2 = decode(str2,l2);
    X = 120.0/(pow(2.0,27.0)-1.0);
    Y = 120.0/(pow(2.0,27.0)-1.0);
    X11 = -60.0+X1*X;
    X22 = -60.0+X2*X;
    accum = (long double)De_Jong2(X11,X22);
    delete [] str1;
    delete [] str2;
    
    return accum;
}

/* Boundaries:  -500 < x < 500                                               */
/*              -500 < y < 500                                               */
/* Source:      Schwefel's function in Schoeneburg                           */
/*****************************************************************************/
long double objective_Schwefel( char *chrom, int lchrom ) {
    long x, y, accum1;
    int i, j, l1, l2;
    char *str1;
    char *str2;
    long double X, Y, X1, X2, Y1, Y2, X11, X22, accum = 0.0;
    unsigned int w;

    l1 = lchrom - int(lchrom / 2);
    l2 = int(lchrom / 2);

    str1 = new char[l1];
    str2 = new char[l2];

    for (i = 0;i < l1;i++)
        str1[i] = chrom[i];

    for (i = 0;i < l2;i++)
        str2[i] = chrom[i + l1];

    X1 = decode(str1,l1);

    X2 = decode(str2,l2);
    X = 1000.0/(pow(2.0,30.0)-1.0);
    Y = 1000.0/(pow(2.0,30.0)-1.0);
    X11 = -500.0+X1*X;
    X22 = -500.0+X2*X;
    accum = (long double)Schwefel(X11,X22);
    delete [] str1;
    delete [] str2;
    
    return accum;
}

/* Description: Mexican Hat                                                  */
/* Boundaries:  -10 < x < 10                                                 */
/*              -10 < y < 10                                                 */
/* Source:                                                                   */
/*****************************************************************************/


long double objective_Mexican_Hat( char *chrom, int lchrom ) {
    int i,j,l1,l2;
    char *str1;
    char *str2;
    long double X,Y,X1,X2,Y1,Y2,X11,X22,accum = 0.0;
    unsigned int w;

    l1 = lchrom - int(lchrom / 2);
    l2 = int(lchrom / 2);

    str1 = new char[l1];
    str2 = new char[l2];

    for (i = 0;i < l1;i++)
        str1[i] = chrom[i];

    for (i = 0;i < l2;i++)
        str2[i] = chrom[i + l1];

    X1 = decode(str1,l1);

    X2 = decode(str2,l2);
    X = 20.0/(pow(2.0,25.0)-1.0);
    Y = 20.0/(pow(2.0,25.0)-1.0);
    X11 = -10.0+X1*X;
    X22 = -10.0+X1*X;
    accum = (long double)Mexican_Hat(X11,X22);
    delete [] str1;
    delete [] str2;
    
    return accum;
}

// f(x) = exp(-2*log(2)*pow((x-0.1)/0.8,2)*pow(sin(5*M_PI*x),6)

long double objective_Modal1( char *chrom, int lchrom ) {
    char *str1;
    char *str2;
    long double X,Y,X1,X2,Y1,Y2,accum = 0.0;
    unsigned int w;

    X1 = decode(chrom, lchrom);
    X = 1.0/pow(2.0,25.0);
    std::cout<<X1<<std::endl;
    Y = X*X1; 
    accum = exp(-2 * log(2) * pow((Y - 0.1) / 0.8, 2)) * pow(sin(5 * M_PI * Y), 6);
    std::cout<<Y<<std::endl;
    accum = Y;
    return accum;
}

//f(x) =  pow(sin(10*M_PI*(pow(Y,0.75)),6.0)

long double objective_AB1( char *chrom, int lchrom ) {
    long x, y, accum1;
    int i, j, l1, l2;
    char *str1;
    char *str2;
    long double X, Y, X1, X2, Y1, Y2, X11, X22, accum = 0.0;
    unsigned int w;

    X1 = decode(chrom, lchrom);
   
    X = 1.0/(pow(2.0,22.0)-1.0);
    Y =   X*X1; 
    X22 = 0.75;
    X11 = pow(Y,X22);
  //std::cout << "<-----regardez ici----> !!!!!" <<Y<<std::endl;

    accum =  (long double)pow(sin(10 * M_PI * X11), 6.0L);
    return accum;
}

//exp(-2*log(2)*pow(Y-0.08/0.854,2))*pow(sin(10*M_PI*(pow(Y,0.75)),6.0);

long double objective_AB2( char *chrom, int lchrom ) {
    long x, y, accum1;
    int i, j, l1, l2;
    char *str1;
    char *str2;
    long double X, Y, X1, X2, Y1, Y2, X11, X22, accum = 0.0;
    unsigned int w;

    X1 = decode(chrom, lchrom);

    X = 1.0 / (pow(2.0,22.0) - 1.0);
    Y =   X*X1; 
    X22 = 0.75L;
    X11 = pow(Y,X22);
    X22 = (long double)pow(sin(10 * M_PI * X11), 6.0L);
    
    accum =  (long double)exp(-2 * log(2) * pow(Y - 0.08L / 0.854L, 2.0L)) * X22;
    return accum;
}

// fonction trompeuse

long double objective_AB3( char *chrom, int lchrom ) {
    long x, y, accum1;
    int i, j, l1, l2;
    char *str1;
    char *str2;
    long double X, Y, X1, X2, Y1, Y2, X11, X22, accum = 0.0;
    unsigned int w;

    X1 = decode(chrom, lchrom);

    X = 6.0 / (pow(2.0,23.0) - 1.0);
    Y =   X * X1; 

    accum =  (long double)AB3(Y);
    return accum;
}

long double objective_AB4( char *chrom, int lchrom ) {
    int i, j, l1, l2;
    char *str1;
    char *str2;
    long double X, Y, X1, X2, Y1, Y2, X11, X22, accum = 0.0;
    unsigned int w;

    l1 = lchrom - int(lchrom / 2);
    l2 = int(lchrom / 2);

    str1 = new char[l1];
    str2 = new char[l2];

    for (i = 0;i < l1;i++)
        str1[i] = chrom[i];

    for (i = 0;i < l2;i++)
        str2[i] = chrom[i + l1];

    X1 = decode(str1,l1);
    X2 = decode(str2,l2);

    X = 6.0 / (pow(2.0,10.0) - 1.0);
    Y = 6.0 / (pow(2.0,10.0) - 1.0);
    X11 = X1 * X;
    X22 = X1 * X;
    accum = (long double)200.0L - pow((X11 * X11 + X22 - 11.0L), 2.0L) - pow((X22 * X22 + X11 - 7.0L), 2.0L);
    delete [] str1;
    delete [] str2;
    
    return accum;
}     
