#include "sort.h"
#include <iostream>
#include <random>
using namespace std;

void Sorter::populate(vector<int> &vec) {
    std::random_device rd;
    std::uniform_int_distribution d(1,99);
    for (int i=0; i<100; ++i)
        vec.push_back(d(rd));
}

bool Sorter::sorted(vector<int> & vec) {
    int len = vec.size();
    for (int i=1; i<len; ++i)
        if (vec[i-1] > vec[i])
            return false;
    return true;
}

void NaiveSorter::sort() {
    for (int i=0; i < vec.size(); ++i) {
        for (int j=i+1; j < vec.size(); ++j)
            if (vec[i] > vec[j])
                std::swap(vec[i], vec[j]);
    }
    
}