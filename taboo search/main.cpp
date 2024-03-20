#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<ctime>
#include<random>
#define maxITER 100
#define LTabuList 10

double uniform_rand(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> d(0, 1);
    return d(gen);
}

double f1(std::vector<double> x) {
    double sum = 0;
    for (int i = 0; i < x.size()-1; i++) {
        sum += 100*pow(x[i+1]-pow(x[i],2), 2)+ pow(x[i]-1, 2);
    }
    return sum;
}

std::vector<double> generate(double upper, double lower,int dim){
    std::vector<double> x;
    double alpha = uniform_rand();
    for(int i = 0; i < dim; i++){
        x[i] = (lower + alpha * (upper - lower));
    }
    return x;
}

std::vector<double> gneighbor(std::vector<double> x){
    std::vector<double> neighbor = x;
    double alpha = uniform_rand();
    double epsilon = uniform_rand()/RAND_MAX;
    for(int i = 0; i < x.size(); i++){
        neighbor[i] += (2*epsilon-1)*alpha;
    }
    return neighbor;
}

std::vector<double> ts(int dim, double upper, double lower){
    std::vector<double> courants,best,neighbor;
    double fcourants,fbest,fneighbor;
    std::vector<std::vector<double>> tabulist;
    courants = generate(upper, lower, dim);
    best = courants;
    fcourants = f1(courants);
    fbest = f1(best);
    for(int i = 0; i < maxITER; i++){
        neighbor = gneighbor(courants);
        fneighbor = f1(neighbor);
        auto it = std::find(tabulist.begin(), tabulist.end(), neighbor);
        if(it != tabulist.end()){
            continue;
        }
        if(fneighbor < fcourants || i == 0){
            courants = neighbor;
            fcourants = fneighbor;
            if(fneighbor < fbest){
                best = neighbor;
                fbest = fneighbor;
            }
            tabulist.push_back(neighbor);
            if (tabulist.size() > LTabuList)    {
                tabulist.erase(tabulist.begin());
            }
        }
    }
    return best;
    
}

int main(){
    int dim = 2;
    double upper = 5.12;
    double lower = -5.12;
    std::vector<double> x = generate(upper, lower, dim);
    // std::cout<<x<<std::endl;
    std::cout<<f1(x)<<std::endl;
    return 0;
}