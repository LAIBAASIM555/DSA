#include <iostream>
using namespace std;
class queue
{
    int front;
    int rear;
    int size;
    int *Q;

public:
    queue()
    {
        front = rear = -1;
        size = 10;
        Q = new int[size];
    }
    queue(int size)
    {
        front = rear = 0;
        this->size = size;
        Q = new int[this->size];
    }
    void enqueue(int x);
    int dequeue();
    void display();

};
void queue::enqueue(int x)
{
    if ((rear+1)% size== front)
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        rear=(rear+1)% size;
        Q[rear] = x;
    }
}
int queue::dequeue()
{
    int x = -1;
    if (front == rear)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        front=(front+1)% size;
        x=Q[front];
        return x;
    }
}
void queue::display()
{
    int i;
    if (front == rear)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        for (i = front + 1; i <= rear; i++)
        {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    queue q(10);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}