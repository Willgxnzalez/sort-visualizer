#include <iostream>
#include <random>
#include "sort.hpp"

bool Sorter::isSorted(vector<int> & v) {
    int len = v.size();
    for (int i=1; i<len; ++i)
        if (v[i-1] > v[i])
            return false;
    return true;
}

void Sorter::randomizeVector(vector<int> &v) {
    v.clear();
    std::random_device rd;
    std::uniform_int_distribution d(1,99);
    for (int i=0; i<100; ++i)
        v.push_back(d(rd));
}

void Sorter::setRenderer(SDL_Renderer *r) { ren = r; }

void Sorter::clear_vis_screen() {
    SDL_SetRenderDrawColor(ren, 24,24,24, 255);
    SDL_Rect visScreen{0, 0, visWidth, screenHeight};
    SDL_RenderFillRect(ren, &visScreen);
}

void Sorter::visualize(vector<int> &v, int h1, int h2, int h3, bool complete) {
    clear_vis_screen(); // clear the screen before the next screen is drawn

    int len = v.size();
    for (int i=0; i < len; ++i) {
        SDL_Rect rect{i * scale, screenHeight - (v[i] * scale), scale, v[i] * scale};
        if (complete) {
            SDL_SetRenderDrawColor(ren, 90, 113, 155, 255);
            SDL_RenderFillRect(ren, &rect);
            SDL_SetRenderDrawColor(ren, 100, 255, 100, 255);
            SDL_RenderDrawRect(ren, &rect);
        } else if (i == h1) {
            SDL_SetRenderDrawColor(ren, 111, 241, 236, 255);
            SDL_RenderFillRect(ren, &rect);
        } else if (i == h2 || i == h3) {
            SDL_SetRenderDrawColor(ren, 255,50,140, 255);
            SDL_RenderFillRect(ren, &rect);
        } else {
            SDL_SetRenderDrawColor(ren, 90, 113, 155, 255);
            SDL_RenderFillRect(ren, &rect);
            SDL_SetRenderDrawColor(ren, 24, 24, 24, 255); //draw small borders
            SDL_RenderDrawRect(ren, &rect);
        }
    }
    SDL_RenderPresent(ren);
}


void BubbleSorter::sort(vector<int> &v) {
    int len = v.size();
    for (int i=0; i < len; ++i) {
        for (int j=i+1; j < len; ++j) {
            if (v[i] > v[j])
                std::swap(v[i], v[j]);
            Sorter::visualize(v, i, j);
            SDL_Delay(2);
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
    Sorter::visualize(v);
    //SDL_Delay(5);
    return high;
}

int QuickSorter::partition(vector<int> &v, int low, int high) {
    int pivot_index = medianOfThree(v, low, high);
    for (int j = low; j < high; j++) {
        if (v[j] <= v[pivot_index]) {
            std::swap(v[low], v[j]);
            Sorter::visualize(v, pivot_index, j, low);
            SDL_Delay(10);
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
        for (int j=i; j > 0 && v[j-1] > v[j]; --j) { // keep swapping with smaller previous value until in correct position
            std::swap(v[j-1], v[j]);
            Sorter::visualize(v, j, j-1);
            SDL_Delay(10);
        }
    }
}

void SelectionSorter::sort(vector<int> &v) {
    int len = v.size();
    for (int i=0; i < len; ++i) {
        int min = i;
        for (int j=i+1; j < len; ++j) {  // finds the new minimum
            if (v[j] < v[min]) {
                min = j;
                Sorter::visualize(v, i, min);
                SDL_Delay(10);
            }
        }
        if (i != min)
            std::swap(v[min], v[i]); // swaps current value with newest minimum
    }
}

void MergeSorter::sort(vector<int> &v) {
    mergeSort(v, 0, v.size());
}

void MergeSorter::mergeSort(vector<int> &v, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) /2;
        mergeSort(v, left, mid);
        mergeSort(v, mid+1, right);
        merge(v, left, mid, right);
    }
}

void MergeSorter::merge(vector<int> &v, int left, int mid, int right) {
    int i, j, k;
    int nleft = mid - left + 1;
    int nright = right - mid;
    int larr[nleft], rarr[nright];

    for (i=0; i < nleft; ++i)
        larr[i] = v[left+i];
    for (j=0; j < nright; ++j)
        rarr[j] = v[mid+1+j];

    /*
        for (auto i : larr)
        cout << i << " ";
    
    for (auto i : rarr)
        cout << i << " ";
    
    */

    i = 0, j = 0; k = 1;

    while (i < nleft && j < nright) { // if both are not empty
        if (larr[i] <= rarr[j]) {
            v[k] = larr[i];
            Sorter::visualize(v);
            ++i;
        } else {
            v[k] = rarr[i];
            Sorter::visualize(v);
            ++j;
        }
        ++k;
    }

    while (i < nleft) {
        v[k] = larr[i];
        Sorter::visualize(v);
        ++i; ++k;
    }

    while (j < nright) {
        v[k] = rarr[j];
        Sorter::visualize(v);
        ++j; ++k;
    }

}