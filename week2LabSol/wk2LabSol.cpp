#include <iostream>

using namespace std;
int* locatelargest(int** a, int row, int col);  // or you may put the entire function here

void display_array(int* array, int size);  // or you may put the entire function here

void Display2d(int** a, int rowlen, int col);  // or you may put the entire function here

/*
@description: main function to test my program
@param: none
@return: 0
*/

int main() {
    int rows, columns;
    // userinput for rows and cols
    cout << "Enter number of rows" << endl;
    cin >> rows;
    cout << "Enter number of columns " << endl;
    cin >> columns;

    // create the 2d array
    int** twoDArr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        twoDArr[i] = new int[columns];
    }

    // input values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "twoDarr[" << i << "][" << j << "]=  ";
            cin >> twoDArr[i][j];
        }
    }

    Display2d(twoDArr, rows, columns);
    cout << endl;
    int* loca = locatelargest(twoDArr, rows, columns);
    cout << "largest elem found at " << loca[0] << " , " << loca[1];
    /* twoDarr need to be free
    for (int i = 0; i < rows; i++) {
        delete[] twoDArr[i];
        }
     delete[] twoDArr;
    */
    return 0;
}

// locate largest 6points
/*
@description: locate the largest Value in a 2d array 
@param: 2d array, row and columns of 2d array
@return: one Dimensional array containing the row and column of the 2d array. 
*/

int* locatelargest(int** a, int row, int col) {  // method signature

    int* location = new int[2];
    location[0] = 0;
    location[1] = 0;
    int largest = a[0][0];
    // for loop for rows and cols
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            // algorithm for moving the largest(if statement)
            if (a[i][j] > largest) {
                largest = a[i][j];
                // set location
                location[0] = i;
                location[1] = j;
            }
        }
    }
    // returning location
    return location;
}

// will not mark
/*
@description: Print the 1d array 
@param: 2d array, size of 1d array
@return: null
*/

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

// will not mark
/*
@description: Print the 2d array, this indirectly tests the display_array function
@param: 2d array, row and columns of 2d array
@return: null
*/

void Display2d(int** a, int rowlen, int col) {
    // for each row
    cout << "[";
    for (int i = 0; i < rowlen; i++) {
        display_array(a[i], col);
        string l = (i == rowlen - 1) ? " " : ",";
        cout << l;
    }
    cout << "]";
}

/*Test results (1)

Enter number of rows
2
Enter number of columns 
2
twoDarr[0][0]=  12
twoDarr[0][1]=  13
twoDarr[1][0]=  14
twoDarr[1][1]=  15
[ [ 12,13 ], [ 14,15 ] ]
largest elem found at 1 , 1


Test results (2)
 
Enter number of rows
3
Enter number of columns 
3
twoDarr[0][0]=  12
twoDarr[0][1]=  13
twoDarr[0][2]=  45
twoDarr[1][0]=  14
twoDarr[1][1]=  15
twoDarr[1][2]=  16
twoDarr[2][0]=  7
twoDarr[2][1]=  8
twoDarr[2][2]=  9
[ [ 12,13,45 ], [ 14,15,16 ], [ 7,8,9 ] ]
largest elem found at 0 , 2



*/
