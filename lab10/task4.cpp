#include <iostream>
using namespace std;

class MinHeap {
public:
    int arr[50];
    int size;

    MinHeap() { size = 0; }

    void insert(int x) {
        arr[size] = x;
        int i = size;
        size++;
        while (i > 0 && arr[(i-1)/2] > arr[i]) {
            int t = arr[i];
            arr[i] = arr[(i-1)/2];
            arr[(i-1)/2] = t;
            i = (i-1)/2;
        }
    }

    void removeRoot() {
        if (size == 0) return;
        arr[0] = arr[size-1];
        size--;
        int i = 0;
        while (true) {
            int l = 2*i+1;
            int r = 2*i+2;
            int mn = i;

            if (l < size && arr[l] < arr[mn]) mn = l;
            if (r < size && arr[r] < arr[mn]) mn = r;

            if (mn == i) break;

            int t = arr[i];
            arr[i] = arr[mn];
            arr[mn] = t;
