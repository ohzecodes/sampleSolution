#include <iostream>
#include <string>
using namespace std;

//merge Sort functions

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

bool IsSame(int* arr1, int* arr2, int arrLen) {
    bool issame = true;
    int* c = MergeSort(arr1, arrLen);  //also accept any other algortihm
    int* e = MergeSort(arr2, arrLen);  //also accept any other algortihm
    for (int i = 0; i < arrLen; i++) {
        if (c[i] != e[i]) {
            // cout << i;
            issame = false;
            break;
        }
    }
    if (c) {
        delete[] c;
        c = nullptr;
    }
    if (e) {
        delete[] e;
        e = nullptr;
    }
    return issame;
}
/*
Big-O analysis: 

    O(n*log (n)) from merge sorting arr1

+   O(n*log (n)) from merge sorting arr2

+   O(n) from comparing contents of arr1 with arr2 (the i-loop inside IsSame performs k*n + p operations where k and p are contants. Since k and p can be ignored when forming the big-O of this loop the order of this loop is O(n))

+   O(1) from everything else that is happening inside IsSame (such as declarations, assignments, memory clenup that are not inside any loop)
 
    O(n*log(n) + n*log(n) + n + 1) = O(2*n*log(n) + n + 1) = O(2*n*log(n)) = O(n*log(n))

A student may also have generated a more accurate count of operations inside IsSame as follows (following is based on IsSame code above, of course a particular student's count would be specific to their code)

  2 //bool issame = true;
+ 2 //int* c =
+ O(n*log(n)) // MergeSort(arr1, arrLen);
+ 2 //int* e =
+ O(n*log(n)) // MergeSort(arr1, arrLen);
+ 2 // int i = 0
+ 9 * n // rest of i-loop, c[i] is two operations: *(c + i) and so is e[i], i++ is two operations
+ 3 // freeing memory for c
+ 3 // freeing memory for e
+ 1 // returning issame

= 15 + 2*n*log(n) + 9*n = O(2*n*log(n)) = O(n*log(n))

*/

int main() {
    int size = 4;
    int* ar = new int[size];
    ar[0] = 3;
    ar[1] = 2;
    ar[2] = 6;
    ar[3] = 7;
    int* ar2 = new int[size];

    ar2[0] = 7;
    ar2[1] = 6;
    ar2[2] = 2;
    ar2[3] = 3;
    cout << boolalpha << IsSame(ar, ar2, size) << endl;

    int* ar3 = new int[size];

    ar3[0] = 7;
    ar3[1] = 6;
    ar3[2] = 2;
    ar3[3] = 4;
    cout << boolalpha << IsSame(ar, ar3, size) << endl;

    if (ar) {
        delete[] ar;
        ar = nullptr;
    }
    if (ar2) {
        delete[] ar2;
        ar2 = nullptr;
    }
    if (ar3) {
        delete[] ar3;
        ar3 = nullptr;
    }
    return 0;
}
