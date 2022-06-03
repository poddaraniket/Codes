#include <bits/stdc++.h>
using namespace std;

int SumOfKsubArray(int arr[],int n,int k)
{
    int sum=0;
    deque<int> dq_min(k),dq_max(k);
    int i=0;
    for(i=0;i<k;i++)
    {
        while((!dq_max.empty()) && arr[i]>=arr[dq_max.back()])
         {
            dq_max.pop_back();
         }
        while((!dq_min.empty()) && arr[i]<=arr[dq_min.back()])
         {
            dq_min.pop_back();
         }
        dq_min.push_back(i);
        dq_max.push_back(i);
    }
    for(;i<n;i++)
    {
        sum+=arr[dq_max.front()]+arr[dq_min.front()];
        //cout<<dq_max.front()<<" "<<dq_min.front()<<endl;
        //cout<<sum<<endl;
        //Removing the indees not in window
        while(!(dq_min.empty()) && dq_min.front()<=i-k)
         {
            dq_min.pop_front();
         }
        while(!(dq_max.empty()) && dq_max.front()<=i-k)
         {
            dq_max.pop_front(); 
         }
        while(!(dq_max.empty())&&arr[i]>=arr[dq_max.back()])
         {
            dq_max.pop_back();
         }
        while(!(dq_min.empty())&&arr[i]<=arr[dq_min.back()])
         {
            dq_min.pop_back();
         }
        dq_min.push_back(i);
        dq_max.push_back(i); 
    }
    sum+=arr[dq_max.front()]+arr[dq_min.front()];
    return sum;
}

int main() {
    int arr[] = {2, 5, -1, 7, -3, -1, -2} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout << SumOfKsubArray(arr, n, k) ;
    return 0;
}
