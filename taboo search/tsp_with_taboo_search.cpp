#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<ctime>
#include<random>

#define ville 5

std::vector<int> ginitial(){
    std::vector<int> x;
    for(int i = 0; i < ville; i++)
        x.push_back(i);
    std::random_shuffle(x.begin(), x.end());
    return x;
}

std::vector<std::vector<int>> echange(std::vector<int> x){
    std::vector<int> neighbor = x;
    std::vector<std::vector<int>> all_moves;
    for(int i = 0; i < ville-1; i++){
        for(int j = i+1; j < ville; j++){
            neighbor = x;
            std::swap(neighbor[i], neighbor[j]);
            all_moves.push_back(neighbor);
        }
    }
    return all_moves;
}

std::vector<std::vector<int>> inversion(std::vector<int> x){
    std::vector<int> neighbor = x;
    std::vector<std::vector<int>> all_moves;
    for(int i = 0; i < ville; i++){
        neighbor = x;
        std::swap(neighbor[i], neighbor[i+1]);
        all_moves.push_back(neighbor);
    }
    return all_moves;
}

template <typename t> void move(std::vector<t>& v, size_t oldIndex, size_t newIndex) {
    if (oldIndex > newIndex)
        std::rotate(v.rend() - oldIndex - 1, v.rend() - oldIndex, v.rend() - newIndex);
    else        
        std::rotate(v.begin() + oldIndex, v.begin() + oldIndex + 1, v.begin() + newIndex + 1);
}

std::vector<std::vector<int>> deplacement(std::vector<int> x){
    std::vector<int> neighbor = x;
    std::vector<std::vector<int>> all_moves;
    
    for(int i = 0; i < ville-1; i++){
        for(int j=i+1; j < ville; j++){
            neighbor = x;
            move(neighbor, i, j);
            all_moves.push_back(neighbor);
        }
    }

    return all_moves;
}