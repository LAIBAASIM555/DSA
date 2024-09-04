#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *lchild;
    Node *rchild;
};

Node *root = nullptr;
Node *q[100]; // assuming a max queue size of 100
int front = 0, rear = 0;

void enqueue(Node *node)
{
    q[rear++] = node;
}

bool isEmpty()
{
    return front == rear;
}

Node *dequeue()
{
    return q[front++];
}

void create()
{
    Node *p, *t;
    int x;
    cout << "Enter root value: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    enqueue(root);
    while (!isEmpty())
    {
        p = dequeue();
        cout << "Enter left child value for " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            enqueue(t);
        }
        cout << "Enter right child value for " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            enqueue(t);
        }
    }
}

void preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void postorder(Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << " ";
    }
}

void inorder(Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}

void levelOrder(Node *p)
{
    if (p == nullptr)
        return;

    enqueue(p);

    while (!isEmpty())
    {
        Node *temp = dequeue();
        cout << temp->data << " ";

        if (temp->lchild != nullptr)
            enqueue(temp->lchild);
        if (temp->rchild != nullptr)
            enqueue(temp->rchild);
    }
}

void printTree(Node *p, int level = 0, bool isLast = true) {
    if (p == nullptr) {
        return;
    }

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
    cout << p->data << endl;

    // Print left subtree
    printTree(p->lchild, level + 1, false);

    // Print right subtree
    printTree(p->rchild, level + 1, true);
}void preorderIterative(Node *temp)
{

    stack<Node *> s;

    while (temp != NULL || !s.empty())
    {
        if (temp != NULL)
        {
            cout << temp->data << " ";
            s.push(temp);
            temp = temp->lchild;
        }
        else
        {
            temp = s.top();
            s.pop();
            temp = temp->rchild;
        }
    }
}
void inorderIterative(Node *temp)
{

    stack<Node *> s;

    while (temp != NULL || !s.empty())
    {
        if (temp != NULL)
        {

            s.push(temp);
            temp = temp->lchild;
        }
        else
        {
            temp = s.top();
            s.pop();
            cout << temp->data << " ";
            temp = temp->rchild;
        }
    }
}
// using two stacks
void postorderIterative(Node *temp)
{
    // Create two empty stacks, s1 and s2.
    stack<Node *> s1, s2;
    // Push the root node into s1.
    s1.push(temp);
    // While s1 is not empty,
    while (!s1.empty())
    {
        // Pop a node from s1 and push it into s2.
        temp = s1.top();
        s1.pop();
        s2.push(temp);
        // Push the left child of the popped node into s1 if it exists.
        if (temp->lchild)
            s1.push(temp->lchild);
        // Push the right child of the popped node into s1 if it exists.
        if (temp->rchild)
            s1.push(temp->rchild);
    }
    // After s1 becomes empty, all nodes have
    // been pushed into s2 in reverse postorder.
    // Finally, pop nodes from s2 and print
    // their data to get the postorder traversal.

    while (!s2.empty())
    {
        temp = s2.top();
        s2.pop();
        cout << temp->data << " ";
    }
}
// using one stack
void postorderIterative1(Node *temp)
{
    stack<Node *> s;
    // temp: a pointer to the current node being processed.
    while (temp != NULL || !s.empty())
    {
        if (temp != NULL)
        {
            s.push(temp);
            temp = temp->lchild;
        }
        else
        {
            // t: a temporary pointer to a node
            //  used to access the top node on the stack.
            // If temp is null, pop the top node from the stack
            Node *t = s.top();
            // If t has a right child, move to it
            if (t->rchild != NULL)
            {
                temp = t->rchild;
            }
            // If t has no right child, print its data pop it from the stack,
            else
            {
                cout << t->data << " ";
                s.pop();
                // While the stack is not empty and the top node's right child is
                //  t print the top node's data and pop it from the stack.
                while (!s.empty() && s.top()->rchild == t)
                {
                    t = s.top();
                    cout << t->data << " ";
                    s.pop();
                }
            }
        }
    }
}
int count(Node *p)
{
    int x, y;
    if (p != NULL)
    {
        // post-order
        x = count(p->lchild);
        y = count(p->rchild);
        return x + y + 1;
    }
    return 0;
}
// Missing nodes
int missingcount(Node *p)
{
    int x, y;
    if (p != NULL)
    {
        // post-order
        x = count(p->lchild);
        y = count(p->rchild);
        if (p->lchild && p->rchild)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}
int height(Node *p)
{
    int x, y;
    if (p != NULL)
    {
        // post-order
        x = height(p->lchild);
        y = height(p->rchild);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    return 0;
}
int deg1(Node *p)
{
    int x, y;
    if (p != NULL)
    {
        // post-order
        x = count(p->lchild);
        y = count(p->rchild);
        if ((p->lchild != NULL) ^ (p->rchild != NULL))
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}
int Rsearchtree(Node *t, int key)
{
    if (t == NULL)
    {
        cout << "Key not found." << endl;
        return 0;
    }
    if (key == t->data)
    {
        cout << "Key found: " << key << endl;
        return t->data;
    }
    else if (key < t->data)
    {
        return Rsearchtree(t->lchild, key);
    }
    else
    {
        return Rsearchtree(t->rchild, key);
    }
}
void insert(Node *t, int key)
{
    if (t == NULL)
    {
        t = new Node;
        t->data = key;
        t->lchild = NULL;
        t->rchild = NULL;
    }
    else
    {
        Node *r = NULL, *p;
        while (t != NULL)
        {
            r = t;
            if (key == t->data)
                return;
            else if (key < t->data)
                t = t->lchild;
            else
                t = t->rchild;
        }
        p = new Node;
        p->data = key;
        p->lchild = NULL;
        p->rchild = NULL;
        if (p->data < r->data)
            r->lchild = p;
        else
            r->rchild = p;
    }
    // Print the tree structure before insertion
    cout << "Tree structure before insertion:" << endl;
    printTree(root);

    // Print the inserted node
    cout << "Inserted node: " << key << endl;

    // Print the tree structure after insertion
    cout << "Tree structure after insertion:" << endl;
    printTree(root);
}
int main()
{
    create();
    // cout << "Tree structure:" << endl;
    // printTree(root);
    // cout << "Preorder traversal: ";
    // preorder(root);
    // cout << endl;
    // cout << "Postorder traversal: ";
    // postorder(root);
    // cout << endl;
    // cout << "Inorder traversal: ";
    // inorder(root);
    // cout << endl;
    // cout << "Level order traversal: ";
    // levelOrder(root);
    // cout << endl;
    // cout << "Height of the tree: " << height(root) << endl;
    // cout << "Iterative preorder: ";
    // preorderIterative(root);
    // cout << endl;
    // cout << "Iterative inorder: ";
    // inorderIterative(root);
    // cout << endl;
    // cout << "Iterative postorder: ";
    // postorderIterative(root);
    // cout << endl;
    // cout << "Iterative postorder: ";
    // postorderIterative1(root);
    // cout << endl;
    // cout << "Count Nodes: " << count(root) << endl;
    // cout << endl;
    // cout << "Count Missing Nodes: " << missingcount(root) << endl;
    // cout << endl;
    // cout << "Fun Nodes: " << height(root) << endl;
    // cout << endl;
    // cout << "Degree 1 Nodes: " << deg1(root) << endl;
    // cout << endl;
    // cout << "Binary Search Recursion: " << Rsearchtree(root, 50) << endl;
    // cout << endl;
    cout << "Binary Search Insertion ";
    insert(root, 38);
    cout << endl;
    return 0;
    return 0;}