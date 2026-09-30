#include <iostream>
#include <stdexcept>
#include <cassert>

class Stack {
private:
    int* data;
    int capacity;
    int count;

    void grow() {
        int newCapacity = capacity * 2;
        int* newData = new int[newCapacity];
        for (int i = 0; i < count; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Stack(int cap) {
        capacity = cap;
        data = new int[capacity];
        count = 0;
    }

    ~Stack() {
        delete[] data;
    }

    void push(int value) {
        if (count == capacity) {
            grow();
        }
        data[count] = value;
        count = count + 1;
    }

    int pop() {
        if (isEmpty()) {
            throw std::out_of_range("pop on empty stack");
        }
        count = count - 1;
        return data[count];
    }

    int peek() {
        if (isEmpty()) {
            throw std::out_of_range("peek on empty stack");
        }
        return data[count - 1];
    }

    bool isEmpty() {
        return count == 0;
    }
};

int main() {
    // empty
    Stack s(2);
    assert(s.isEmpty());

    // single element
    s.push(10);
    assert(s.peek() == 10);
    assert(!s.isEmpty());
    assert(s.pop() == 10);
    assert(s.isEmpty());

    // growth past initial capacity
    for (int i = 1; i <= 50; i++) {
        s.push(i);
    }
    assert(!s.isEmpty());
    for (int i = 50; i >= 1; i--) {
        assert(s.pop() == i);
    }
    assert(s.isEmpty());

    // invalid operation
    bool threw = false;
    try {
        s.pop();
    } catch (const std::out_of_range&) {
        threw = true;
    }
    assert(threw);

    std::cout << "Stack tests passed" << std::endl;
    return 0;
}
