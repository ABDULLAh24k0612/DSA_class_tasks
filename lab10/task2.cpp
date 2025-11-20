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
            int biggest = i;

            if (l < size && arr[l] > arr[biggest]) biggest = l;
            if (r < size && arr[r] > arr[biggest]) biggest = r;

            if (biggest == i) break;

            int t = arr[i];
            arr[i] = arr[biggest];
            arr[biggest] = t;
            i = biggest;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h;
    h.insert(4);
    h.insert(7);
    h.insert(9);
    h.insert(5);

    cout << "Initial heap: ";
    h.display();

    h.insert(10);

    cout << "Heap after inserting 10: ";
    h.display();

    h.removeRoot();

    cout << "Heap after removing highest severity: ";
    h.display();
}
