#include <iostream>
using namespace std;

int comparisons = 0;

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

int partition(int arr[], int low, int high, int pivotIndex) {
    swap(arr[pivotIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, string method) {
    if (low < high) {
        int pivotIndex;
        if (method == "first") pivotIndex = low;
        else if (method == "random") pivotIndex = low + rand() % (high - low + 1);
        else if (method == "middle") pivotIndex = (low + high) / 2;
        else {
            int a = arr[low], b = arr[(low + high) / 2], c = arr[high];
            if ((a > b) != (a > c)) pivotIndex = low;
            else if ((b > a) != (b > c)) pivotIndex = (low + high) / 2;
            else pivotIndex = high;
        }
        int pi = partition(arr, low, high, pivotIndex);
        quickSort(arr, low, pi - 1, method);
        quickSort(arr, pi + 1, high, method);
    }
}

void runTest(string method) {
    int arr[] = {10, 7, 8, 9, 1, 5, 3};
    int n = 7;
    comparisons = 0;
    quickSort(arr, 0, n - 1, method);
    cout << method << " pivot sorted: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << " | Comparisons: " << comparisons << endl;
}

int main() {
    srand(0);
    runTest("first");
    runTest("random");
    runTest("middle");
    runTest("median");
    return 0;
}
