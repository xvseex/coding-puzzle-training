#include <cassert>
#include <iostream>
#include "queue.hpp"

int main() {
    Queue q;
    assert(q.empty());

    for (int i = 1; i <= 10; i++) q.enqueue(i);   // forces grow()
    assert(q.size() == 10 && q.front() == 1);

    for (int i = 1; i <= 5; i++) assert(q.dequeue() == i);  // FIFO order

    for (int i = 11; i <= 20; i++) q.enqueue(i);  // wraps + grows
    for (int i = 6; i <= 20; i++) assert(q.dequeue() == i);
    assert(q.empty());

    bool threw = false;
    try { q.dequeue(); } catch (const std::underflow_error&) { threw = true; }
    assert(threw);

    // Wrap test: head wraps around many times
    Queue w;
    for (int i = 0; i < 100; i++) {
        w.enqueue(i);
        assert(w.dequeue() == i);
    }
    assert(w.empty());

    // clear() test
    Queue c;
    c.enqueue(1);
    c.enqueue(2);
    c.clear();
    assert(c.empty());
    assert(c.size() == 0);

    std::cout << "All queue tests passed\n";
}
