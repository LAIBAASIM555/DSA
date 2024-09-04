#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node** head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

int findmax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

void binsort(int a[], int n) {
    int max = findmax(a, n);
    Node** bin = new Node*[max + 1];
    for (int i = 0; i <= max; i++) {
        bin[i] = NULL;
    }
    for (int i = 0; i < n; i++) {
        insert(&bin[a[i]], a[i]);
    }
    int i = 0, j = 0;
    while (i < max+1) {
        while (bin[i] != NULL) {
            Node* temp = bin[i];
            a[j++] = temp->data;
            bin[i] = bin[i]->next;
            delete temp;
        }
        i++;
    }
}

int main() {
    // Test the binsort function
    int arr[] = {5, 2, 8, 1, 9, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    binsort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}