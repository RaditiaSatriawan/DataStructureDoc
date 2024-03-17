// Assignment March 4, 2024
// Queue
#include <iostream>

using namespace std;

class Queue {
private:
    int size;
    int frontIndex;
    int rearIndex;
    int capacity;
    int *queue;

public:
    Queue(int queueSize) {
        size = 0; // Mulai dengan queue kosong
        capacity = queueSize; // Maksimum kapasistas queue
        queue = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
    }

    void enqueue(int value) {
        // Periksa apakah antrian penuh
        if (size == capacity) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }

        rearIndex = (rearIndex + 1) % capacity;
        queue[rearIndex] = value;
        size++;
    }

    void dequeue() {
        // Periksa apakah antrian kosong
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        frontIndex = (frontIndex + 1) % capacity;
        size--;
    }

    int front() {
        // Periksa apakah antrian kosong
        if (isEmpty()) {
            cout << "Queue is empty. No front element.\n";
            return -1; // or any other suitable default value
        }

        return queue[frontIndex];
    }

    bool isEmpty() {
        return (size == 0);
    }

    int getSize() {
        return size;
    }
};

int main() {
    cout << endl;
    Queue Queue(3);

    Queue.enqueue(5);
    Queue.enqueue(3);
    Queue.enqueue(7);

    cout << "Front element: " << Queue.front() << endl;

    Queue.dequeue();
    cout << "Front element after dequeue: " << Queue.front() << endl;

    Queue.dequeue();
    cout << "Front element after dequeue: " << Queue.front() << endl;

    Queue.dequeue();
    cout << "Front element after dequeue: " << Queue.front() << endl;

    Queue.enqueue(100);

    cout << "Queue size: " << Queue.getSize() << endl;

    while (!Queue.isEmpty()) {
        Queue.dequeue();
    }
    cout << "Queue size after dequeue all: " << Queue.getSize() << endl;

    return 0;
}
