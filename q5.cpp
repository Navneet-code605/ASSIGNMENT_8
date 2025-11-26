#include <iostream>
#include <vector>
using namespace std;

// Heapify function for max-heap
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;       // root
    int left = 2*i + 1;    // left child
    int right = 2*i + 2;   // right child

    // If left child is larger
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heapsort for increasing order
void heapSortIncreasing(vector<int>& arr) {
    int n = arr.size();

    // Build max-heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements one by one
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);   // Move current root to end
        heapify(arr, i, 0);     // Heapify reduced heap
    }
}

// Heapify function for min-heap
void heapifyMin(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

// Heapsort for decreasing order
void heapSortDecreasing(vector<int>& arr) {
    int n = arr.size();

    // Build min-heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    // Extract elements one by one
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);   // Move current root to end
        heapifyMin(arr, i, 0);  // Heapify reduced heap
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    // Increasing order
    vector<int> incArr = arr;
    heapSortIncreasing(incArr);
    cout << "Sorted (Increasing): ";
    for (int x : incArr) cout << x << " ";
    cout << endl;

    // Decreasing order
    vector<int> decArr = arr;
    heapSortDecreasing(decArr);
    cout << "Sorted (Decreasing): ";
    for (int x : decArr) cout << x << " ";
    cout << endl;

    return 0;
}
