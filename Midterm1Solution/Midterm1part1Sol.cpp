#include <iostream>
#include <string>
using namespace std;

int GenerateRandomValue(int min, int max) {
    return rand() % (max - min + 1) + min;
}
void display_array(int* array, int size) {
    cout << " [ ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << ",";
    }
    cout << " ]\n";
}

void Display2d(int** a, int rows, int col) {
    // for each row
    cout << "[ \n";
    for (int i = 0; i < rows; i++) {
        display_array(a[i], col);
    }
    cout << "]";
}
int MainDiagonalSum(int** matrix, int r, int c) {
    if (r == 0 || c == 0) {
        return 0;
    } else {
        // int sm = (r > c) ? matrix[c - 1][c - 1] : matrix[r - 1][r - 1];  //ternary operator
        int sm = matrix[c - 1][c - 1];  //since you test this in the main funct
        int big = sm + MainDiagonalSum(matrix, --r, --c);
        return big;
    }
}

int main() {
    srand(time(NULL));  // null is 0
    int rows, cols;
    cout << "enter rows and then cols" << endl;
    cin >> rows;
    cin >> cols;
    // create the 2d array
    int** twoDArr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        twoDArr[i] = new int[cols];
    }

    // input values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            twoDArr[i][j] = GenerateRandomValue(0, 9);
        }
    }
    Display2d(twoDArr, rows, cols);
    int sum = 0;
    if (rows < cols) {
        sum = MainDiagonalSum(twoDArr, rows, rows);
    } else {
        sum = MainDiagonalSum(twoDArr, cols, cols);
    }
    cout << endl
         << "Sun=" << sum << "\n";

    // clear array
    for (int i = 0; i < rows; i++) {
        delete[] twoDArr[i];
        twoDArr[i] = nullptr;
    }
    delete[] twoDArr;
    twoDArr = nullptr;

    return 0;
}