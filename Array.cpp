#include <iostream>
using namespace std;

class Array
{
public:
    int length;
    int *A;

    Array()
    {
        A = new int[10]; // Initialize array in constructor
    }
    void create()
    {
        cout << "Enter length: ";
        cin >> length;
        cout << "Enter the array elements: " << endl;
        for (int i = 0; i < length; i++)
        {
            cout << "Array element: " << i << " = ";
            cin >> A[i];
        }
    }

    void Insert(int index, int y)
    {
        if (index >= 0 && index <= length)
        {
            for (int i = length; i > index; i--)
            {
                A[i] = A[i - 1];
            }
            A[index] = y;
            length++;
        }
    }
    void Append(int x)
    {
        if (length < 10)
        {
            A[length] = x;
            length++;
        }
    }
    void del(int index)
    {
        //  int c = A[index];
        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
    }
    void swap(int x, int y)
    {
        int temp = A[x];
        A[x] = A[y];
        A[y] = temp;
    }
    void search()
    {
        int key = 5;
        for (int i = 0; i < length; i++)
        {
            if (key == A[i])
            {
                if (i > 0)
                {
                    swap(i, 0);
                }
                cout << "Key found at index " << i << endl;
                return;
            }
        }
        cout << "Key not found" << endl;
    }
    void bsearch(int l, int h, int key)
    {
        int mid;
        while (l <= h)
        {
            mid = (l + h) / 2; // Calculate the midpoint
            if (A[mid] == key)
            {
                cout << "Key found at = " << mid << endl;
                return;
            }
            else if (key < A[mid])
            {
                h = mid - 1; // Update the high index
            }
            else
            {
                l = mid + 1; // Update the low index
            }
        }
        cout << "Key not found" << endl;
    }
    void reverse()
    {
        for (int i = 0, j = length - 1; i < j; i++, j--)
        {
            swap(i, j);
            cout << endl;
        }
    }
    void in(int z)
    {
        int i = length - 1;
        while (A[i] > z)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = z;
        length++;
        cout << endl;
    }
    bool isSorted(int A[], int length)
    {
        for (int i = 0; i < length - 1; i++)
        {
            if (A[i] > A[i + 1])
            {
                return false;
            }
        }
        return true;
    }
    void bubble(int *A, int length)
    {
        for (int i = 0; i < length - 1; i++)
        {
            for (int j = 0; j < length - 1 - i; j++)
            {
                if (A[j] > A[j + 1])
                {
                    swap(j, j + 1);
                }
            }
        }
    }
    void all_del()
    {
        for (int i = 0; i < length - 1; i++)
        {
            if (A[i] == A[i + 1])
                del(0);
        }
    }
    void merge(Array &a1, Array &a2)
    {
        int i = 0, j = 0, k = 0;
        int *C = new int[a1.length + a2.length];
        while (i < a1.length && j < a2.length)
        {
            if (a1.A[i] < a2.A[j])
            {
                C[k++] = a1.A[i++];
            }
            else
            {
                C[k++] = a2.A[j++];
            }
        }
        for (; i < a1.length; i++)
            C[k++] = a1.A[i];
        for (; j < a2.length; j++)
            C[k++] = a2.A[j];
        delete[] A;
        A = C;
        length = k;
    }
    void un(Array &a1, Array &a2)
    {
        int i = 0, j = 0, k = 0;
        int *C = new int[10];
        while (i < a1.length && j < a2.length)
        {
            if (a1.A[i] < a2.A[j])
            { // i<j
                C[k++] = a1.A[i++];
            }
            else if (a1.A[i] > a2.A[j]) // i>j
            {
                C[k++] = a2.A[j++];
            }
            else
                (a1.A[i] == a2.A[j]);
            C[k++] = a1.A[i++];
            j++;
        }
        for (; i < a1.length; i++)
            C[k++] = a1.A[i];
        for (; j < a2.length; j++)
            C[k++] = a2.A[j];
        delete[] A;
        A = C;
        length = k;
    }
    void inter(Array &a1, Array &a2)
    {
        int i = 0, j = 0, k = 0;
        int *C = new int[10];
        while (i < a1.length && j < a2.length)
        {
            if (a1.A[i] < a2.A[j])
            { // i<j
                i++;
            }
            else if (a1.A[i] > a2.A[j]) // i>j
            {
                j++;
            }
            else if (a1.A[i] == a2.A[j])
            {
                C[k++] = a1.A[i++];
                j++;
            }
        }
        delete[] A;
        A = C;
        length = k;
    }
    void def(Array &a1, Array &a2)
    {
        int i = 0, j = 0, k = 0;
        int *C = new int[10];
        while (i < a1.length && j < a2.length)
        {
            if (a1.A[i] < a2.A[j])
            { // i<j
                C[k++] = a1.A[i++];
            }
            else if (a1.A[i] > a2.A[j]) // i>j
            {
                j++;
            }
            else
                (a1.A[i] == a2.A[j]);
            i++;
            j++;
        }
        for (; i < a1.length; i++)
            C[k++] = a1.A[i];
        delete[] A;
        A = C;
        length = k;
    }
    void display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << A[i] << " ";
        }
    }
    ~Array()
    {
        delete[] A;
        cout << endl
             << "Array destroyed" << endl;
    }
    // Function to left shift an array by one position
    void leftShift(int arr[], int length)
    {
        // Create a temporary array to hold the shifted elements
        int temp[length];

        // Loop through the original array, starting from the second element (index 1)
        for (int i = 1; i < length; i++)
        {
            // Copy the current element to the previous index in the temporary array
            temp[i - 1] = arr[i];
        }

        // Copy the first element of the original array to the last index of the temporary array
        temp[length - 1] = arr[0];

        // Loop through the temporary array and copy its elements back to the original array
        for (int i = 0; i < length; i++)
        {
            arr[i] = temp[i];
        }
    }
    // Function to right shift an array by one position
    void rightShift(int arr[], int length)
    {
        // Create a temporary array to hold the shifted elements
        int temp[length];

        // Copy the last element of the original array to the first index of the temporary array
        temp[0] = arr[length - 1];

        // Loop through the original array, starting from the first element (index 0)
        for (int i = 0; i < length - 1; i++)
        {
            // Copy the current element to the next index in the temporary array
            temp[i + 1] = arr[i];
        }

        // Loop through the temporary array and copy its elements back to the original array
        for (int i = 0; i < length; i++)
        {
            arr[i] = temp[i];
        }
    }
    void concat(Array &a1, Array &a2)
    {
        int *C = new int[a1.length + a2.length];
        for (int i = 0; i < a1.length; i++)
        {
            C[i] = a1.A[i];
        }
        for (int i = 0; i < a2.length; i++)
        {
            C[a1.length + i] = a2.A[i];
        }
        delete[] A;
        A = C;
        length = a1.length + a2.length;
    }
};

int main()
{
    Array a1, a2, a3;
    a1.create();
    a2.create();

    a1.display();
    // cout<<"Right shift :";
    // // a1.leftShift(a1.A, a1.length);
    // a1.rightShift(a1.A, a1.length);
    // a1.display();
    cout << endl;
    a2.display();
    cout << endl;

    a3.length = 0; // Initialize length to 0
    //a3.merge(a1, a2);
    // a3.un(a1,a2);
    //a3.inter(a1,a2);
    //a3.def(a1,a2);
    a3.concat(a1, a2);
    //a3.display();
    a3.concat(a1, a2);
    a3.display();

    // a.Append(23);
    // a.Insert(3,67);
    // a.del(3);
    // a.search();
    // a.bsearch(0 , 7 , 15);
    // a.reverse();
    // a.in(9);
    // a.isSorted(a.A,a.length);
    // a.bubble(a.A, a.length);
    // a.all_del();
    return 0;
}