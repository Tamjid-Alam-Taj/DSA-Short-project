#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void merge(vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    vector<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100;
    }
    return arr;
}

void startGame() {
    cout << "Welcome to the Divide and Conquer Sorting Game!" << endl;

    int arraySize;
    cout << "Enter the size of the array you want to sort: ";
    cin >> arraySize;

    vector<int> arr = generateRandomArray(arraySize);

    cout << "Here is the unsorted array: ";
    printArray(arr);

    mergeSort(arr, 0, arr.size() - 1);

    cout << "\nCongratulations! You've successfully sorted the array.\n";
    cout << "Sorted array: ";
    printArray(arr);
}

int main() {
    startGame();
    return 0;
}
