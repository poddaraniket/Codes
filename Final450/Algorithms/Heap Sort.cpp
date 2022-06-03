#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[],int n,int parent){
    int left=2*parent+1;
    int right=2*parent+2;
    int largest=parent;
    
    if(left<n && arr[largest]<arr[left])
     largest=left;
    if(right<n && arr[largest]<arr[right])
     largest=right;
    if(parent!=largest)
     {
        swap(arr[parent],arr[largest]);
        heapify(arr,n,largest);
     }
}

void heapSort(int arr[],int n)
{
    //Build MaxHeap
    for(int i=n/2-1;i>=0;i--)
     heapify(arr,n,i);
    
    
    for(int i=n-1;i>=0;i--)
     {
        // Swap the largest[root] with the last item of heap and then reduce the size of heap by 1  
        swap(arr[i],arr[0]);
        // heapify again
        heapify(arr,i,0);
     }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
    cout<<endl; 
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    heapSort(arr, n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
}