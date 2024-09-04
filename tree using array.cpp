#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    int lchild;
    int rchild;
};

Node tree[100]; // assuming a max tree size of 100
int root = 0;
int queue[100]; // assuming a max queue size of 100
int front = 0, rear = 0;

void enqueue(int node) {
    queue[rear++] = node;
}

bool isEmpty() {
    return front == rear;
}

int dequeue() {
    return queue[front++];
}

void create() {
    int x;
    cout << "Enter root value: ";
    cin >> x;
    tree[root].data = x;
    tree[root].lchild = -1;
    tree[root].rchild = -1;
    enqueue(root);
    while (!isEmpty()) {
        int p = dequeue();
        cout << "Enter left child value for " << tree[p].data << ": ";
        cin >> x;
        if (x != -1) {
            tree[root].lchild = root + 1;
            tree[root + 1].data = x;
            tree[root + 1].lchild = -1;
            tree[root + 1].rchild = -1;
            enqueue(root + 1);
            root++;
        }
        cout << "Enter right child value for " << tree[p].data << ": ";
        cin >> x;
        if (x != -1) {
            tree[root].rchild = root + 1;
            tree[root + 1].data = x;
            tree[root + 1].lchild = -1;
            tree[root + 1].rchild = -1;
            enqueue(root + 1);
            root++;
        }
    }
}

void preorder(int p) {
    if (p != -1) {
        cout << tree[p].data << " ";
        preorder(tree[p].lchild);
        preorder(tree[p].rchild);
    }
}

void postorder(int p) {
    if (p != -1) {
        postorder(tree[p].lchild);
        postorder(tree[p].rchild);
        cout << tree[p].data << " ";
    }
}

void inorder(int p) {
    if (p != -1) {
        inorder(tree[p].lchild);
        cout << tree[p].data << " ";
        inorder(tree[p].rchild);
    }
}

void levelOrder(int p) {
    if (p == -1)
        return;

    enqueue(p);

    while (!isEmpty()) {
        int temp = dequeue();
        cout << tree[temp].data << " ";

        if (tree[temp].lchild != -1)
            enqueue(tree[temp].lchild);
        if (tree[temp].rchild != -1)
            enqueue(tree[temp].rchild);
    }
}

void printTree(int p, int level = 0, bool isLast = true) {
    if (p == -1)
        return;

    // Print indentation
    for (int i = 0; i < level; i++) {
        cout << "  ";
    }

    // Print branch indicator
    if (level > 0) {
        if (isLast) {
            cout << "+--- ";
        } else {
            cout << "|--- ";
        }
    }

    // Print node data
    cout << tree[p].data << endl;

    // Print left subtree
    printTree(tree[p].lchild, level + 1, false);

    // Print right subtree
    printTree(tree[p].rchild, level + 1, true);
}

void preorderIterative(int temp) {
    stack<int> s;

    while (temp != -1 || !s.empty()) {
        if (temp != -1) {
            cout << tree[temp].data << " ";
            s.push(temp);
            temp = tree[temp].lchild;
        } else {
            temp = s.top();
            s.pop();
            temp = tree[temp].rchild;
        }
    }
}

void inorderIterative(int temp) {
    stack<int> s;

    while (temp != -1 || !s.empty()) {
        if (temp != -1) {
            s.push(temp);
            temp = tree[temp].lchild;
        } else {
            temp = s.top();
            s.pop();
            cout << tree[temp].data << " ";
            temp = tree[temp].rchild;
        }
    }
}

void postorderIterative(int temp) {
    stack<int> s1, s2;
    s1.push(temp);

    while (!s1.empty()) {
        temp = s1.top();
        s1.pop();
        s2.push(temp);

        if (tree[temp].lchild != -1)
            s1.push(tree[temp].lchild);