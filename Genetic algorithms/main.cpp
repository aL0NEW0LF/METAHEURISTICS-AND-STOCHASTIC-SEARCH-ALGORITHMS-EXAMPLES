#include <iostream>
#include <vector>
#include <random>
#include "./include/chromosome.hpp"

using namespace std;
 
int main()
{
    chromosome C1(50);
    chromosome C2(50);

    C1.random();
    C2.random();

    cout << "C1 = " << C1 << endl;
    cout << "C2 = " << C2 << endl;

    C1.evaluer();
    C2.evaluer();

    cout << "Fitness C1 = " << C1.fitness() << endl;
    cout << "Fitness C2 = " << C2.fitness() << endl;

    C1.mutation(0.1);
    C2.mutation(0.1);

    cout << "C1 = " << C1 << endl;
    cout << "C2 = " << C2 << endl;

    C1.evaluer();
    C2.evaluer();

    cout << "Fitness C1 = " << C1.fitness() << endl;
    cout << "Fitness C2 = " << C2.fitness() << endl;

    // bin2string test
    char str[51];
    C1.bin2string(str);
    cout << "C1 = " << str << endl;

    // init chromosome from another chromosome
    chromosome C3(C1);

    cout << "C3 = " << C3 << endl;
    
    return 0;
}
