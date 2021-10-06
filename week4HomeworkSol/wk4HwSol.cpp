#include <iostream>
#include <string>
using namespace std;

void display_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            cout << " [ " << array[i] << ",";
        } else if (i == size - 1) {
            cout << array[i] << " ]";
        } else {
            cout << array[i] << ",";
        }
    }
}

/*1. 
no need to validate start and n
Has to be recursive 
*/
int Rec_getNthterm(int* arr, int size, int& start, int n) {
    // base case
    if (start == n) {
        return arr[n];
    } else {
        return Rec_getNthterm(arr, size, ++start, n);
    }
}

/*2.
must validate start and end
Need not be recursive
 */
int* Slice(int* arr, int size, int start, int end, int& newsize) {
    int* b = new int[newsize];
    if (start >= 0 && start < size && end > 0 && end < size) {
        for (int j = 0, i = start; j < newsize || i < end; j++, i++) {
            b[j] = arr[i];
        }
    }
    return b;
}

/*3.
Has to be recursive 
*/
bool Rec_isSorted(int* arr, int size) {
    if (size == 1 || size == 0) {
        return true;
    }

    if (arr[size - 2] > arr[size - 1]) {
        return false;
    }

    return Rec_isSorted(arr, size - 1);
}

/*4.  
assume left and right already sorted
no need to validate
Need not be recursive */
int* MergeInOrder(int* left, int lSize, int* right, int rSize) {
    int i, j, k;
    i = j = k = 0;
    int* merged = new int[lSize + rSize];

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
    // clear left and right arrays
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

/*helper functions*/
int extractlastdigit(int num) {
    int rem;

    rem = num % 10;

    return rem;
}
/*helper functions*/
int removelastdigit(int n) {
    return n / 10;
}
/*5. has to be recursive */
int Rec_productDigit(int n) {
    if (n == 0) {
        return 1;
    } else {
        int sm = extractlastdigit(n);                         //small solution
        int big = sm * Rec_productDigit(removelastdigit(n));  //big solution
        return big;
    }
}

int main() {
    int start = 0;
    int size = 7;
    int* ar = new int[size];
    ar[0] = 3;
    ar[1] = 2;
    ar[2] = 6;
    ar[3] = 7;
    ar[4] = 5;
    ar[5] = 8;
    ar[6] = 9;
    cout << "\n+++++++++++++++++++++++++\n";
    cout << "test for getNthterm" << endl;

    cout << Rec_getNthterm(ar, size, start, 5) << " = " << ar[5] << endl;
    cout << "\n+++++++++++++++++++++++++\n";
    cout << "test for Slice" << endl;
    int items = 3;
    int* i = Slice(ar, size, 4, 6, items);
    display_array(i, items);
    cout << "\n+++++++++++++++++++++++++\n";
    cout << "\ntest for isSorted" << endl;
    display_array(i, items);
    cout << ".." << Rec_isSorted(i, items) << endl;
    display_array(ar, size);
    cout << ".." << Rec_isSorted(ar, size) << endl;
    cout << "\n+++++++++++++++++++++++++\n";
    cout << "test for MergeInOrder\n";
    size = 4;
    int* l = new int[size];
    l[0] = 5;
    l[1] = 7;
    l[2] = 9;
    l[3] = 15;
    int* r = new int[size + 2];
    r[0] = 6;
    r[1] = 8;
    r[2] = 10;
    r[3] = 11;
    r[4] = 12;
    r[5] = 14;

    int* m = MergeInOrder(l, size, r, size + 2);
    display_array(m, size * 2 + 2);
    cout << "\n+++++++++++++++++++++++++\n";
    cout << "\ntest for ProductDigit\n";
    cout << Rec_productDigit(1234) << " = " << 1 * 2 * 3 * 4 << endl;
    cout << Rec_productDigit(456) << " = " << 4 * 5 * 6 << endl;

    //no need to delete r and l because the MergeInOrder already deletes them
    delete[] m;
    m = nullptr;
    delete[] i;
    i = nullptr;
    delete[] ar;
    ar = nullptr;
    return 0;
}

/*Test Results 

+++++++++++++++++++++++++
test for getNthterm
8 = 8

+++++++++++++++++++++++++
test for Slice
 [ 5,8,9 ]
+++++++++++++++++++++++++

test for isSorted
 [ 5,8,9 ]..1
 [ 3,2,6,7,5,8,9 ]..0

+++++++++++++++++++++++++
test for MergeInOrder
 [ 5,6,7,8,9,10,11,12,14,15 ]
+++++++++++++++++++++++++

test for ProductDigit
24 = 24
120 = 120

*/