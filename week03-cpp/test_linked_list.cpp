#include <cassert>
#include <iostream>
#include "linked_list.hpp"

int main() {
    LinkedList l;
    assert(l.empty() && l.size() == 0);

    l.push_back(2);
    l.push_back(3);
    l.push_front(1);                       // list: 1 2 3
    assert(l.size() == 3);
    assert(l.at(0) == 1 && l.at(1) == 2 && l.at(2) == 3);

    assert(l.contains(2));
    assert(!l.contains(99));

    assert(l.remove(2));                   // middle: 1 3
    assert(l.size() == 2 && l.at(1) == 3);
    assert(l.remove(1));                   // head: 3
    assert(l.at(0) == 3);
    assert(l.remove(3));                   // only element: empty
    assert(l.empty());
    assert(!l.remove(42));                 // not found

    l.push_back(10);
    l.push_back(20);
    assert(l.pop_front() == 10);
    assert(l.pop_front() == 20);

    bool threw = false;
    try { l.pop_front(); } catch (const std::underflow_error&) { threw = true; }
    assert(threw);

    threw = false;
    try { l.at(0); } catch (const std::out_of_range&) { threw = true; }
    assert(threw);

    // leak check: leave nodes in the list; the destructor must free them
    LinkedList big;
    for (int i = 0; i < 1000; i++) big.push_back(i);
    assert(big.size() == 1000 && big.at(999) == 999);

    std::cout << "All linked list tests passed\n";
}
