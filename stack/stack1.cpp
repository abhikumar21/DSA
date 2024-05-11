#include <bits/stdc++.h>
using namespace std;

class Stack {
    private: 
        int arr[1000]; // Assuming a fixed size for simplicity
        int top;
    public:
        Stack() {
            top=-1;
        } // Constructor initializer list to initialize top
        void pop();
        void push(int);
        int getTop(); // Function to get the top element of the stack
};

void Stack::push(int x) {
    top++;
    arr[top] = x;
}

void Stack::pop() {
    if (top == -1) {
        cout << "Stack is empty!" << endl;
    } else {
        top--;
    }
}

int Stack::getTop() {
    if (top == -1) {
        cout << "Stack is empty!" << endl;
        return -1; // Return -1 if stack is empty
    }
    return arr[top];
}

int main() {
    Stack myStack;
    myStack.push(5);
    myStack.push(4);
    myStack.push(8);
    myStack.push(1);
    cout << myStack.getTop() << endl; // Output the top element
    myStack.pop(); // Pop an element
    cout << myStack.getTop() << endl; // Output the new top element after popping
    return 0;
}
