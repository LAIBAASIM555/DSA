#include<iostream>
using namespace std;

class stack {
    int size;
    int top;
    int *s;

public:
    stack(int sz) {
        size = sz; 
        s = new int[size]; 
        top = -1; 
    }
    void display() {
        for (int i = top; i >= 0; i--) {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    void push(int x) {
        if (isfull()) {
            cout << "Stack is full" << endl;
        } else {
            top++;
            s[top] = x;
        }
    }
    int pop() {
        int x = -1;
        if (isempty()) {
            cout << "Stack is empty" << endl;
        } else {
            x = s[top];
            top--;
        }
        return x;
    }
    int peek(int index) {
        int x = -1; //empty top
        if (top - index  < 0) {
            cout << "Invalid" << endl;
        } else {
            x = s[top -index + 1];
        }
        return x;
    }
    bool isfull() {
        if (top == size - 1) {
            return true;
        } else {
            return false;
        }
    }
    bool isempty() {
        if (top == -1) {
            return true;
        } else {
            return false;
        }
    }
    void stacktop() {
        if (!isempty()) {
            cout << "Top element = " << s[top] << endl;
        } else {
            cout << "Stack is empty" << endl;
        }
    }
};

int main() {
    stack s1(10);
    cout << "Enter elements: ";
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        s1.push(x);
    }
    s1.display();
    cout << endl;
    s1.pop();
    cout << "POP ";
    s1.display();
    cout << endl;
    s1.push(3);
    cout << "PUSH ";
    s1.display();
    cout << endl;
    if (!s1.isempty()) {
        cout << "EMPTY ";
        s1.display();
    }
    cout << endl;
    cout << "PEEK ";
    cout << "Element at position 1 = " << s1.peek(1) << endl;
    s1.display();
    cout << endl;
    s1.stacktop();
    return 0;
}