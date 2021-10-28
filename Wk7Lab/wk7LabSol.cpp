#include <ctime>
#include <iostream>
#include <string>

#include "MergeSort.cpp"
#include "QuickSort.cpp"
using namespace std;

int GenerateRandomValue(int min, int max) {
    return rand() % (max - min + 1) + min;
}
void Swap(int* arr, int pos1, int pos2) {
    int temp = arr[pos2];
    arr[pos2] = arr[pos1];
    arr[pos1] = temp;
}

void Rec_selectionSort(int* arr, int len, int i = 0) {
    if (i == len)
        return;
    int mini = 0;
    for (int b = i; b < len; b++) {
        if (arr[b] < arr[mini]) {
            mini = b;
        }
    }
    if (mini != i) {
        Swap(arr, mini, i);
    }
    Rec_selectionSort(arr, len, i + 1);
}

void Rec_insertionSort(int* arr, int size) {
    if (size <= 1) {
        return;
    }
    // start from size=2
    Rec_insertionSort(arr, size - 1);
    int temp = arr[size - 1];
    int index = size - 2;
    while (index == 0 && arr[index] > temp) {
        arr[index + 1] = arr[index];
        index--;
    }
    arr[index + 1] = temp;
}

void Rec_bubbleSort(int* arr, int n) {
    if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            Swap(arr, i, i + 1);
        }
    }

    Rec_bubbleSort(arr, n - 1);
}

void printArray(int* arr, int n) {
    cout << "{";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "}\n";
}

int* randomArray(int size, int min = 0, int max = 30) {
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = GenerateRandomValue(min, max);
    }
    return arr;
}

void Unsort(int* arr, int size) {
    int j = 0;
    while (j < 35) {
        for (int i = 0; i < size; i++) {
            int pos_to_swap = GenerateRandomValue(size - 1, 0);
            Swap(arr, pos_to_swap, i);
        }
        j++;
    }
}

void gettime(int size) {
    ofstream myfile;
    myfile.open("example.txt", ios::app);

    clock_t start, end;
    double timeTakenInSeconds;
    int* arr = randomArray(size);

    start = clock();
    mergeSort(arr, size);
    end = clock();
    timeTakenInSeconds = (double)(end - start) / CLOCKS_PER_SEC;

    myfile << "MergeSort " << timeTakenInSeconds << endl;

    Unsort(arr, size);

    start = clock();
    quickSort(arr, size);
    end = clock();
    timeTakenInSeconds = (double)(end - start) / CLOCKS_PER_SEC;

    myfile << "quicksort " << timeTakenInSeconds << endl;

    Unsort(arr, size);

    start = clock();
    Rec_insertionSort(arr, size);
    end = clock();
    timeTakenInSeconds = (double)(end - start) / CLOCKS_PER_SEC;

    myfile << "Rec_insertionSort " << timeTakenInSeconds << endl;

    Unsort(arr, size);

    start = clock();
    Rec_bubbleSort(arr, size);
    end = clock();
    timeTakenInSeconds = (double)(end - start) / CLOCKS_PER_SEC;
    myfile << "Rec_bubbleSort " << timeTakenInSeconds << endl;

    Unsort(arr, size);

    start = clock();
    Rec_selectionSort(arr, size);
    end = clock();
    timeTakenInSeconds = (double)(end - start) / CLOCKS_PER_SEC;
    myfile << "Rec_selectionSort " << timeTakenInSeconds << endl;
    // delete[] arr;
    // arr = nullptr;
    myfile << "Writing this to a file.\n";
    myfile.close();
}

int main() {
    srand(time(0));
    // gettime(1000);

    int size = 7;
    int* arr = new int[size];
    // arr[0] = 3;
    // arr[1] = 2;
    // arr[2] = 6;
    // arr[3] = 7;
    // arr[4] = 9;
    // arr[5] = 8;
    // arr[6] = 5;
    // cout << "insertionSort ";
    // // Rec_insertionSort(arr, size);
    // Rec_insertionSort(arr, size);
    // printArray(arr, size);
    // arr[0] = 3;
    // arr[1] = 2;
    // arr[2] = 6;
    // arr[3] = 7;
    // arr[4] = 9;
    // arr[5] = 8;
    // arr[6] = 5;
    // printArray(arr, size);
    // cout << "bubbleSort ";
    // Rec_bubbleSort(arr, size);
    // printArray(arr, size);
    // arr[0] = 3;
    // arr[1] = 2;
    // arr[2] = 6;
    // arr[3] = 7;
    // arr[4] = 9;
    // arr[5] = 8;
    // arr[6] = 5;
    // printArray(arr, size);
    arr[0] = 3;
    arr[1] = 2;
    arr[2] = 6;
    arr[3] = 7;
    arr[4] = 9;
    arr[5] = 8;
    arr[6] = 5;
    Rec_selectionSort(arr, size);
    printArray(arr, size);
    return 0;
}