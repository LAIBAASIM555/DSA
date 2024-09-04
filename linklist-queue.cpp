#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
node *front = nullptr;
node *rear = nullptr;

void inqueue(int x){
    node *t = new node;
    t->data = x;
    t->next = nullptr;
    if (front == nullptr)
        front = rear = t;
    else {
        rear->next = t;
        rear = t;
    }
}

int dequeue(){
    int x = -1;
    node *p;
    if (front == nullptr)
        cout << "Queue is empty" << endl;
    else {
        p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}

int main(){
    inqueue(10);
    inqueue(20);
    inqueue(30);
    inqueue(40);
    inqueue(50);

    // test dequeue
    cout << dequeue() << endl; // 10
    cout << dequeue() << endl; // 20
    

    return 0;
}