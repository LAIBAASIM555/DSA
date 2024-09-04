#include<iostream>
using namespace std;

int partition(int A[],int l , int h){
    int pivot=A[l];
    int i = l , j=h;
    do{
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
        if(i<j){
            swap(A[i],A[j]);
        }
    }while(i<j);
    swap(A[l],A[j]);
    return j;
}
void quicksort(int A[], int l ,int h)
{
    int j;
    if(l<h){
        //Recurrsion calls
        j=partition(A,l,h);
        //all elements less than the pivot.
        quicksort(A,l,j);
        //all elements greater than the pivot.
        quicksort(A,j+1,h);
    }
          
}
int main()
{
    int A[]={5,2,9,1,7,6,3,8,4,INT32_MAX};
    int n = 10 ,i;
    quicksort(A,0,n-1);
    for( i = 0 ; i<n;i++){
        cout<<A[i]<<" ";
    }

}


