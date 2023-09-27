#include "sort.h"
#include <iostream>
#include <random>
using namespace std;

void Sorter::randomizeVector(vector<int> &v) {
    std::random_device rd;
    std::uniform_int_distribution d(1,99);
    for (int i=0; i<100; ++i)
        v.push_back(d(rd));
}

bool Sorter::sorted(vector<int> & v) {
    int len = v.size();
    for (int i=1; i<len; ++i)
        if (v[i-1] > v[i])
            return false;
    return true;
}

void NaiveSorter::sort(vector<int> &v) {
    int len = v.size();
    for (int i=0; i < len; ++i) {
        for (int j=i+1; j < len; ++j) {
            if (v[i] > v[j])
                std::swap(v[i], v[j]);
            app.visualize();
            //engine.delay(5);
        }
    }
    
}