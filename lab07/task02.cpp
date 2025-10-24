#include<iostream>
using namespace std;
#include <iostream>
#include <string>
using namespace std;


struct Participant {
    string name;
    int time; 
};


void merge(Participant arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Participant* L = new Participant[n1];
    Participant* R = new Participant[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].time <= R[j].time) {
            arr[k] = L[i];
            i++;.
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }

    delete[] L;
    delete[] R;
}


void mergeSort(Participant arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    const int n = 10;
    Participant runners[n] = {
        {"Alice", 3600},
        {"Bob", 3420},
        {"Charlie", 4100},
        {"David", 3550},
        {"Ella", 3320},
        {"Frank", 3900},
        {"Grace", 3000},
        {"Hank", 3700},
        {"Ivy", 3150},
        {"Jack", 3400}
    };

    cout << "Before Sorting (Name - Time):\n";
    for (int i = 0; i < n; i++)
        cout << runners[i].name << " - " << runners[i].time << "s\n";

    
    mergeSort(runners, 0, n - 1);

    cout << "\nAfter Sorting (Name - Time):\n";
    for (int i = 0; i < n; i++)
        cout << runners[i].name << " - " << runners[i].time << "s\n";

    cout << "\n?? Top 5 Fastest Runners:\n";
    for (int i = 0; i < 5; i++)
        cout << i + 1 << ". " << runners[i].name << " - " << runners[i].time << "s\n";

    return 0;
}
