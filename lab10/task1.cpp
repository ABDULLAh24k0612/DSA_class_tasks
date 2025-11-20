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

    void display() {
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h;
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.insert(1);
    h.insert(6);

    cout << "Initial heap: ";
    h.display();

    h.insert(2);

    cout << "Heap after inserting 2: ";
    h.display();
}
