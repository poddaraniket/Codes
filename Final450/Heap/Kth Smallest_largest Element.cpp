#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[],int n,int k){
    priority_queue<int> pq;
    for(int i=0;i<n;i++)
     {
        if(pq.size()<=k)
         {
            pq.push(arr[i]); 
         }
        else
         {
            if(arr[i]<pq.top()) 
            {
                pq.pop();
                pq.push(arr[i]);
            }
         }
     }
    return pq.top(); 
    
}

int main()
{
    int arr[] = { 12, 3, 5, 7, 19 };
    int n = sizeof(arr) / sizeof(arr[0]), k = 2;
    cout << "K'th smallest element is " << kthSmallest(arr, n, k);
    return 0;
}
