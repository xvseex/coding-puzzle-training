#pragma once
#include <stdexcept>

class Queue {
    int* data;
    int capacity, head, count;

    void grow() {
        int* bigger = new int[capacity * 2];
        for (int i = 0; i < count; i++)
            bigger[i] = data[(head + i) % capacity];  // unwrap in order
        delete[] data;
        data = bigger;
        head = 0;
        capacity *= 2;
    }

public:
    Queue() : data(new int[4]), capacity(4), head(0), count(0) {}
    ~Queue() { delete[] data; }
    Queue(const Queue&) = delete;             // avoid double-free
    Queue& operator=(const Queue&) = delete;

    void enqueue(int v) {
        if (count == capacity) grow();
        data[(head + count) % capacity] = v;  // wraps around
        count++;
    }
    int dequeue() {
        if (empty()) throw std::underflow_error("queue is empty");
        int v = data[head];
        head = (head + 1) % capacity;
        count--;
        return v;
    }
    int front() const {
        if (empty()) throw std::underflow_error("queue is empty");
        return data[head];
    }
    bool empty() const { return count == 0; }
    void clear() { head = 0; count = 0; }
    int size() const { return count; }
};
