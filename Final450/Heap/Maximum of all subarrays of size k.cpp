#include<bits/stdc++.h>
using namespace std;

void printKMax(int arr[],int n,int k){
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<k;i++)
     {
        pq.push({arr[i],i}); 
     }
    int next=k; 
    while(next<=n){
        pair<int,int> p=pq.top();
        cout<<p.first<<" ";
        if(p.second<=next-k)
         pq.pop();
        pq.push({arr[next],next}); 
        next++;
    } 
} 

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
    return 0;
}