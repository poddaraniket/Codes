#include <bits/stdc++.h>
using namespace std;

void Max_heapify(int arr[],int n,int parent)
{
    int left=2*parent+1;
    int right=2*parent+2;
    //leaf Node
    int largest=parent;
    
    if(left<n && arr[largest]<arr[left]){
        largest=left;
    }
    
    if(right<n && arr[largest]<arr[right])
     {
        largest=right; 
     }
    
    if(largest!=parent){
     swap(arr[parent],arr[largest]);
     Max_heapify(arr,n,largest);
    }
}

void printHeap(int arr[],int n){
    for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
    cout<<endl; 
}

int main() {
    // Binary Tree Representation
    // of input array
    // 1
    //           /     \
    // 3         5
    //      /    \     /  \
    // 4      6   13  10
    //    / \    / \
    // 9   8  15 17
    int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
  
    int n = sizeof(arr) / sizeof(arr[0]);
  
    int  from=(n/2j)-1;
  
    for(int i=from;i>=0;i--)
     {
       Max_heapify(arr, n,i);
     }
  
    printHeap(arr, n);
    // Final Heap:
    // 17
    //           /      \
    // 15         13
    //       /    \      /  \
    // 9      6    5   10
    //     / \    /  \
    // 4   8  3    1
  
    return 0;
}
