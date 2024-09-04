#include <iostream>
#include <cstring>

using namespace std;

struct Node
{
  int data;
  Node *next;
};

class Stack
{
public:
  Node *top;

  Stack() : top(nullptr) {}

  void push(int x)
  {
    Node *t = new Node;
    if (t == nullptr)
    {
      cout << "Stack is full\n";
      exit(1);
    }
    t->data = x;
    t->next = top;
    top = t;
  }

  int pop()
  {
    if (top == nullptr)
    {
      cout << "Stack is Empty\n";
      exit(1);
    }
    Node *t = top;
    top = top->next;
    int x = t->data;
    delete t;
    return x;
  }

  bool isEmpty()
  {
    return top == nullptr;
  }

  int topElement()
  {
    if (top == nullptr)
    {
      cout << "Stack is Empty\n";
      exit(1);
    }
    return top->data;
  }
};

bool isOperand(char x)
{
  return (x >= '0' && x <= '9');
}

int precedence(char x)
{
  if (x == '+' || x == '-')
    return 1;
  else if (x == '*' || x == '/')
    return 2;
  return 0;
}

char *InToPost(char *infix)
{
  int i = 0, j = 0;
  int len = strlen(infix);
  char *postfix = new char[len + 2];
  Stack st;

  while (infix[i] != '\0')
  {
    if (isOperand(infix[i]))
    {
      postfix[j++] = infix[i++];
    }
    else
    {
      if (st.isEmpty() || precedence(infix[i]) > precedence(st.topElement()))
      {
        st.push(infix[i++]);
      }
      else
      {
        postfix[j++] = st.pop();
      }
    }
  }

  while (!st.isEmpty())
  {
    postfix[j++] = st.pop();
  }
  postfix[j] = '\0';
  return postfix;
}

char *InToPre(char *infix)
{
    int i = 0, j = 0;
    int len = strlen(infix);
    char *prefix = new char[len + 2]; // Allocate memory for prefix expression
    Stack st;

    // Reverse the infix expression
    for (i = 0; i < len / 2; i++)
    {
        char temp = infix[i];
        infix[i] = infix[len - i - 1];
        infix[len - i - 1] = temp;
    }

    // Convert the reversed infix to postfix
    for (i = 0; infix[i] != '\0'; i++)
    {
        if (isOperand(infix[i]))
        {
            prefix[j++] = infix[i];
        }
        else if (infix[i] == ')')
        {
            st.push(infix[i]);
        }
        else if (infix[i] == '(')
        {
            while (st.topElement() != ')')
            {
                prefix[j++] = st.pop();
            }
            st.pop(); // Remove the ')'
        }
        else
        {
            while (!st.isEmpty() && precedence(infix[i]) <= precedence(st.topElement()))
            {
                prefix[j++] = st.pop();
            }
            st.push(infix[i]);
        }
    }

    while (!st.isEmpty())
    {
        prefix[j++] = st.pop();
    }

    // Reverse the postfix expression to get the prefix expression
    for (i = 0; i < j / 2; i++)
    {
        char temp = prefix[i];
        prefix[i] = prefix[j - i - 1];
        prefix[j - i - 1] = temp;
    }

    prefix[j] = '\0';
    cout << "Prefix expression: " << prefix << endl; // Print the prefix expression
    return prefix;
}
int Eval(char *postfix)
{
  int i = 0;
  int x1, x2, r = 0;
  Stack st;

  for (i = 0; postfix[i] != '\0'; i++)
  {
    if (isOperand(postfix[i]))
    {
      st.push(postfix[i] - '0');
    }
    else
    {
      x2 = st.pop();
      x1 = st.pop();
      switch (postfix[i])
      {
      case '+':
        r = x1 + x2;
        break;
      case '-':
        r = x1 - x2;
        break;
      case '*':
        r = x1 * x2;
        break;
      case '/':
        r = x1 / x2;
        break;
      }
      st.push(r);
    }
  }
  return st.top->data;
}
void middlestack(Node *head)
{
  Node *p = head;
  Stack s;
  int count = 0;
  // Count the number of elements in the stack
  while (p != nullptr)
  {
    count++;
    p = p->next;
  }
  p = head;
  // Push elements to the temporary stack
  while (p != nullptr)
  {
    s.push(p->data);
    p = p->next;
  }
  // Pop elements from the temporary stack until the middle element is reached
  for (int i = 0; i < count / 2; i++)
  {
    s.pop();
  }
  // The top element of the temporary stack is the middle element
  cout << "Middle element is " << s.topElement() << endl;
}
void intersection(Node *head1, Node *head2)
{
  Stack s1, s2;
  Node *p = head1;
  Node *q = head2;

  // Push elements of first linked list to stack s1
  while (p)
  {
    s1.push(p->data);
    p = p->next;
  }

  // Push elements of second linked list to stack s2
  while (q)
  {
    s2.push(q->data);
    q = q->next;
  }

  // Find the intersection by popping elements from both stacks
  while (!s1.isEmpty() && !s2.isEmpty())
  {
    if (s1.topElement() == s2.topElement())
    {
      cout << "Intersection node: " << s1.topElement() << endl;
      s1.pop();
      s2.pop();
    }
    else if (s1.topElement() > s2.topElement())
    {
      s1.pop();
    }
    else
    {
      s2.pop();
    }
  }
}

int main()
{
  // char *postfix = "234*+82/-";
  // cout << "Result is " << Eval(postfix) << endl;
  // Create a linked list: 2 -> 3 -> 4

  char *infix = "2+3*4";
  char *prefix = InToPre(infix);
  cout << "Prefix expression: " << prefix << endl;

  // Node *head = new Node;
  // head->data = 2;
  // head->next = new Node;
  // head->next->data = 3;
  // head->next->next = new Node;
  // head->next->next->data = 4;
  // head->next->next->next = nullptr;

  // middlestack(head);

  // Node* head1 = new Node;
  // head1->data = 2;
  // head1->next = new Node;
  // head1->next->data = 3;
  // head1->next->next = new Node;
  // head1->next->next->data = 4;
  // head1->next->next->next = nullptr;

  // Node* head2 = new Node;
  // head2->data = 3;
  // head2->next = new Node;
  // head2->next->data = 4;
  // head2->next->next = new Node;
  // head2->next->next->data = 5;
  // head2->next->next->next = nullptr;

  // intersection(head1, head2);
  return 0;
}
