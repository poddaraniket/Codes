#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
     cin>>arr[i];
    int neg[n];
    memset(neg,-1,sizeof(neg));
    stack<int> s;
    s.push(0);
    for(int i=1;i<n;i++)
     {
        while(!s.empty() && arr[s.top()]<arr[i])
         {
            neg[s.top()]=arr[i];
            s.pop();
         }
        s.push(i); 
     }
    for(int i=0;i<n;i++)
     cout<<neg[i]<<" ";
    cout<<endl; 
	return 0;
}
