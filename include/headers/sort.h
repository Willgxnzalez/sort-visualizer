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
            engine.init();
            populate(vec);
        }

        virtual void sort() = 0;

        bool sorted(vector<int> &vec);

        virtual ~Sorter() {}

    protected:
        vector<int> vec;
        Graphics engine;

    private:
        void populate(vector<int> &vec);  
};

class NaiveSorter : public Sorter {
    public:
        NaiveSorter() : Sorter("NaiveSorter") {}

        void sort();

        ~NaiveSorter() {}
};

#endif