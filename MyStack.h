#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>

template <typename T>
class MyStack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value, Node* nextNode = nullptr) : data(value), next(nextNode) {}
    };

    Node* top;
    int size;

public:
    MyStack();
    ~MyStack();

    void push(T value);
    void pop();
    T peek() const;
    bool isEmpty() const;
    int getSize() const;
    void printStack() const;
};

// Constructor
template <typename T>
MyStack<T>::MyStack() : top(nullptr), size(0) {}

// Destructor
template <typename T>
MyStack<T>::~MyStack() {
    while (!isEmpty()) {
        pop();
    }
}

// Push element onto stack
template <typename T>
void MyStack<T>::push(T value) {
    Node* newNode = new Node(value, top);
    top = newNode;
    size++;
}

// Pop element from stack
template <typename T>
void MyStack<T>::pop() {
    if (isEmpty()) {
        std::cerr << "Stack underflow: Cannot pop from an empty stack.\n";
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
    size--;
}

// Peek top element
template <typename T>
T MyStack<T>::peek() const {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty. Cannot peek.");
    }
    return top->data;
}

// Check if stack is empty
template <typename T>
bool MyStack<T>::isEmpty() const {
    return top == nullptr;
}

// Get size of stack
template <typename T>
int MyStack<T>::getSize() const {
    return size;
}

// Print stack elements
template <typename T>
void MyStack<T>::printStack() const {
    Node* current = top;
    std::cout << "Stack (top to bottom): ";
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

#endif // MYSTACK_H
