#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <string>
#include <vector>
#include "app.h"
using namespace std;

class Sorter {
    public:
        Sorter(App &a) : app(a) {}
        virtual void sort(vector<int> &v) = 0;
        static bool isSorted(vector<int> &v);
        static void randomizeVector(vector<int> &v); 
        virtual ~Sorter() {}

    protected:
        App &app;

};

class BubbleSorter : public Sorter {
    public:
        BubbleSorter(App &a) : Sorter(a) {}
        void sort(vector<int> &v);
        ~BubbleSorter() {}
};

class QuickSorter : public Sorter {
    public:
        QuickSorter(App &a) : Sorter(a) {}
        void sort(vector<int> &v);
        ~QuickSorter() {}

    private:
        void quicksort(vector<int> &v, int low, int high);
        int medianOfThree(vector<int> &v, int low, int high);
        int partition(vector<int> &v, int low, int high);
};

class InsertionSorter : public Sorter {
    public:
        InsertionSorter(App &a) : Sorter(a) {}
        void sort(vector<int> &v);
        ~InsertionSorter() {}
};

class SelectionSorter : public Sorter {
    public:
        SelectionSorter(App &a) : Sorter(a) {}
        void sort(vector<int> &v);
        ~SelectionSorter() {}
};

class MergeSorter : public Sorter {
    public:
        MergeSorter(App &a) : Sorter(a) {}
        void sort(vector<int> &v);
        ~MergeSorter() {}
    private:
        void merge(vector<int> &v, int left, int mid, int right);
        void mergeSort(vector<int> &v, int left,int right);
};

#endif