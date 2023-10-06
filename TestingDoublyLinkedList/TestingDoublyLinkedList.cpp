// TestingDoublyLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept> 

struct ListNode {
    int value;
    ListNode* prev;
    ListNode* next;

    ListNode(int val, ListNode* p = nullptr, ListNode* n = nullptr)
        : value(val), prev(p), next(n) {} 
};

class List {
public:
    List() : m_head(new ListNode(0)), m_size(0), m_tail(new ListNode(0)) {
        m_head->next = m_tail;
        m_tail->prev = m_head;
    }

    ~List() {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() const { return m_size == 0; }

    unsigned long Size() const { return m_size; }

    void PushFront(int value) {
        InsertAfter(m_head, value);
    }

    void PushBack(int value) {
        InsertBefore(m_tail, value);
    }

    int PopFront() {
        if (Empty()) throw std::runtime_error("list is empty");
        return Remove(m_head->next);
    }

    int PopBack() {
        if (Empty()) throw std::runtime_error("list is empty");
        return Remove(m_tail->prev);
    }

    void Clear() {
        while (!Empty()) {
            PopFront();
        }
    }

private:
    void InsertAfter(ListNode* node, int value) {
        auto new_node = new ListNode(value);
        new_node->prev = node;
        new_node->next = node->next;
        node->next->prev = new_node;
        node->next = new_node;
        ++m_size;
    }

    void InsertBefore(ListNode* node, int value) {
        InsertAfter(node->prev, value);
    }

    int Remove(ListNode* node) {
        auto prev_node = node->prev;
        auto next_node = node->next;
        prev_node->next = next_node;
        next_node->prev = prev_node;
        int value = node->value;
        delete node;
        --m_size;
        return value;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};

/*int main() {
    List myList;
    myList.PushBack(1);
    myList.PushBack(2);
    myList.PushBack(3);

    std::cout << "Size: " << myList.Size() << std::endl;

    while (!myList.Empty()) {
        std::cout << myList.PopFront() << " ";
    }

    return 0;
}*/


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
