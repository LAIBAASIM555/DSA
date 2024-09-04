#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList {
public:
    Node *head;

    LinkedList() {
        head = nullptr;
    }

    void create(int A[], int n) {
        Node *last = nullptr;
        for (int i = 0; i < n; i++) {
            Node *temp = new Node(A[i]);
            if (head == nullptr) {
                head = temp;
                last = head;
            } else {
                last->next = temp;
                temp->prev = last;
                last = temp;
            }
        }
    }

    void Display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node *p = head;
        while (p != nullptr) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    int count() {
        int c = 0;
        Node *p = head;
        while (p != nullptr) {
            c++;
            p = p->next;
        }
        return c;
    }

    void insert(int pos, int x) {
        Node *p = head;
        Node *t = new Node(x);

        if (pos < 0 || pos > count()) {
            cout << "Invalid position" << endl;
            return;
        }

        if (pos == 0) {
            t->prev = nullptr;
            t->next = head;
            if (head != nullptr) {
                head->prev = t;
            }
            head = t;
        } else {
            for (int i = 0; i < pos - 1; i++) {
                p = p->next;
            }
            t->next = p->next;
            t->prev = p;
            if (p->next != nullptr) {
                p->next->prev = t;
            }
            p->next = t;
        }
    }

    void del(int pos) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node *p = head;
        int x;

        if (pos == 0) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete p;
            return;
        }

        for (int i = 0; i < pos - 1; i++) {
            p = p->next;
        }

        if (p == nullptr || p->next == nullptr) {
            cout << "Position out of range" << endl;
            return;
        }

        x = p->next->data;
        Node* temp = p->next;
        p->next = p->next->next;
        if (p->next != nullptr) {
            p->next->prev = p;
        }
        delete temp;

        if (p->next == nullptr) {
            head = p;
        }
    }

    void reverse() {
        Node *p = head;
        Node *temp = nullptr;

        while (p) {
            temp = p->next;
            p->next = p->prev;
            p->prev = temp;
           if (p&&p->prev == nullptr) {
            head = p;
        }
        p = temp;
    }
    }
};
int main()
{
    int A[] = {3, 5, 10, 15, 25, 28, 32, 42,53,64};

    LinkedList list;
    list.create(A, 10);
    cout<<"Doubly Linklist : ";
    list.Display();
    // cout << "Count : ";
    // cout << list.count();
    // cout<<"Insert : ";
    // list.insert(4,27);
    // list.Display();
    // cout<<"Delete : ";
    // list.del(6);
    // list.Display();
    cout << "Reversed Doubly Linked List: ";
    list.reverse();
    list.Display();
    return 0;
}