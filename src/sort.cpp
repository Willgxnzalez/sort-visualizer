#include "sort.h"
#include <iostream>
#include <random>
using namespace std;

void Sorter::randomizeVector(vector<int> &v) {
    v.clear();
    std::random_device rd;
    std::uniform_int_distribution d(1,99);
    for (int i=0; i<100; ++i)
        v.push_back(d(rd));
}

bool Sorter::isSorted(vector<int> & v) {
    int len = v.size();
    for (int i=1; i<len; ++i)
        if (v[i-1] > v[i])
            return false;
    return true;
}

void BubbleSorter::sort(vector<int> &v) {
    int len = v.size();
    for (int i=0; i < len; ++i) {
        for (int j=i+1; j < len; ++j) {
            if (v[i] > v[j])
                std::swap(v[i], v[j]);
            app.visualize(i, j);
            //app.delay(5);
        }
    }
}

void QuickSorter::sort(vector<int> &v) {
    quicksort(v, 0, v.size());
}

int QuickSorter::medianOfThree(vector<int> &v, int low, int high) {
    int mid = (low + high) / 2;
    if (v[mid] < v[low]) std::swap(v[low], v[mid]);
    if (v[high] < v[low]) std::swap(v[low], v[high]);
    if (v[mid] < v[high]) std::swap(v[mid], v[high]);
    app.visualize();
    //app.delay(5);
    return high;
}

int QuickSorter::partition(vector<int> &v, int low, int high) {
    int pivot_index = medianOfThree(v, low, high);
    for (int j = low; j < high; j++) {
        if (v[j] <= v[pivot_index]) {
            std::swap(v[low], v[j]);
            app.visualize(pivot_index, j, low);
            app.delay(10);
            ++low;
        }
    }
    std::swap(v[low], v[high]);
    return low;

}

void QuickSorter::quicksort(vector<int> &v, int low, int high) {
    if (low < high) {
        int pivot = partition(v, low, high);
        quicksort(v, low, pivot-1);
        quicksort(v, pivot+1, high);
    }
}

void InsertionSorter::sort(vector<int> &v) {
    int len = v.size();
    for (int i=0; i < len; ++i) { // iterate over the array
        for (int j=i; j > 0 && v[j-1] > v[j]; --j) {
            std::swap(v[j-1], v[j]);
            app.visualize(j, j-1);
            app.delay(10);
        }
    }
}

void SelectionSorter::sort(vector<int> &v) {
    int len = v.size();
    for (int i=0; i < len; ++i) {
        int min = i;
        for (int j=i+1; j < len; ++j) {
            if (v[j] < v[min]) {
                min = j;
                app.visualize(i, min);
                app.delay(10);
            }
        }
        if (i != min)
            std::swap(v[min], v[i]);
    }
}