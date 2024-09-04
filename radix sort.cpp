#include<iostream>
#include<cmath>
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

void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixsort(int arr[], int n) {
    int maxElement = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    for (int exp = 1; maxElement / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// void binsort(int a[], int n) {
//     int max = findmax(a, n);
//     Node** bin = new Node*[max + 1];
//     for (int i = 0; i <= max; i++) {
//         bin[i] = NULL;
//     }
//     for (int i = 0; i < n; i++) {
//         insert(&bin[a[i]], a[i]);
//     }
//     int i = 0, j = 0;
//     while (i <= max) {
//         while (bin[i] != NULL) {
//             Node* temp = bin[i];
//             a[j++] = temp->data;
//             bin[i] = bin[i]->next;
//             delete temp;
//         }
//         i++;
//     }
//     radixsort(a, n);
// }

int main() {
    // Test the radixsort function
    int arr[] = {5, 2, 8, 1, 9, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    radixsort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}