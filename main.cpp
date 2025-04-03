#include <iostream>
#include "MyStack.h"
using namespace std;
int main() {
    MyStack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Top element: " << stack.top() << endl; // 30
    stack.pop();
   cout << "Top element after pop: " << stack.top() << endl; // 20
    stack.pop();
    stack.pop();

    // This should throw an exception
    try {
        stack.pop();
    } catch (const std::logic_error &e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    return 0;
}
