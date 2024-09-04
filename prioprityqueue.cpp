#include<iostream>
using namespace std;

class priority {
    int front;
    int size;
    int *q;

public:
    priority() {
        size = 10;
        q = new int[size];
        front = -1;
    }
    priority(int size) {
        this->size = size;
        q = new int[size];
        front = -1;
    }
    void display() {
        for(int i = 0; i <= front; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }
    void insert(int x) {
        if(front == size - 1) {
            cout << "Queue is full" << endl;
            return;
        }
        front+1;
        int i;
        for(i = front; i > 0 && q[i - 1] < x; i--) {
            q[i] = q[i - 1];
        }
        q[i] = x;
    }
    int del() {
        if(front == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int x = q[0];
        for(int i = 0; i < front; i++) {
            q[i] = q[i + 1];
        }
        front--;
        return x;
    }
};

int main() {
    priority q(5);
    q.insert(5);
    q.insert(10);
    q.insert(3);
    q.insert(8);
    q.insert(1);

    q.display(); // 10 8 5 3 1

    cout << "Deleted: " << q.del() << endl; // 10
    cout << "Deleted: " << q.del() << endl; // 8

    q.display(); // 5 3 1

    return 0;
}