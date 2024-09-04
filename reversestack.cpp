#include<iostream>
using namespace std;

class reverse{
    int size1;
    int size2;
    int t1;
    int t2;
    int *s1;
    int *s2;

public:
    reverse(int size1, int size2)
    {
        this->size1 = size1;
        this->size2 = size2;
        s1 = new int[size1];
        s2 = new int[size2];
        t1 = -1;
        t2 = -1;
    }
    void insert(int x){
        if(t1 == size1-1){
            cout << "stack1 is full" << endl;
        }
        else{
            s1[++t1] = x;
        }
    }
    int del(){
        if(t2 == -1){
            if(t1 == -1){
                cout << "stack1 is empty" << endl;
                return -1;
            }
            else{
                while(t1 != -1){
                    s2[++t2] = s1[t1--];
                }
            }
        }
        return s2[t2--];
    }
   void display(){
        cout << "Stack 1: ";
        for(int i = t1; i >= 0; i--){
            cout << s1[i] << " ";
        }
        cout << endl;
        cout << "Stack 2: ";
        for(int i = t2; i >= 0; i--){
            cout << s2[i] << " ";
        }
        cout << endl;
    }
    
    ~reverse(){
        delete[] s1;
        delete[] s2;
    }
};
int main(){
    reverse r (5 , 5);
    r.insert(5);
    r.insert(4);
    r.insert(3);
    r.display();
    r.del();
    r.del();
    r.display();
    return 0;

    
}