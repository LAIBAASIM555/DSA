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

class CircularDoublyLinkedList {
public:
    Node *head;

    CircularDoublyLinkedList() {
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
        last->next = head;
        head->prev = last;
    }

    void Display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node *p = head;
        do {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
        cout << endl;
    }

    int count() {
        int c = 0;
        Node *p = head;
        do {
            c++;
            p = p->next;
        } while (p != head);
        return c;
    }

    void insert(int pos, int x) {
    // Initialize a temporary pointer 'p' to point to the head of the list
    Node *p = head;
    
    // Initialize another temporary pointer 't' to hold the new node to be inserted
    Node *t = new Node(x);

    // Check if the position 'pos' is less than 0 or greater than the current count of nodes in the list
    if (pos < 0 || pos > count()) {
        // Print an error message indicating an invalid position
        cout << "Invalid position" << endl;
        // Return without modifying the list
        return;
    }

    // If the position is 0, meaning the insertion should happen at the beginning of the list
    if (pos == 0) {
        // The new node 't' becomes the new head of the list
        t->prev = head->prev;
        t->next = head;
        // Update the previous pointer of the old head to point to the new node
        head->prev->next = t;
        // Update the previous pointer of the new node to point to the old head
        head->prev = t;
        // Update the head pointer of the list to point to the new node
        head = t;
    } else {
        // If the position is not 0, iterate through the list until reaching the node just before the desired insertion position
        for (int i = 0; i < pos - 1; i++) {
            p = p->next;
        }
        // Insert the new node 't' between the node found ('p') and its next node ('p->next')
        t->next = p->next;
        t->prev = p;
        // Update the next pointer of the node at the target position ('p') to point to the new node 't'
        p->next->prev = t;
        // Update the next pointer of the new node 't' to point to the node following the target position
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
            head->prev->next = head->next;
            head->next->prev = head->prev;
            x = head->data;
            delete head;
            head = head->next;
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
        p->next->prev = p;
        delete temp;
    }

    void reverse() {
        Node *p = head;
        Node *temp = nullptr;

        do {
            temp = p->next;
            p->next = p->prev;
            p->prev = temp;
            p = temp;
        } while (p != head);

        head = head->prev;
    }
};

int main() {
    int A[] = {3, 5, 10, 15, 25, 28, 32, 42, 53, 64};

    CircularDoublyLinkedList list;
    list.create(A, 10);
    cout << "Circular Doubly Linked List: ";
    list.Display();
    cout << "Count: " << list.count() << endl;
    cout << "Inserting 27 at position 4: ";
    list.insert(4, 27);
    list.Display();
    cout << "Deleting node at position 6: ";
    list.del(6);
    list.Display();
    cout << "Reversed Circular Doubly Linked List: ";
    list.reverse();
    list.Display();
    return 0;
}