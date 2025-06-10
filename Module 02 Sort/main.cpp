#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <random>
#include <stdexcept>

using namespace std;

// Check input validity
bool checkAvailable(const vector<int>& inputList) {
    set<int> seen;
    for (int val : inputList) {
        if (val == 0) return false;
        if (seen.find(val) != seen.end()) return false;
        seen.insert(val);
    }
    return true;
}

// Selection Sort
vector<int> SelectionSort(vector<int> arr) {
    if (!checkAvailable(arr)) throw invalid_argument("InappropriateInput");

    vector<int> output;
    while (!arr.empty()) {
        auto min_it = min_element(arr.begin(), arr.end());
        output.push_back(*min_it);
        arr.erase(min_it);
    }
    return output;
}

// Insertion helper
vector<int> Insertion(vector<int> inputList, int elem) {
    if (!checkAvailable(inputList)) throw invalid_argument("InappropriateInput");

    auto it = inputList.begin();
    while (it != inputList.end() && *it < elem) ++it;
    inputList.insert(it, elem);
    return inputList;
}

// Insertion Sort
vector<int> InsertionSort(const vector<int>& inputList) {
    if (!checkAvailable(inputList)) throw invalid_argument("InappropriateInput");

    vector<int> output;
    for (int i : inputList) {
        output = Insertion(output, i);
    }
    return output;
}

// Merge Sort
vector<int> MergeSort(vector<int> inputList) {
    if (!checkAvailable(inputList)) throw invalid_argument("InappropriateInput");

    if (inputList.size() <= 1) return inputList;

    int mid = inputList.size() / 2;
    vector<int> left(inputList.begin(), inputList.begin() + mid);
    vector<int> right(inputList.begin() + mid, inputList.end());

    left = MergeSort(left);
    right = MergeSort(right);

    vector<int> merged;
    size_t i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) merged.push_back(left[i++]);
        else merged.push_back(right[j++]);
    }
    while (i < left.size()) merged.push_back(left[i++]);
    while (j < right.size()) merged.push_back(right[j++]);

    return merged;
}

// Shell Sort
vector<int> ShellSort(vector<int> inputList) {
    if (!checkAvailable(inputList)) throw invalid_argument("InappropriateInput");

    int n = inputList.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = inputList[i];
            int j;
            for (j = i; j >= gap && inputList[j - gap] > temp; j -= gap) {
                inputList[j] = inputList[j - gap];
            }
            inputList[j] = temp;
        }
    }
    return inputList;
}

// QuickSort
vector<int> QuickSort(const vector<int>& inputList) {
    if (!checkAvailable(inputList)) throw invalid_argument("InappropriateInput");

    vector<int> leftPart, rightPart;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, inputList.size() - 1);

    int pivot = inputList[dis(gen)];
    while (pivot == *min_element(inputList.begin(), inputList.end()) ||
           pivot == *max_element(inputList.begin(), inputList.end())) {
        pivot = inputList[dis(gen)];
    }

    for (int val : inputList) {
        if (val < pivot) leftPart.push_back(val);
        else if (val > pivot) rightPart.push_back(val);
    }

    sort(leftPart.begin(), leftPart.end());
    sort(rightPart.begin(), rightPart.end());

    vector<int> result = leftPart;
    result.push_back(pivot);
    result.insert(result.end(), rightPart.begin(), rightPart.end());

    return result;
}

// Print helper
void printVector(const vector<int>& vec) {
    for (int v : vec) cout << v << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {4, 9, 1, 5, 2};

    try {
        cout << "InsertionSort: ";
        printVector(InsertionSort(arr));

        cout << "MergeSort: ";
        printVector(MergeSort(arr));

        cout << "ShellSort: ";
        printVector(ShellSort(arr));

        cout << "QuickSort: ";
        printVector(QuickSort(arr));

        cout << "SelectionSort: ";
        printVector(SelectionSort(arr));
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
