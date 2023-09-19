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