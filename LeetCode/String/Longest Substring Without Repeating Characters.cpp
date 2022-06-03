#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	string s;
	cin>>s;
	int arr[256];
	memset(arr,-1,sizeof(arr));
	int start=0,maxi=0,i;
	for(i=0;i<s.length();i++)
	 {
	     if(arr[s[i]]!=-1 && arr[s[i]]>=start)
          {
	           start=arr[s[i]]+1;
	      }
         else
           maxi=max(maxi,i-start+1);   
	    arr[s[i]]=i;
	 }    
	//maxi=max(maxi,i-start+1); 
	cout<<maxi<<endl;
	return 0;
}
