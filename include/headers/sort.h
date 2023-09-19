#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <string>
#include <vector>
#include "graphics.h"
using namespace std;

class Sorter {
    const string type;

    public:
        Sorter(const string & t) :type(t) {
            Graphics engine;
            engine.init();
            populate(vec);
        }

        virtual void sort() = 0;

        virtual ~Sorter() {}

    protected:
        vector<int> vec;

    private:
        void populate(vector<int> &vec);  
};

class SwapSorter : public Sorter {
    public:
        SwapSorter() : Sorter("SwapSorter") {}

        void sort();

        ~SwapSorter() {}
};

#endif