#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(b==0)
     return a;
    return gcd(b,a%b); 
}

int main() {
	// your code goes here
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
     cin>>arr[i];
    int sets=gcd(k,n);
    cout<<sets<<endl;
    for(int i=0;i<sets;i++)
    {
        int temp=arr[i];
        int curr=i;
        while(1)
         {
            int next=curr+k;
            if(next>=n)
             next-=n;
            if(next==i)
             break;
            arr[curr]=arr[next];
            curr=next;
         }
        arr[curr]=temp;
    }
    for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
	return 0;
}
