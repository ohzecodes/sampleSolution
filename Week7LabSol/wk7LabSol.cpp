#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

#include "MergeSort.cpp"
#include "QuickSort.cpp"
#include "recursivesorting.cpp"

using namespace std;

int GenerateRandomValue(int min, int max) {
    return rand() % (max - min + 1) + min;
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

void push(int size) {
    char* s = new char[5];
    ofstream myfile;
    double* timearr;
    myfile.open("SortingAlgorithm.txt", ios::app);
    // int size = 40000;
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
    //  buuble sort two arrays
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
}
int main() {
    srand(time(0));
    push(1000);
    push(1500);
    push(2000);
    push(8000);
    push(8100);
    return 0;
}