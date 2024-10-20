#include <iostream>
#include <vector>
#include <stdexcept>

template <class T>
class PriorityQueue {
private:
    std::vector<T> heap;  // The min-heap to store the priority queue elements

    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] < heap[parentIndex]) {
                std::swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int leftChild, rightChild, smallest, size = heap.size();
        while ((leftChild = 2 * index + 1) < size) {
            rightChild = leftChild + 1;
            smallest = index;

            if (heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }

            if (rightChild < size && heap[rightChild] < heap[smallest]) {
                smallest = rightChild;
            }

            if (smallest != index) {
                std::swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    PriorityQueue() {}

    void insert(T value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    T extractMin() {
        if (heap.empty()) {
            throw std::runtime_error("Priority queue is empty");
        }
        T minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
        return minValue;
    }

    T peekMin() const {
        if (heap.empty()) {
            throw std::runtime_error("Priority queue is empty");
        }
        return heap[0];
    }

    bool isEmpty() const {
        return heap.empty();
    }
};

int main() {
    PriorityQueue<int> pq;
    pq.insert(30);
    std::cout << "Inserted: 30" << std::endl;
    pq.insert(20);
    std::cout << "Inserted: 20" << std::endl;
    pq.insert(10);
    std::cout << "Inserted: 10" << std::endl;
    pq.insert(50);
    std::cout << "Inserted: 50" << std::endl;
    pq.insert(40);
    std::cout << "Inserted: 40" << std::endl;
    pq.insert(5);
    std::cout << "Inserted: 5" << std::endl;

    std::cout << "\nPeek minimum: " << pq.peekMin() << std::endl;

    while (!pq.isEmpty()) {
        std::cout << "Extracted minimum: " << pq.extractMin() << std::endl;
    }

    return 0;
}