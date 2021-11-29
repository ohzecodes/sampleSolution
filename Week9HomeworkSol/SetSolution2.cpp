#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

struct Pair {
    int first;
    int second;
};

class Set {
   private:
    vector<int> items;
    bool IsInSet(int item) const {
        for (int i = 0; i < items.size(); i++) {
            if (items[i] == item) {
                return true;
            }
        }
        return false;
    }
    void Swap(int left, int right) {
        int temp = items[left];
        items[left] = items[right];
        items[right] = temp;
    }

   public:
    Set() {
        items.clear();
    }

    Set(vector<int> inData) {
        SetItems(inData);
    }

    Set(const Set& that) {
        *this = that;
    }

    Set(int n, int min, int max) {
        SetItems(n, min, max);
    }

    ~Set() {
        cout << "\n\n\nGarbage Collector << \"Clean up after yourself please, I am busy cleaning up after Java programmers. Have a nice day!\"" << endl;
    }

    vector<int> GetItems() {
        return items;
    }

    void SetItems(vector<int> inData) {
        for (int i = 0; i < inData.size(); i++) {
            AddToSet(inData[i]);
        }
    }

    void SetItems(int n, int min, int max) {
        GenerateRandom(n, min, max);
    }

    bool AddToSet(int item) {
        if (!IsInSet(item)) {
            items.push_back(item);
            return true;
        }
        cout << "Item " << item << " already in set." << endl;
        return false;
    }

    void GenerateRandom(int n, int min, int max) {
        int range = max - min + 1;
        int offset = min;
        int item, i;

        srand(time(0));

        if (range >= n) {
            i = 0;
            while (i < n) {
                item = (int)rand() % range + offset;
                if (AddToSet(item)) {
                    i++;
                }
            }
        } else {
            cout << "Invalid parameters set for randomization purposes. Range must be equal or greater than number of items requested" << endl;
        }
    }

    void Randomize() {
        for (int i = 0; i < items.size(); i++) {
            int randI = (int)rand() % (int)items.size();

            Swap(i, randI);
        }
    }

    vector<vector<int> > Split(vector<int> arr, int indexToSplitAt) {
        vector<vector<int> > splits;  //items to the left of indexToSplitAt at index 0, items to the right of indexToSplitAt at index 1

        if (indexToSplitAt != 0) {
            vector<int> s;  //items from arr[0] to arr[indexToSplitAt-1] (inclusive)
            s.insert(s.begin(), arr.begin(), arr.begin() + indexToSplitAt);
            s.shrink_to_fit();
            splits.push_back(s);
        } else {
            vector<int> s;
            splits.push_back(s);
        }

        if (arr.size() - indexToSplitAt != 0) {
            vector<int> s;  // items from arr[indexToSplitAt] to arr[size - 1] (inclusive)
            s.insert(s.begin(), arr.begin() + indexToSplitAt, arr.end());
            s.shrink_to_fit();
            splits.push_back(s);
        } else {
            vector<int> s;
            splits.push_back(s);
        }

        return splits;
    }

    vector<int> MergeInOrder(vector<int> left, vector<int> right) {
        int i, j, k;
        // this merge assumes all items in left are smaller than the FIRST item in right
        vector<int> merged(left.size() + right.size());
        // initialize all loop indices
        i = j = k = 0;

        // merge the items from each vector in order (assuming both left and right are already sorted in ascending order) until one of them runs out of items
        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                merged[k++] = left[i++];
            } else {
                merged[k++] = right[j++];
            }
        }
        // either left or right may have items left to merge
        //remaining items in left, append in order to the end of merged
        while (i < left.size()) {
            merged[k++] = left[i++];
        }
        // similarly do for right, append in order to the end of merged
        while (j < right.size()) {
            merged[k++] = right[j++];
        }

        return merged;
    }

    vector<int> MergeSort(vector<int> arr) {
        if (arr.size() <= 1) {
            return arr;
        } else {
            int splitIndex = arr.size() / 2;

            vector<vector<int> > slices = Split(arr, splitIndex);
            vector<int> left = slices[0];   //items to the left of splitIndex (including splitIndex itself)
            vector<int> right = slices[1];  //items to the right of splitIndex

            left = MergeSort(left);
            right = MergeSort(right);

            vector<int> sortedArr = MergeInOrder(left, right);

            return sortedArr;
        }
    }

    void Sort() {
        items = MergeSort(items);
    }

    Set& operator+(const Set& right) {
        Set* uni = new Set();
        uni->SetItems(items);
        uni->SetItems(right.items);
        return *uni;
    }

    Set& operator-(const Set& right) {
        Set* diff = new Set();

        for (int i = 0; i < items.size(); i++) {
            if (!(right.IsInSet(items[i]))) {
                diff->AddToSet(items[i]);
            }
        }
        return *diff;
    }

    Set& operator/(const Set& right) {
        Set* intersec = new Set();

        for (int i = 0; i < items.size(); i++) {
            if (right.IsInSet(items[i])) {
                intersec->AddToSet(items[i]);
            }
        }
        return *intersec;
    }

    vector<Pair>& operator*(const Set& right) {
        vector<Pair>* cartProd = new vector<Pair>();
        Pair p;
        for (int i = 0; i < items.size(); i++) {
            p.first = items[i];
            for (int j = 0; j < right.items.size(); j++) {
                p.second = right.items[j];
                cartProd->push_back(p);
            }
        }
        return *cartProd;
    }

    friend ostream& operator<<(ostream& out, const Set& outSet);

    friend ostream& operator<<(ostream& out, vector<Pair>& v);
};

ostream& operator<<(ostream& out, const Set& outSet) {
    out << "{ ";
    for (int i = 0; i < (int)outSet.items.size() - 1; i++) {
        out << outSet.items[i] << ", ";
    }
    out << outSet.items[(int)outSet.items.size() - 1] << " }" << endl;
    return out;
}

ostream& operator<<(ostream& out, vector<Pair>& v) {
    out << "{ ";
    for (int i = 0; i < (int)v.size() - 1; i++) {
        out << "( " << v[i].first << ", " << v[i].second << ")"
            << ", ";
    }
    out << "( " << v[(int)v.size() - 1].first << ", " << v[(int)v.size() - 1].second << ")"
        << " }" << endl;
    return out;
}

int main() {
    Set s1 = Set(5, 1, 10);
    Set s2 = Set(5, 5, 15);

    cout << "Set1" << endl;
    cout << "Number of Items: " << s1.GetItems().size() << endl;
    cout << "Items: " << s1;
    s1.Sort();
    cout << "Items: " << s1;

    cout << "-------------" << endl;

    cout << "Set2" << endl;
    cout << "Number of Items: " << s2.GetItems().size() << endl;
    cout << "Items: " << s2;

    cout << "-------------" << endl;

    cout << "Union of sets" << endl;
    cout << "Number of Items: " << (s1 + s2).GetItems().size() << endl;
    cout << "Items: " << (s1 + s2);

    cout << "-------------" << endl;

    cout << "Defference of sets (s1 - s2)" << endl;
    cout << "Number of Items: " << (s1 - s2).GetItems().size() << endl;
    cout << "Items: " << (s1 - s2);

    cout << "-------------" << endl;

    cout << "Intersectio of sets" << endl;
    cout << "Number of Items: " << (s1 / s2).GetItems().size() << endl;
    cout << "Items: " << (s1 / s2);

    cout << "-------------" << endl;

    cout << "Cartesian Product" << endl;
    cout << "Number of Items: " << (s1 * s2).size() << endl;
    cout << "Items: " << (s1 * s2);
}
