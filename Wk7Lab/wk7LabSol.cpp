#include <ctime>
#include <fstream>
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

int* randomArray(int size, int min = 0, int max = 100) {
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

double* gettime(int size) {
    double* answer = new double[5];
    clock_t start, end;
    double timeTakenInSeconds;
    int* arr = randomArray(size);

    start = clock();
    mergeSort(arr, size);
    end = clock();
    timeTakenInSeconds = (double)(end - start) / CLOCKS_PER_SEC;
    answer[0] = timeTakenInSeconds;  //merge
    Unsort(arr, size);

    start = clock();
    quickSort(arr, size);
    end = clock();
    timeTakenInSeconds = (double)(end - start) / CLOCKS_PER_SEC;
    answer[1] = timeTakenInSeconds;  //quick
    Unsort(arr, size);
    Unsort(arr, size);
    start = clock();
    Rec_insertionSort(arr, size);
    end = clock();
    timeTakenInSeconds = (double)(end - start) / CLOCKS_PER_SEC;
    answer[2] = timeTakenInSeconds;  //insertion
    Unsort(arr, size);

    start = clock();
    Rec_bubbleSort(arr, size);
    end = clock();
    timeTakenInSeconds = (double)(end - start) / CLOCKS_PER_SEC;
    answer[3] = timeTakenInSeconds;  // bubble
    Unsort(arr, size);

    start = clock();
    Rec_selectionSort(arr, size);
    end = clock();
    timeTakenInSeconds = (double)(end - start) / CLOCKS_PER_SEC;
    answer[4] = timeTakenInSeconds;  //selection

    // if (arr != nullptr) {
    //     delete[] arr;
    //     arr = nullptr;
    // }
    return answer;
}

int main() {
    srand(time(0));

    char* s = new char[5];
    ofstream myfile;
    double* timearr;
    myfile.open("example.txt", ios::app);
    int size = 40000;
    s[0] = 'M';
    s[1] = 'Q';
    s[2] = 'I';
    s[3] = 'B';
    s[4] = 'S';
    timearr = gettime(size);

    for (int i = 0; i < 5; i++) {
        cout << s[i] << " : " << timearr[i] << endl;
    }
    cout << endl
         << endl;
    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (timearr[j] > timearr[j + 1]) {
                // swap
                double temp = timearr[j + 1];
                char temp1 = s[j + 1];
                timearr[j + 1] = timearr[j];
                s[j + 1] = s[j];
                timearr[j] = temp;
                s[j] = temp1;
            }
        }
    }
    myfile << endl
           << "size:" << size << endl;
    for (int i = 0; i < 5; i++) {
        cout << s[i] << " " << timearr[i] << endl;
        myfile << s[i] << " " << timearr[i] << endl;
    }

    myfile.close();
    if (s) {
        delete[] s;
        s = nullptr;
    }
    if (timearr) {
        delete[] timearr;
        timearr = nullptr;
    }

    return 0;
}