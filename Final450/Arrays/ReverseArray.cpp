#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	for(int i=0;i<n/2;i++){
	    arr[i]^=arr[n-i-1];
	    arr[n-i-1]^=arr[i];
	    arr[i]^=arr[n-i-1];
	}
	for(int i=0;i<n;i++){
	    cout<<arr[i]<<endl;
	}
	return 0;
}
