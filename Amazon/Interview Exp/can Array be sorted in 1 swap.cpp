// O(n)

#include <bits/stdc++.h>
using namespace std;

bool checkSorted(int n,int arr[])
{
    int count=0,first=0,second=0;
    for(int i=1;i<n;i++)
     {
        if(arr[i]<arr[i-1]){
         count++;
        if(first==0)
         first=i;
        else
         second=i;
        }
     }
    if(count>2)
     return false;
    if(count==1)
     swap(arr[first],arr[first-1]);
    if(count==2)
     swap(arr[first-1],arr[second]);
    for(int i=1;i<n;i++)
     {
        if(arr[i]<arr[i-1])
            return false;
     } 
    return true; 
}

int main()
{
    int arr[] = { 1, 4, 3, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    if (checkSorted(n, arr))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}