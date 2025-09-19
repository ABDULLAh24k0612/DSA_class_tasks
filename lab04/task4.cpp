#include <iostream>
using namespace std;

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int interpolationSearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            else return -1;
        }

        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]);

        if (arr[pos] == target)
            return pos;
        else if (arr[pos] < target)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    insertionSort(arr, n);

    cout << "Sorted array:\n";
    printArray(arr, n);

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int index = interpolationSearch(arr, n, key);

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found in the array.\n";

    return 0;
}
