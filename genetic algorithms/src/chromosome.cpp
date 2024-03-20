#include "../include/chromosome.hpp"

alea RANDOM;

chromosome::chromosome( int ell ) {
    Longueur = ell;
    genes = new gene[Longueur];
    Fitness = 0;
}

chromosome::chromosome( const chromosome &chrom ) {
    Longueur = chrom.Longueur;
    genes = new gene[Longueur];
    for ( int i = 0; i < Longueur; i++ ) {
        genes[i] = chrom.genes[i];
    }
    Fitness = chrom.Fitness;
}

long double chromosome::objfonc() {
    //
    // convertir chromosome en chaîne de caractères
    //
    char *str = new char [ Longueur ];
    bin2string( str );
            
    //  insertion de la fonction modifiee  
    long double v = objective_fonc( str, Longueur );
    delete [] str;
    return v;
}

void chromosome::evaluer() {
    if(para->Type_Optim){
        Fitness = objfonc();
    } else {
        Fitness = -objfonc();
    }
}

void chromosome::random() {
    for ( int i = 0; i < Longueur; i++ ) {
        genes[i].random();
    }
}

void chromosome::init( std::ifstream &in1 ) {
    int j,val;
    char  s[200] = "";

    in1.getline( s, 200 );
    for( j = 0; j< para->lchrom; j++ ) {  //strlen(s)
        //if (s[j] 
        genes[j].init(s[j]);
    }
        
    std::cout <<std::endl;
}

void chromosome::mutation( double pmut ) {
    for ( int i = 0; i < Longueur; i++ ) {
        if ( RANDOM.flip(pmut) ) {
            genes[i].mutation();
        }
    }
}

void chromosome::mutation1bit() {
    int i = RANDOM.uniform(0, Longueur - 1);
    genes[i].mutation();
}

void chromosome::hamming_mutation(double pmut) {
    int i, k, j, dham, l; 
    int *temp, *ham, *poly;
    int mini, maxi;
    mini = 0;
    maxi = para->lchrom;
    maxi--;
    k = RANDOM.uniform(mini, maxi) + 1;
    j = RANDOM.uniform(mini, maxi) + 1;
    dham = maxi-k;
    temp = new int[k];
    ham = new int[dham];
    poly = new int[j];

    for(i=mini;i<dham;i++)
        ham[i]=1;

    for(i=mini;i<k;i++) {        
        l=RANDOM.uniform(mini, maxi) + 1;
        j=RANDOM.uniform(mini, maxi) + 1;
        
        if (j>l) 
            poly[i]=0;
        else 
            poly[i]=1;
    }   

    for(i=0;i<=maxi;i++) 
        temp[i]=0;

    for(i=0;i<dham;i++) {
        j=int(pow(2,i));

        if (j<dham)
            temp[j] = ham[i];
    }

    for(i=0;i<maxi;i++) {
        if(!(temp[i])) 
            temp[i]=poly[i%k];
    }

    for (i=0;i<maxi;i++) {
        if (temp[i]) 
            genes[i].mutation();
    }
}

void chromosome::bin2string( char *str ) {
    for ( int i = 0; i < Longueur; i++ ) {
        str[i] = genes[i].allele() + '0';
    }
    str[Longueur] = '\0';
}

void chromosome::copieGene( chromosome &C, int *locus, int n ) {
    for ( int i = 0; i < n; i++ ) {
        genes[locus[i]] = C.genes[locus[i]];
    }
}

chromosome & chromosome::operator=(const chromosome &chrom) {
    if ( this == &chrom ) {
        return *this;
    }
    Longueur = chrom.Longueur;
    delete[] genes;
    genes = new gene[Longueur];
    for ( int i = 0; i < Longueur; i++ ) {
        genes[i] = chrom.genes[i];
    }
    Fitness = chrom.Fitness;
    return *this;
}

std::ostream &operator<<(std::ostream &out, chromosome &chrom) {
    for ( int i = 0; i < chrom.Longueur; i++ ) {
        out << chrom.genes[i];
    }
    return out;
}