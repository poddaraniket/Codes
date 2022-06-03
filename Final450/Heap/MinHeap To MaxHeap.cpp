#include <bits/stdc++.h>
using namespace std;

void MaxHeapify(int arr[],int n,int parent){
    int left=2*parent+1;
    int right=2*parent+2;
    int largest=parent;
    if(left<n && arr[left]>arr[largest])
     largest=left;
    if(right<n && arr[right]>arr[largest])
     largest=right;
    if(largest!=parent)
     {
         swap(arr[largest],arr[parent]);
         MaxHeapify(arr,n,largest);
     }
}

void convertMaxHeap(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        MaxHeapify(arr,n,i);
    }
}

void printArray(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}
 
// Driver program to test above functions
int main()
{
    // array representing Min Heap
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    printf("Min Heap array : ");
    printArray(arr, n);
 
    convertMaxHeap(arr, n);
 
    printf("\nMax Heap array : ");
    printArray(arr, n);
 
    return 0;
}