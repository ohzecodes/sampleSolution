#include <iostream>
#include <string>
using namespace std;

void Swap(int* arr, int pos1, int pos2) {
    int temp = arr[pos2];
    arr[pos2] = arr[pos1];
    arr[pos1] = temp;
}

void FindMinIndex(int* arr, int len, int startingIndex, int& min, int& minIndex) {
    if (startingIndex == len) {
        return;
    } else {
        if (arr[startingIndex] < min) {
            min = arr[startingIndex];
            minIndex = startingIndex;
        }

        return FindMinIndex(arr, len, startingIndex + 1, min, minIndex);
    }
}
void Rec_selectionSort(int* arr, int len, int i = 0) {
    if (i == len)
        return;
    int mini = i;
    int min = arr[mini];
    FindMinIndex(arr, len, i, min, mini);
    if (mini != i) {
        Swap(arr, mini, i);
    }
    Rec_selectionSort(arr, len, i + 1);
}

void bubble1(int*& arr, int i, int size) {
    if (i == size) {
        return;
    }

    if (arr[i] > arr[i + 1]) {
        Swap(arr, i, i + 1);
    }

    bubble1(arr, i + 1, size);
}
void Rec_bubbleSort(int*& arr, int size) {
    if (size == 1) {
        return;
    }
    bubble1(arr, 0, size - 1);
    Rec_bubbleSort(arr, size - 1);
}

void insert1(int*& arr, int key, int j) {
    if (key > arr[j] || j < 0) {
        arr[j + 1] = key;
        return;
    } else {
        arr[j + 1] = arr[j];
        insert1(arr, key, j - 1);
    }
}

void Rec_insertionSort(int*& arr, int size, int i = 0) {
    if (i == size) {
        return;
    }
    int key = arr[i];
    int j = i - 1;
    insert1(arr, key, j);
    Rec_insertionSort(arr, size, i + 1);
}
/*
int main() {
    srand(time(0));
    int size = 6;
    int* list = new int[6];
    for (int i = 0; i < size; i++) {
        list[i] = rand() % (6 - 0 + 1);
        cout << list[i] << ".";
    }
    cout << endl;
    Rec_bubbleSort(list, size);
    for (int i = 0; i < size; i++) {
        cout << list[i] << ".";
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        list[i] = rand() % (6 - 0 + 1);
        cout << list[i] << ".";
    }
    cout << endl;
    Rec_insertionSort(list, size);
    for (int i = 0; i < size; i++) {
        cout << list[i] << ".";
    }

    return 0;
}
*/