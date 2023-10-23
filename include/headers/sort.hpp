#ifndef SORT_HPP
#define SORT_HPP

#include <vector>
#include <../SDL2/SDL.h>
#include "const.hpp"
using namespace std;

class Sorter {
    
    public:
        Sorter() : running(true) {}
        virtual void sort(vector<int> &v) = 0;
        static bool isSorted(vector<int> &v);
        static void randomizeVector(vector<int> &v); 
        void setRenderer(SDL_Renderer *r);
        void clear_screen();
        void visualize(vector<int> &v, int h1 = -1, int h2 = -1, int h3 = -1, bool complete = false);
        bool cancel_sort();
        virtual ~Sorter() {}

    protected:
        SDL_Renderer *ren;
        bool running;
};

class BubbleSorter : public Sorter {
    public:
        BubbleSorter() : Sorter() {}
        virtual void sort(vector<int> &v) override;
        ~BubbleSorter() {}
};

class QuickSorter : public Sorter {
    public:
        QuickSorter() : Sorter() {}
        virtual void sort(vector<int> &v) override;
        ~QuickSorter() {}
    private:
        void quicksort(vector<int> &v, int low, int high);
        int medianOfThree(vector<int> &v, int low, int high);
        int partition(vector<int> &v, int low, int high);
};

class InsertionSorter : public Sorter {
    public:
        InsertionSorter() : Sorter() {}
        virtual void sort(vector<int> &v) override;
        ~InsertionSorter() {}
};

class SelectionSorter : public Sorter {
    public:
        SelectionSorter() : Sorter() {}
        virtual void sort(vector<int> &v) override;
        ~SelectionSorter() {}
};

class MergeSorter : public Sorter {
    public:
        MergeSorter() : Sorter() {}
        virtual void sort(vector<int> &v) override;
        ~MergeSorter() {}
    private:
        void merge(vector<int> &v, int left, int mid, int right);
        void mergeSort(vector<int> &v, int left,int right);
};

#endif