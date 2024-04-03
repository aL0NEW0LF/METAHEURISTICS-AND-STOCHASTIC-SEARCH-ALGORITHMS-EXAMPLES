#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include<cmath>
#include <climits>
#include <random>

using namespace std;

const int villes = 5;
const int maxIter = 5;
const int Ltabu = 10;

double tour_distance(const vector<int>& tour, const vector<vector<int>>& matrice) {
    double total_distance = 0.0;
    
    for (int i = 0; i < villes - 1; i++) {
        total_distance += matrice[tour[i]] [tour[i+1]];
    }

    total_distance += matrice[tour[villes - 1]][tour[0]]; // Return to starting city

    return total_distance;
}

vector<int> Ginitial() {
    random_device rd;
    mt19937 gen(rd());
    vector<int> tour(villes);

    for (int i = 0; i < villes; i++) {
        tour[i] = i;
    }

    shuffle(tour.begin(), tour.end(),gen); // Random permutation
    
    return tour;
}

vector<vector<int>> echange(const vector<int>& solution) {
    vector<vector<int>> AllMove;vector<int> neighbor;
    
    for (int i = 0; i < villes - 1; i++) {
        for (int j = i + 1; j < villes; j++) {
            neighbor = solution;
            swap(neighbor[i], neighbor[j]); // Swap two cities
            AllMove.push_back(neighbor);
        }
    }

    return AllMove;
}

vector<vector<int>> deplace(const vector<int>& solution) {
    vector<vector<int>> AllMove;
    
    for (int i = 0; i < villes - 1; i++) {
        for (int j = i + 1; j < villes-1; j++) {
            vector<int> neighbor = solution;
            swap(neighbor[i], neighbor[j]); // Swap two cities
            swap(neighbor[i], neighbor[j+1]);
            AllMove.push_back(neighbor);
        }
    }

    return AllMove;
}

vector<vector<int>> inversion(const vector<int>& solution) {
    vector<vector<int>> AllMove;
    
    for (int i = 0; i < villes - 1; i++) {
        vector<int> neighbor = solution;
        swap(neighbor[i], neighbor[i+1]); // Swap two cities
        AllMove.push_back(neighbor);
    }

    return AllMove;
}

vector<int> tabu_search(const vector<vector<int>>& matrice) {
    srand(time(NULL)); // Seed
    vector<int> courante= Ginitial();
    cout<<"s0= ";
    for(int i=0;i<courante.size();i++)cout<<courante[i]<<" ";
   cout<<"fitness0= "<< tour_distance(courante, matrice)<<endl;

    vector<int> best =courante;


    vector<vector<int>> tabu_list;


    for (int iter = 0; iter < maxIter; iter++) {
        // Generate AllMove solutions
        vector<vector<int>> AllMove = echange(courante);

        // Find the best neighbor not in the tabu list
        double min_distance = INT_MAX;
        vector<int> next_solution;
        
        for (const auto& neighbor : AllMove) {
            if (find(tabu_list.begin(), tabu_list.end(), neighbor) == tabu_list.end()) {
                double dist = tour_distance(neighbor, matrice);
                cout<<"iteration: "<<iter<<" ....   ";
                for(int i=0;i<neighbor.size();i++) cout<<neighbor[i]<<" "; cout<<"fitness= "<<dist<<endl;

                if (dist < min_distance) {
                    min_distance = dist;
                    next_solution = neighbor;
                }
            }
        }

        courante= next_solution;

        // MAJ best solution
        if (tour_distance(courante, matrice) < tour_distance(best, matrice)) {
            best = courante;
            for(int i=0;i<best.size();i++) cout<<best[i]<<" "; cout<<"fitness_best= "<<tour_distance(best, matrice)<<endl;
        }

        // MAJ tabu list
        tabu_list.push_back(courante);

        if (tabu_list.size() >Ltabu) {
            tabu_list.erase(tabu_list.begin());
        }
    }

    return best;
}

int main() {
    vector<int> row(villes, 0);
    vector<vector<int>> matrice(villes,row);

    matrice[0][1]=355; matrice[0][2]=70;matrice[0][3]=258;matrice[0][4]=240;
    matrice[1][2]=280;matrice[1][3]=88;matrice[1][4]=600;
    matrice[2][3]=160;matrice[2][4]=310;
    matrice[3][4]=310;

    for (int i = 0; i < villes; i++) {
        matrice[i][i]=0;
    }

    for (int i = 0; i < villes; i++)
        for (int j = 0; j < villes; j++)
            matrice[j][i]=matrice[i][j];

    vector<int> best_tour = tabu_search(matrice);

    cout << "Best tour: ";
    for(int i;i<villes;i++) {
        switch (best_tour[i]) {
            case 0: cout << "Casablanca" << " ";break;
            case 1:  cout << "Tanger" << " ";break;
            case 2: cout << "Rabat" << " ";break;
            case 3: cout << "Larache" << " ";break;
            case 4: cout << "Marrakech" << " ";break;
        }
    }

    cout << endl;

    for (int city : best_tour) {
       cout << city << " ";
    }

    cout << endl;
    cout << "Total distance: " << tour_distance(best_tour, matrice) << endl;

    return 0;
}
