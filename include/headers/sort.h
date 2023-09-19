#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <string>
#include "graphics.h"
using namespace std;

class Sort {
    const string type;
    public:
        Sort(const string & t) :type(t) {}
        ~Sort() {}
};

#endif