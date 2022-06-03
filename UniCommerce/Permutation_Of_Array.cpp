#include <bits/stdc++.h>
using namespace std;

void permute(int arr[],int index,vector<int> v,int n)
{
    if(index==n)
     return;
    for(int j=0;j<v.size();j++)
     cout<<v[j]<<" ";
    cout<<endl; 
    for(int i=index+1;i<n;i++)
     {
        v.push_back(arr[i]); 
        permute(arr,i,v,n);
        v.pop_back();
     }
}

int main() {
	// your code goes here
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) 
     cin>>arr[i];
    vector<int> v; 
    //cout<<"*"<<endl;
    permute(arr,-1,v,n); 
    // for(int i=0;i<8;i++)
    //  {
    //      for(int j=0;j<v[i].size();j++)
    //       cout<<v[i][j]<<" ";
    //      cout<<endl; 
    //  }
	return 0;
}
