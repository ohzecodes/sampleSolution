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

int sumPage(int*** book, int pageNumber, int lines, int col) {
    int sum = 0;
    for (int j = 0; j < lines; j++) {
        for (int k = 0; k < col; k++) {
            sum += book[pageNumber][j][k];
        }
    }
    return sum;
}

int GenerateRandomValue(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void clearbook(int*** book, int pages, int lines, int cols) {
    for (int i = 0; i < pages; i++) {
        for (int j = 0; j < lines; j++) {
            delete[] book[i][j];
        }
        delete[] book[i];
    }
    delete[] book;
    cout << "book cleared";
}

int*** makebook(int pages, int lines, int col) {
    int*** book = new int**[pages];
    for (int i = 0; i < pages; i++) {
        book[i] = new int*[lines];
        for (int j = 0; j < lines; j++) {
            // pages
            book[i][j] = new int[col];
        }
    }
    return book;
}

void printbook(int*** book, int pages, int lines, int col) {
    for (int i = 0; i < pages; i++) {
        cout << "\npage:" << i << endl;
        for (int j = 0; j < lines; j++) {
            for (int k = 0; k < col; k++) {
                cout << book[i][j][k] << " ";
            }
            cout << endl;
        }
    }
    // cout << "\n sum: " << sumPage(book, pages, lines, col) << endl;
}

void fillRandomValues(int*** book, int pages, int lines, int col) {
    for (int i = 0; i < pages; i++) {
        for (int j = 0; j < lines; j++) {
            for (int k = 0; k < col; k++) {
                book[i][j][k] = GenerateRandomValue(5, 55);
            }
        }
    }
}

void Swap1d(int*& arr, int pos1, int pos2) {
    int temp = arr[pos2];
    arr[pos2] = arr[pos1];
    arr[pos1] = temp;
    temp = 0;
}

int* sumofallpages(int*** book, int pages, int lines, int col) {
    int* sumbook = new int[pages];
    for (int i = 0; i < pages; i++) {
        sumbook[i] = sumPage(book, i, lines, col);
    }

    return sumbook;
}

void swappages(int***& book, int pages, int lines, int cols, int page1, int page2) {
    for (int j = 0; j < lines; j++) {
        for (int k = 0; k < cols; k++) {
            int temp = book[page1][j][k];
            book[page1][j][k] = book[page2][j][k];
            book[page2][j][k] = temp;
        }
    }
    /*
    Accept this as well
    int** temp;
    temp = book[page1];
    book[page1] = book[page2];
    book[page2] = temp;
    */
}

/*bubble sort*/
void bsort(int*** book, int pages, int lines, int cols) {
    int* sumbook = sumofallpages(book, pages, lines, cols);
    cout << "pre-sort";
    display_array(sumbook, pages);
    for (int i = 0; i < pages; i++) {
        for (int j = 0; j < pages - 1; j++) {
            if (sumbook[j] > sumbook[j + 1]) {
                swappages(book, pages, lines, cols, j, j + 1);
                Swap1d(sumbook, j, j + 1);
            }
        }
    }
    cout << "\npost-sort";
    display_array(sumbook, pages);
}

int main() {
    srand(time(0));
    int k, m, n;
    cout << "enter number of pages";
    cin >> k;
    cout << "enter number of lines";
    cin >> m;
    cout << "enter number of columns";
    cin >> n;

    int*** x = makebook(k, m, n);
    fillRandomValues(x, k, m, n);

    printbook(x, k, m, n);
    bsort(x, k, m, n);
    cout << "\nswap";
    printbook(x, k, m, n);
    clearbook(x, k, m, n);

    return 0;
}

/*
Test results(1):
    enter number of pages   2
    enter number of lines   2
    enter number of columns 2

    page:0
    54 54 
    10 46 

    page:1
    25 14 
    7 12 

    pre-sort [ 164,58 ]
    post-sort [ 58,164 ]

    swapped

    page:0
    25 14 
    7 12 

    page:1
    54 54 
    10 46 
    book cleared


Test Results(2):

    enter number of pages3
    enter number of lines2
    enter number of columns1

    page:0
    39 
    32 

    page:1
    51 
    7 

    page:2
    49 
    21 
    pre-sort [ 71,58,70 ]
    post-sort [ 58,70,71 ]
    swap
    page:0
    51 
    7 

    page:1
    49 
    21 

    page:2
    39 
    32 
    book cleared



*/
