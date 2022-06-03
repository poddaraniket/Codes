#include<bits/stdc++.h>

using namespace std;

void printNonRepeated(int arr[],int n)
{
    //Your code here
    map<int,int> mp;
    for(int i=0;i<n;i++)
     mp[arr[i]]++;
    for(int i=0;i<n;i++)
    {
        if(mp[arr[i]]==1)
         cout<<arr[i]<<" ";
    }
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) 
	 cin>>arr[i];
	printNonRepeated(arr,n); 
}