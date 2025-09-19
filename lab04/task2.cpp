#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100 + 1;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int bubbleSort(int arr[], int size) {
    int comparisons = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return comparisons;
}

int insertionSort(int arr[], int size) {
    int comparisons = 0;
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key)
                arr[j + 1] = arr[j];
            else
                break;
            j--;
        }
        arr[j + 1] = key;
    }
    return comparisons;
}

int selectionSort(int arr[], int size) {
    int comparisons = 0;
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
    return comparisons;
}

int shellSort(int arr[], int size) {
    int comparisons = 0;
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap; j -= gap) {
                comparisons++;
                if (arr[j - gap] > temp)
                    arr[j] = arr[j - gap];
                else
                    break;
            }
            arr[j] = temp;
        }
    }
    return comparisons;
}

void sortAndDisplay(int original[], int size) {
    int a1[100], a2[100], a3[100], a4[100];
    for (int i = 0; i < size; i++) {
        a1[i] = a2[i] = a3[i] = a4[i] = original[i];
    }

    int cmp1 = bubbleSort(a1, size);
    cout << "Bubble Sort:\n";
    printArray(a1, size);
    cout << "Comparisons: " << cmp1 << "\n\n";

    int cmp2 = insertionSort(a2, size);
    cout << "Insertion Sort:\n";
    printArray(a2, size);
    cout << "Comparisons: " << cmp2 << "\n\n";

    int cmp3 = selectionSort(a3, size);
    cout << "Selection Sort:\n";
    printArray(a3, size);
    cout << "Comparisons: " << cmp3 << "\n\n";

    int cmp4 = shellSort(a4, size);
    cout << "Shell Sort:\n";
    printArray(a4, size);
    cout << "Comparisons: " << cmp4 << "\n\n";
}

int main() {
    srand(time(0));

    int arr20[20];
    generateRandomArray(arr20, 20);
    cout << "Original 20-element array:\n";
    printArray(arr20, 20);
    cout << "\n";
    sortAndDisplay(arr20, 20);

    int arr100[100];
    generateRandomArray(arr100, 100);
    cout << "Original 100-element array:\n";
    printArray(arr100, 100);
    cout << "\n";
    sortAndDisplay(arr100, 100);

    return 0;
}
