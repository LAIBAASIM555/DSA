// #include <iostream>
// using namespace std;

// // Function to merge two arrays into one array
// void mergeTwoArrays(int arr1[], int arr2[], int m, int n) {
//     int mergedArray[m + n];
//     int i = 0, j = 0, k = 0;

//     // Merge smaller elements first
//     while (i < m && j < n) {
//         if (arr1[i] < arr2[j]) {
//             mergedArray[k++] = arr1[i++];
//         } else {
//             mergedArray[k++] = arr2[j++];
//         }
//     }

//     // Copy remaining elements from arr1, if any
//     while (i < m) {
//         mergedArray[k++] = arr1[i++];
//     }

//     // Copy remaining elements from arr2, if any
//     while (j < n) {
//         mergedArray[k++] = arr2[j++];
//     }

//     // Print the merged array
//     cout << "Merged Array: ";
//     for (int x = 0; x < m + n; x++) {
//         cout << mergedArray[x] << " ";
//     }
//     cout << endl;
// }

// // Function to merge four arrays into one array using two-way merging
// void mergeFourArrays(int arr1[], int arr2[], int arr3[], int arr4[], int m, int n, int o, int p) {
//     int tempArray[m + n];

//     // Merge arr1 and arr2 into tempArray
//     int i = 0, j = 0, k = 0;
//     while (i < m && j < n) {
//         if (arr1[i] < arr2[j]) {
//             tempArray[k++] = arr1[i++];
//         } else {
//             tempArray[k++] = arr2[j++];
//         }
//     }
//     while (i < m) {
//         tempArray[k++] = arr1[i++];
//     }
//     while (j < n) {
//         tempArray[k++] = arr2[j++];
//     }

//     // Merge tempArray and arr3 into tempArray
//     i = 0, j = 0, k = 0;
//     while (i < m + n && j < o) {
//         if (tempArray[i] < arr3[j]) {
//             tempArray[k++] = tempArray[i++];
//         } else {
//             tempArray[k++] = arr3[j++];
//         }
//     }
//     while (i < m + n) {
//         tempArray[k++] = tempArray[i++];
//     }
//     while (j < o) {
//         tempArray[k++] = arr3[j++];
//     }

//     // Merge tempArray and arr4 into final merged array
//     mergeTwoArrays(tempArray, arr4, m + n + o, p);
// }

// int main() {
//     int arr1[] = {1, 2, 3, 4, 5};
//     int arr2[] = {6, 7, 8, 9, 10};
//     int arr3[] = {11, 12, 13, 14, 15};
//     int arr4[] = {16, 17, 18, 19, 20};

//     int m = sizeof(arr1) / sizeof(arr1[0]);
//     int n = sizeof(arr2) / sizeof(arr2[0]);
//     int o = sizeof(arr3) / sizeof(arr3[0]);
//     int p = sizeof(arr4) / sizeof(arr4[0]);

//     mergeFourArrays(arr1, arr2, arr3, arr4, m, n, o, p);

//     return 0;
// }


#include<iostream>
using namespace std;

void merge(int a[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = l;
    int b[h + 1];
    while (i <= mid && j <= h) {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    for (; i <= mid; i++)
        b[k++] = a[i];
    for (; j <= h; j++)
        b[k++] = a[j];
    for (int i = l; i <= h; i++)
        a[i] = b[i];
}

void imerge(int a[], int n) {
    int p, i, h, l, mid;
    for (p = 2; p <= n; p *= 2) {
        for (i = 0; i + p - 1 < n; i += p) {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(a, l, mid, h);
        }
    }
    if (p / 2 < n) {
        merge(a, 0, p / 2 - 1, n - 1);
    }
}
void mergesort(int a[],int l , int h){
    if(l<h){
        int mid=(l+h)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}

int main() {
    int a[] = {31, 22, 15, 4, 10, 6, 17, 8};
    int n = 8;
    mergesort(a,0,n-1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}