#include <iostream>
#include <string>
#include <vector>

using namespace std;

class set {
   private:
    vector<int>* vSet;
    bool isin(int val) {
        for (unsigned int i = 0; i < vSet->size(); i++) {
            if (vSet->at(i) == val) {
                return true;
            }
        }
        return false;
    }
    bool dublicates() {
        bool dublicateitemsExists = false;

        for (unsigned int i = 0; i < vSet->size() - 1; i++) {
            for (unsigned int j = i + 1; j < vSet->size(); j++) {
                if (vSet->at(i) == vSet->at(j)) {
                    dublicateitemsExists = true;
                    break;
                }
            }
            if (dublicateitemsExists) break;
        }
        return dublicateitemsExists;
    }
    void addvalue(int val) {
        vSet->push_back(val);
    }

   public:
    set() {
        vSet = new vector<int>;
    }

    set(vector<int> v) {
        vSet = new vector<int>;
        for (int x : v) {
            // if (!isin(x))
            vSet->push_back(x);
        }

        if (dublicates()) {
            cout << "duplicate exists " << endl;
            vSet->empty();
        }
    }

    void generateRandom(int n, int min, int max) {
        for (int i = 0; true; i++) {
            int randval = rand() % (max - min + 1) + min;
            if (!isin(randval))
                vSet->push_back(randval);
            if (vSet->size() == (unsigned long)n) {
                break;
            }
        }
    }

    set(set& s2) {
        vector<int> vSet(s2.getVector()->begin(), s2.getVector()->end());
    }

    vector<int>* getVector() {
        return vSet;
    }

    friend ostream& operator<<(ostream& out, const set& s);
    friend istream& operator>>(istream& in, set& s);
    set operator+(set& s2) {
        set s3;
        for (int x : *this->vSet) {
            s3.vSet->push_back(x);
        }
        for (int x : *s2.vSet) {
            s3.vSet->push_back(x);
        }
        return s3;
    }

    set operator-(set& s2) {
        set s3;
        //  the set of all the elements of set A which are not there in set B.
        for (int x : *this->vSet) {
            if (!s2.isin(x)) {
                s3.vSet->push_back(x);
            }
        }
        return s3;
    }

    vector<pair<int, int> > operator*(set& s2) {
        vector<pair<int, int> > s3;
        for (unsigned int i = 0; i < this->vSet->size(); i++) {
            for (unsigned int j = 0; j < s2.vSet->size(); j++) {
                pair<int, int> p1;
                p1.first = this->vSet->at(i);
                p1.second = s2.vSet->at(j);
                s3.push_back(p1);
            }
        }

        return s3;
    }

    set operator/(set& s2) {
        set s3;
        if (this->vSet->size() > s2.vSet->size()) {
            for (int x : *this->vSet) {
                if (s2.isin(x)) {
                    s3.vSet->push_back(x);
                }
            }
        } else {
            for (int x : *s2.vSet) {
                if (this->isin(x)) {
                    s3.vSet->push_back(x);
                }
            }
        }
        return s3;
    }
};

// inclusive
int GenerateRandomValue(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void Swap(vector<int>& a, int pos1, int pos2) {
    int temp = a[pos2];
    a[pos2] = a[pos1];
    a[pos1] = temp;
}
void randomize(vector<int>& a) {
    int j = 0;
    while (j < 7) {
        for (unsigned int i = 0; i < a.size(); i++) {
            int pos_to_swap = GenerateRandomValue(0, a.size() - 1);
            Swap(a, pos_to_swap, i);
        }
        j++;
    }
}

ostream& operator<<(ostream& out, set& s) {
    vector<int> temp;
    for (int x : *s.getVector()) {
        temp.push_back(x);
    }
    randomize(temp);

    for (int x : temp) {
        cout << x << " ";
    }
    temp.empty();
    // temp = nullptr;

    return out;
}
istream& operator>>(istream& in, set& s) {
    int ui;
    in >> ui;
    if (!s.isin(ui)) {
        s.vSet->push_back(ui);
    } else {
        cout << "element already exists" << endl;
    }
    return in;
}

int main() {
    srand(time(NULL));
    int size = 4;
    int* arr = new int[size];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;

    vector<int> vec1(arr, arr + size);
    if (arr) {
        delete[] arr;
        arr = nullptr;
    }

    set v1(vec1);
    // for (int i = 0; i < 10; i++) {
    //     cout << v1;
    //     cout << endl;
    // }
    // cout << v1;
    // cout << endl;
    set v2;
    v2.generateRandom(3, 1, 9);

    cout << v1 << endl;

    cout << v2 << endl;
    // // +op and -op
    set v3 = v1 + v2;
    cout << v3 << endl;
    set v4 = v3 - v2;
    cout << v4 << endl;  // same as v1
    // for (pair<int, int> x : (v1 * v2)) {
    //     cout << "(" << x.first << "," << x.second << ") ";
    // }
    set v5 = v3 / v2;
    cout << v5;  //same as v2

    // cout << endl;
    cout << (v1 * v2).size() << endl
         << endl;

    return 0;
}
