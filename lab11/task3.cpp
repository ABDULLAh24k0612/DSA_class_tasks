#include <iostream>
using namespace std;

class Hash {
public:
    int arr[50];

    Hash() {
        for(int i=0;i<50;i++) arr[i] = -1;
    }

    int hashFunc(int key) {
        return key % 50;
    }

    void insertKey(int key) {
        int index = hashFunc(key);
        while(arr[index] != -1) index = (index + 1) % 50;
        arr[index] = key;
    }

    void deleteKey(int key) {
        for(int i=0;i<50;i++) {
            if(arr[i] == key) {
                arr[i] = -1;
                return;
            }
        }
    }

    void searchKey(int key) {
        for(int i=0;i<50;i++) {
            if(arr[i] == key) {
                cout<<"Found at index "<<i<<"\n";
                return;
            }
        }
        cout<<"Not found\n";
    }

    void display() {
        for(int i=0;i<50;i++)
            cout<<i<<" : "<<arr[i]<<"\n";
    }
};

int main() {
    Hash h;
    h.insertKey(25);
    h.insertKey(75);
    h.searchKey(75);
    h.display();
}
