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
	
	int low=0,high=n-1;
	while(low<=high){
	    if(a[low]>0 && a[high]<0){
	        a[low]^=a[high];
	        a[high]^=a[low];
	        a[low]^=a[high];
	        high--;
	        low++;
	    }
	    else if(a[high]>0){
	        high--;
	    }
	    else if(a[low]<0){
	        low++;
	    }
	}
	
	return 0;
}
