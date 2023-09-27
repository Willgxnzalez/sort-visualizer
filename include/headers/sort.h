#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <string>
#include <vector>
#include "app.h"
using namespace std;

class Sorter {
    const string type;
    public:
        Sorter(const string & t, App &a) :type(t), app(a) {}
        virtual void sort(vector<int> &v) = 0;
        static bool sorted(vector<int> &v);
        static void randomizeVector(vector<int> &v); 
        virtual ~Sorter() {}

    protected:
        App &app;

};

class BubbleSorter : public Sorter {
    public:
        BubbleSorter(App &a) : Sorter("BubbleSorter", a) {}
        void sort(vector<int> &v);
        ~BubbleSorter() {}
};

class QuickSorter : public Sorter {
    public:
        QuickSorter(App &a) : Sorter("QuickSorter", a) {}
        void sort(vector<int> &v);
        ~QuickSorter() {}

    private:
        void quicksort(vector<int> &v, int low, int high);
        int medianOfThree(vector<int> &v, int low, int high);
        int partition(vector<int> &v, int low, int high);
};

#endif