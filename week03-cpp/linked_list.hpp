#pragma once
#include <stdexcept>

class LinkedList {
    struct Node {
        int value;
        Node* next;
        Node(int v, Node* n = nullptr) : value(v), next(n) {}
    };

    Node* head;
    int count;

public:
    LinkedList() : head(nullptr), count(0) {}
    ~LinkedList() { clear(); }
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void push_front(int v) {
        head = new Node(v, head);   // new node points at old head
        count++;
    }

    void push_back(int v) {
        Node* n = new Node(v);
        if (!head) {
            head = n;
        } else {
            Node* cur = head;
            while (cur->next) cur = cur->next;   // walk to the last node
            cur->next = n;
        }
        count++;
    }

    int pop_front() {
        if (!head) throw std::underflow_error("list is empty");
        Node* old = head;
        int v = old->value;
        head = head->next;   // move head forward BEFORE deleting
        delete old;
        count--;
        return v;
    }

    bool contains(int v) const {
        for (Node* cur = head; cur; cur = cur->next)
            if (cur->value == v) return true;
        return false;
    }

    int at(int index) const {
        if (index < 0 || index >= count)
            throw std::out_of_range("index out of range");
        Node* cur = head;
        for (int i = 0; i < index; i++) cur = cur->next;
        return cur->value;
    }

    bool remove(int v) {   // removes first match
        Node* prev = nullptr;
        Node* cur = head;
        while (cur && cur->value != v) {
            prev = cur;
            cur = cur->next;
        }
        if (!cur) return false;                 // not found
        if (prev) prev->next = cur->next;       // skip over it
        else head = cur->next;                  // it was the head
        delete cur;
        count--;
        return true;
    }

    void clear() {
        while (head) {
            Node* nxt = head->next;   // save before deleting
            delete head;
            head = nxt;
        }
        count = 0;
    }

    int size() const { return count; }
    bool empty() const { return count == 0; }
};
