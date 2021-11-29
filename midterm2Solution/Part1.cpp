#include <iostream>
#include "Complex.h"

using namespace std;


int main() { 
    Complex c1;

    cout << c1; // 0

    Complex c2(2,3);
    Complex c3(-4,-5);

    cout << c2 << c3; // 2 + 3i then -4 + -5i

    Complex c4 = c2 + c3;

    cout << c4; // -2 + -2i

    Complex c5 = c4++;

    cout << c4 << c5; // -1 + -2i then -2 + -2i

    Complex c6 = c2 - c3;

    cout << c6; // 6 + 8i

    Complex c7;

    cin >> c7;

    cout << c7;

    return 0;
  }
