#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> heap;

    // Helper: Heapify up
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else break;
        }
    }

    // Helper: Heapify down
    void heapifyDown(int index) {
        int n = heap.size();
        while (true) {
            int left = 2*index + 1;
            int right = 2*index + 2;
            int largest = index;

            if (left < n && heap[left] > heap[largest]) largest = left;
            if (right < n && heap[right] > heap[largest]) largest = right;

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else break;
        }
    }

public:
    // Insert element
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    // Remove highest priority element
    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    // Get highest priority element
    int top() {
        if (heap.empty()) throw runtime_error("Priority Queue is empty");
        return heap[0];
    }

    // Check if empty
    bool empty() {
        return heap.empty();
    }

    // Size of queue
    int size() {
        return heap.size();
    }
};

int main() {
    PriorityQueue pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    cout << "Priority Queue size: " << pq.size() << endl;

    cout << "Top element (highest priority): " << pq.top() << endl;

    pq.pop();
    cout << "After pop, new top: " << pq.top() << endl;

    cout << "Remaining elements (in priority order): ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}
