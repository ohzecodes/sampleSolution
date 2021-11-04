#include <iostream>
#include <string>
using namespace std;

void display_array(int* array, int size, string msg = "") {
    cout << msg << " [ ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << ",";
    }
    cout << "]";
}

//merge Sort functions
// /*
int** MSplit(int* arr, int size, int indexToSplitAt) {
    int** splits = new int*[2];  //items to the left of indexToSplitAt, items to the right of indexToSplitAt, neither includes arr[indexToSplitAt]
    if (indexToSplitAt != 0) {
        splits[0] = new int[indexToSplitAt];  //items from arr[0] to arr[indexToSplitAt-1] (inclusive)
        for (int i = 0; i < indexToSplitAt; i++) {
            splits[0][i] = arr[i];
        }
    } else {
        splits[0] = nullptr;
    }
    if (size - indexToSplitAt != 0) {
        splits[1] = new int[size - indexToSplitAt];  // items from arr[indexToSplitAt + 1] to arr[size - 1] (inclusive)
        for (int i = indexToSplitAt; i < size; i++) {
            splits[1][i - indexToSplitAt] = arr[i];
        }
    } else {
        splits[1] = nullptr;
    }
    return splits;
}
// */
int* MergeInOrder(int* left, int lSize, int* right, int rSize) {
    int i, j, k;
    int* merged = new int[lSize + rSize];
    i = j = k = 0;

    while (i < lSize && j < rSize) {
        if (left[i] <= right[j]) {
            merged[k++] = left[i++];
        } else {
            merged[k++] = right[j++];
        }
    }
    //remaining items in left, just put in merge since left is already sorted
    while (i < lSize) {
        merged[k++] = left[i++];
    }
    // similarly do for right, in case right has items remaining to place in the merged array
    while (j < rSize) {
        merged[k++] = right[j++];
    }

    if (left) {
        delete[] left;
        left = nullptr;
    }
    if (right) {
        delete[] right;
        right = nullptr;
    }
    return merged;
}

int* MergeSort(int* arr, int size) {
    if (size == 0) {
        return nullptr;
    } else if (size == 1) {
        int* baseSolution = new int[size];
        baseSolution[0] = arr[0];

        if (arr) {
            delete[] arr;
            arr = nullptr;
        }
        return baseSolution;
    } else if (size == 2) {
        int* baseSolution = new int[size];

        if (arr[0] < arr[1]) {
            baseSolution[0] = arr[0];
            baseSolution[1] = arr[1];
        } else {
            baseSolution[0] = arr[1];
            baseSolution[1] = arr[0];
        }
        if (arr) {
            delete[] arr;
            arr = nullptr;
        }
        return baseSolution;
    } else {
        //split arr into 2  halves, left and right
        int** slices = MSplit(arr, size, size / 2);
        /*if (arr) {
            delete[] arr;
            arr = nullptr;
        }*/
        int leftSize = size / 2;

        int rightSize = size - leftSize;

        slices[0] = MergeSort(slices[0], leftSize);
        slices[1] = MergeSort(slices[1], rightSize);

        // if (slices[0]) {
        //     delete[] slices[0];
        //     slices[0] = nullptr;
        // }
        // if (slices[1]) {
        //     delete[] slices[1];
        //     slices[1] = nullptr;
        // }
        // if (slices) {
        //     delete[] slices;
        //     slices = nullptr;
        // }

        int* result = MergeInOrder(slices[0], leftSize, slices[1], rightSize);

        return result;
    }
}

int GenerateRandomValue(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int* randomArray(int size, int min, int max) {
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = GenerateRandomValue(min, max);
    }
    return arr;
}

int main() {
    srand(time(0));
    int size = 7;
    int* ar = randomArray(size, 0, 10);

    display_array(ar, size, "unsorted");
    // int* b = QuickSort(ar, size);
    // display_array(b, size, "\nquick sort");

    // quick sort deletes the array passed array
    ar = randomArray(size, 0, 10);
    display_array(ar, size, "\nunsorted");

    int* c = MergeSort(ar, size);
    display_array(c, size, "\nmerge sort");

    // housekeeping
    if (ar) {
        delete ar;
        ar = nullptr;
    }
    // if (b) {
    //     delete b;
    //     b = nullptr;
    // }
    if (c) {
        delete c;
        c = nullptr;
    }
    return 0;
}