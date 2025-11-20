#include <iostream>
using namespace std;

class MaxHeap {
public:
    int arr[50];
    int size;

    MaxHeap() { size = 0; }

    void insert(int x) {
        arr[size] = x;
        int i = size;
        size++;
        while (i > 0 && arr[(i-1)/2] < arr[i]) {
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
            int maxIndex = i;

            if (l < size && arr[l] > arr[maxIndex]) maxIndex = l;
            if (r < size && arr[r] > arr[maxIndex]) maxIndex = r;

            if (maxIndex == i) break;

            int t = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = t;
            i = maxIndex;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h;

    h.insert(5);
    h.insert(3);
    h.insert(8);

    cout << "Heap after inserting A(5), B(3), C(8): ";
    h.display();

    h.removeRoot();
    cout << "Heap after removing highest priority: ";
    h.display();

    h.insert(6);
    cout << "Heap after inserting D(6): ";
    h.display();
}
