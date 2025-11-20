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
            int mx = i;

            if (l < size && arr[l] > arr[mx]) mx = l;
            if (r < size && arr[r] > arr[mx]) mx = r;

            if (mx == i) break;

            int t = arr[i];
            arr[i] = arr[mx];
            arr[mx] = t;
            i = mx;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h;

    h.insert(1500);
    h.insert(1200);
    h.insert(1800);
    h.insert(1600);

    cout << "Initial queue: ";
    h.display();

    h.insert(1700);
    cout << "Queue after inserting 1700: ";
    h.display();

    h.removeRoot();
    cout << "Queue after matching highest rating: ";
    h.display();
}
