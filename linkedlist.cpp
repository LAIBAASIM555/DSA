#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    { // Constructor
        this->data = data;
        next = nullptr;
    }
};
class LinkedList
{
public:
    Node *head; // first
    Node *second;
    Node *third;
    LinkedList()
    {
        head = nullptr; // Default Constructor
        second = nullptr;
        third = nullptr;
    }
    void create(int A[], int n)
    {                      
        Node *last = nullptr; // last = 0
        for (int i = 0; i < n; i++)
        {
            Node *temp = new Node(A[i]); // create new node for next value
            if (head == nullptr)
            {                // It mean first node is empty
                head = temp; // assign value to first node
                last = head; // initialize last to head
            }
            else
            {
                // If first node is not 0 then initiaize next node
                last->next = temp;
                last = temp; // update last to the new node
            }
        }
    }
    void Display()
    {
        Node *p = head; // p=pointer to node
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    void RDisplay(Node *p)
    { // Recursive Function
        if (p != nullptr)
        {
            RDisplay(p->next);
            cout << p->data << " ";
        }
    }
    int count()
    {
        int c = 0;
        Node *p = head; // assuming head is the first node of the linked list
        while (p != nullptr)
        {
            c++;
            p = p->next;
        }
        return c;
    }
    int count(Node *p)
    {
        int x = 0;
        if (p)
        {
            x = count(p->next);
            return x + 1;
        }
        else
            return x;
    }
    int add()
    {
        int sum = 0;
        Node *p = head; // assuming head is the first node of the linked list
        while (p != nullptr)
        {
            sum = sum + p->data;
            p = p->next;
        }
        return sum;
    }
    int add(Node *p)
    { // Recursive version of add
        if (p == nullptr)
        {
            return 0;
        }
        else
        {
            return p->data + add(p->next);
        }
    }
    int maxi()
    {
        int max = INT32_MIN;
        Node *p = head;
        while (p)
        {
            if (p->data > max)
            {
                max = p->data;
            }
            p = p->next;
        }
        return max;
    }
    int Rmaxi(Node *p)
    { // Recursive version
        int x = 0;
        if (p == nullptr)
        {
            return INT32_MIN;
        }
        else
        {
            x = Rmaxi(p->next);
            if (x > p->data)
                return x;
        }
        return p->data;
    }
    int search(int key)
    {
        Node *p = head;
        while (p != NULL)
        {
            if (p->data == key)
            {
                return p->data;
            }
            else
                p = p->next;
        }
        return 0;
    }
    int Rsearch(Node *p, int key)
    {
        if (p == NULL)
            return 0;
        if (key == p->data)
            return p->data;
        return Rsearch(p->next, key);
    }
    int Isearch(Node *p, int key)
    {
        // Check if the head needs to be updated immediately if the key is found at the head
        if (p != nullptr && p->data == key)
        {
            return p->data; // Return true if the key is found at the head
        }
        // Initialize q to keep track of the previous node
        Node *q = nullptr;
        while (p != nullptr)
        {
            // If the current node's data matches the key, move it to the front
            if (p->data == key)
            {
                // Adjust the next pointer of the previous node (if exists)
                if (q != nullptr)
                {
                    q->next = p->next;
                }
                else
                {
                    // If the key is found at the head, adjust the head pointer
                    head = p->next;
                }
                // Insert the found node at the beginning
                p->next = head;
                head = p;
                return p->data; // Return true if the key is found and moved
            }
            q = p;
            p = p->next;
        }
        return 0; // Return false if the key is not found
    }

    void Insert(int index, int x)
    {
        if (index < 0 || index > count())
            return;
        Node *t = new Node(x);
        if (index == 0)
        {
            t->next = head;
            head = t;
        }
        else
        {
            Node *p = head;
            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            t->next = p->next;
            p->next = t;
        }
    }
    void insertLast(int x)
    {
        Node *t = new Node(x);
        t->data = x;
        t->next = NULL;

        if (head == NULL)
        {
            head = t;
        }
        else
        {
            Node *last = head;
            while (last->next != NULL)
            {
                last = last->next;
            }
            last->next = t;
        }
    }
    void sort(int x)
    {
        Node *p = head;
        Node *q = NULL;
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        Node *t = new Node(x);
        t->data = x;
        t->next = q->next;
        q->next = t;
    }
    int del(int pos)
    {
        Node *p, *q;
        int x = -1, i;
        if (pos == 1)
        {
            x = head->data;
            p = head;
            head = head->next;
            delete p;
        }
        else
        {
            p = head;
            q = NULL;
            for (i = 0; i < pos - 1 && p; i++)
            {
                q = p;
                p = p->next;
            }
            if (p)
            {
                q->next = p->next;
                x = p->data;
                delete p;
            }
        }
        return x;
    }
    bool sortedlist()
    {
        Node *p = head;
        int x = INT32_MIN; // Initialize x with the smallest possible integer value
        while (p != NULL)
        {
            if (p->data < x)
            {
                cout << "Not Sorted " << endl; // If current node's data is less than x, list is not sorted
                return false;
            }
            x = p->data; // Update x with the current node's data
            p = p->next;
        }
        cout << "Sorted " << endl; // If the loop completes without finding any unsorted nodes, list is sorted
        return true;
    }
    void removeDuplicate()
    {
        Node *p = head;
        Node *q = p->next;
        while (q != nullptr)
        {
            if (p->data == q->data)
            {
                Node *temp = q;
                p->next = q->next;
                delete temp;
                q = p->next;
            }
            else
            {
                p = q;
                q = q->next;
            }
        }
    }
    void reverseElements()
    {
        Node *p = head;
        int size = count(); // get the size of the linked list
        int A[size];        // declare the array A
        int i = 0;
        // Store the data in an array
        while (p != NULL)
        {
            A[i] = p->data;
            p = p->next;
            i++;
        }
        // Reset p to head and i to the last index
        p = head;
        i--;
        // Assign the data from the array back to the linked list
        while (p != NULL)
        {
            p->data = A[i--];
            p = p->next;
        }
    }
    void reverseLink()
    {
        Node *p = head;
        Node *r, *q = NULL;
        while (p != NULL)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        head = q;
    }
    Node *Rreverse(Node *q, Node *p)
    {
        if (p == NULL)
        {
            head = q;
            return NULL;
        }
        Node *next = p->next;
        p->next = q;
        return Rreverse(p, next);
    }
    void create2(int B[], int n)
    {
        Node *last = nullptr;
        for (int i = 0; i < n; i++)
        {
            Node *temp = new Node(B[i]);
            if (second == nullptr)
            {
                second = temp;
                last = second;
            }
            else
            {
                last->next = temp;
                last = temp;
            }
        }
    }
    void Display2()
    {
        Node *p = second; // p=pointer to node
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    void concate(Node *p, Node *q)
    {
        if (p == nullptr)
        {
            head = q;
        }
        else
        {
            Node *last = p;
            while (last->next != nullptr)
            {
                last = last->next;
            }
            last->next = q;
        }
    }
    void Display(Node *p)
    {
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    void merge(Node *p, Node *q)
    {
        Node *last;
        if (p->data < q->data)
        {
            third = last = p;
            p = p->next;
            last->next = nullptr;
        }
        else
        {
            third = last = q;
            q = q->next;
            last->next = nullptr;
        }

        while (p != nullptr && q != nullptr)
        {
            if (p->data < q->data)
            {
                last->next = p;
                last = p;
                p = p->next;
                last->next = nullptr;
            }
            else
            {
                last->next = q;
                last = q;
                q = q->next;
                last->next = nullptr;
            }
        }

        if (p != nullptr)
        {
            last->next = p;
        }
        else
        {
            last->next = q;
        }
    }
    // void createLoop(Node* head) {
    //     Node* temp = head;
    //     while (temp->next != nullptr) {
    //         temp = temp->next;
    //     }
    //     // Now temp is pointing to the last node in the list
    //     temp->next = head->next; // or any other node in the list
    // }
    bool isLoop(Node *head)
    {
        Node *p = head;
        Node *q = head;
        do
        {
            p = p->next;
            q = q->next;
            if (q != nullptr)
            {
                q = q->next;
            }
        } while (p != q && p != nullptr && q != nullptr);
        if (p == q)
        {
            cout << "Loop is available" << endl;
            return true;
        }
        else
        {
            cout << "Loop is not available" << endl;
            return false;
        }
    }

    void display(Node *p)
    {
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
    }

    void insertCircular(int pos, int x)
    {
        Node *p = head; // Initialize p to head
        Node *t = new Node(x);
        t->data = x;
        if (pos < 0 || (head != nullptr && pos > count()))
        {
            cout << "Invalid position." << endl;
            delete t;
            return;
        }
        if (head == nullptr)
        { // If the list is empty
            head = t;
            head->next = head; // Create a circular link
        }
        else if (pos == 0)
        { // Insert at the beginning
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
        else
        {
            for (int i = 0; i < pos - 1; i++)
            {
                p = p->next;
            }
            t->next = p->next;
            p->next = t;
        }
    }
    int deleteCircular(int pos)
    {
        Node *p;
        Node *q;
        int i, x;

        if (pos == 1)
        {
            p = head;
            while (p->next != head)
            {
                p = p->next;
            }

            x = head->data;
            if (p == head)
            {
                delete head;
                head = NULL;
            }
            else
            {
                p->next = head->next;
                delete head;
                head = p->next;
            }
        }
        else
        {
            p = head;
            for (i = 0; i < pos - 2; i++)
            {
                p = p->next;
            }
            q = p->next;
            x = q->data;
            p->next = q->next;
            delete q;
        }
        return x;
    }
  void middle(){
    Node *p = head, *q = head;
    while(q && q->next){
        q = q->next->next;
        p = p->next;
    }
    cout<<"Middle element is "<<p->data<<endl;
}

};

int main()
{
    int A[] = {3, 5, 10, 15, 25, 28, 32, 42};
    // int B[] = {2, 4, 6, 8, 11};
    LinkedList list;
    list.create(A, 8);
    cout << "List 1 : ";
    list.Display();
    list.middle();
    // cout << "List 1 : ";
    // list.Display();
    // list.create2(B, 5);
    // cout << "List 2 : ";
    // list.Display2();
    // list.RDisplay(list.head);//Recursive Function
    // cout << endl;
    // int count = list.count(); // store the count in a variable
    // cout << "Count: " << count << endl; // print the count
    // cout << "Count (Recursive): " << list.count(list.head) << endl;
    // cout << "Sum: " << list.add() << endl;
    // cout << "Sum (Recursive): " << list.add(list.head) << endl;
    // cout << "Max: " << list.maxi() << endl;
    // cout << "Max (Recursive): " << list.Rmaxi(list.head) << endl;
    // cout << "Search: " << list.search(8) << endl;
    // cout << "Search (Recursive): " << list.Rsearch(list.head,25) << endl;
    // cout << "Improve Search: " << list.Isearch(list.head,32) << endl;
    // cout<<"Insert on Index :";
    // list.Insert(3, 15);
    // list.Display();
    // cout<<"Insert on Last Index :";
    // list. insertLast(6);
    // list.Display();
    // cout<<"Sort :";
    // list. sort(6);
    // list.Display();
    // cout << "Delete :";
    // list.del(4);
    // list.Display();
    // cout << "Delete :";
    // list.sortedlist();
    // list.Display();
    // cout << "Remove Duplicate :";
    // list.removeDuplicate();
    // list.Display();
    // cout << "Reverse  Elements of Linklist :";
    // list.reverseElements();
    // list.Display();
    // cout << "Reverse Links of Linklist :";
    // list. reverseLink();
    // list.Display();
    // cout << "Reverse (Recursive): ";
    // list.Rreverse(NULL, list.head);
    // list.Display();
    // cout<<"Concatenate :"
    // list.concate(list.head, list.second);
    // list.Display(list.head);
    // cout<<"Merge List :";
    // list.merge(list.head, list.second);
    // list.Display(list.third);
    // list.createLoop(list.head);
    // cout<<"LOOP :";
    // list.isLoop(list.head);
    // list.Display();
    // cout << "Circular Linklist :";
    // list.Display(list.head);
    // // cout<<"Insert Node :";
    // // list.insertCircular(3,55);
    // // list.Display(list.head);
    // cout << "Delete Node :";
    // list.deleteCircular(5);
    // list.Display(list.head);
    return 0;
}