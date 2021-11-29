#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Floating point numbers are numbers with a dot in them that may
 * be preceeded and/or followed by 0 or more digits. Here are examples of
 * positive floating point values
 * 11.23
 * 0.78
 * .78
 * 5. 
 * 
 * In this problem we are interested in knowing whether or not the string text
 * contains a positive floating point value inside it (we do not expect
 * the + sign to be ever used).
 * The string text will have no leading or trailing spaces however it may
 * contain any other letters and/or symbols.
 * 
 * RESTRICTIONS:
 * There can be NO LOOPS in your work. Hence, only recursion whenever necessary
 * The only string class methods you are allowed to use are substr and length
 * You may NOT use any other C++ built-in functions and/or classes.
 * You are welcome (encouraged) to add extra functions - no loops though
 * 
 * @param text, type string, contains characters but no leading or trailing spaces
 * @return true when text contains a floating point number; false otherwise
 */

int DotCount(string text, int len) {
    // 5 points
    if (len == 0) {
        return 0;
    } else {
        if (text[len - 1] == '.') {
            return 1 + DotCount(text, len - 1);
        } else {
            return DotCount(text, len - 1);
        }
    }
}

int FindDotIndex(string text, int len) {
    // 5 points

    if (len == 0) {
        return -1;
    } else {
        if (text[len - 1] == '.') {
            return len - 1;
        } else {
            return FindDotIndex(text, len - 1);
        }
    }
}
bool ContainsOnlyDigits(string text, int len) {
    // 5 points

    if (len == 0) {
        return true;
    } else {
        if (text[len - 1] < '0' || text[len - 1] > '9') {
            return false;
        } else {
            return true && ContainsOnlyDigits(text, len - 1);
        }
    }
}

bool IsPositiveFloat(string text) {
    // 5 points

    if (DotCount(text, text.length()) != 1) {
        return false;
    }

    int dotIndex = FindDotIndex(text, text.length());

    string before = text.substr(0, dotIndex);
    string after = text.substr(dotIndex + 1, text.length() - (dotIndex + 1));

    if (before.length() == 0 && after.length() == 0) {
        return false;
    }

    if (!ContainsOnlyDigits(before, before.length()) || !ContainsOnlyDigits(after, after.length())) {
        return false;
    }

    return true;
}

int main() {
    cout << IsPositiveFloat("123.76") << endl;  //true
    cout << IsPositiveFloat(".76") << endl;     //true
    cout << IsPositiveFloat("123.") << endl;    //true
    cout << IsPositiveFloat(".") << endl;       //false
    cout << IsPositiveFloat("1.7678") << endl;
    cout << IsPositiveFloat("12367.8") << endl;
    cout << IsPositiveFloat("12367...8") << endl;  //true
    cout << IsPositiveFloat("12.367.8") << endl;
    cout << IsPositiveFloat("12367.a..") << endl;  //
    cout << IsPositiveFloat(".12367.8") << endl;
    cout << IsPositiveFloat(".12.367.8.") << endl;
    cout << IsPositiveFloat("abc.def") << endl;
    cout << IsPositiveFloat("abc.") << endl;
    cout << IsPositiveFloat(".def") << endl;
    cout << IsPositiveFloat("abc.789") << endl;
    cout << IsPositiveFloat("12.defg") << endl;
    cout << IsPositiveFloat("abc123.789def") << endl;
    cout << IsPositiveFloat("abc0.0") << endl;
    cout << IsPositiveFloat("0.0def") << endl;

    return 0;
}