//Time complexity of both: O(n)

/*#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	
	int min=arr[0],max=arr[0];
	//Min and Max
	for(int i=1;i<n;i++){
	    if(arr[i]>max){
	        max=arr[i];
	    }
	    else if(arr[i]<min){
	        min=arr[i];
	     }
	}
	cout<<max<<" "<<min<<endl;
	return 0;
}


*/

#include <bits/stdc++.h>
using namespace std;

struct Pair{
    int min,max;
};

struct Pair find(int arr[],int low,int high){
    struct Pair minmax,mml,mmr;
    if(low==high){
        minmax.min=arr[low];
        minmax.max=arr[low];
        return minmax;
    }
    else if(low==high-1){
        if(arr[low]<arr[high]){
            minmax.min=arr[low];
            minmax.max=arr[high];
        }
        else{
            minmax.max=arr[low];
            minmax.min=arr[high];
        }
        return minmax;
    }
    int mid=(low+high)/2;
    mml=find(arr,low,mid);
    mmr=find(arr,mid+1,high);
    minmax.min=min(mml.min,mmr.min);
    minmax.max=max(mml.max,mmr.max);
    return minmax;
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	
	struct Pair minmax=find(arr,0,n-1);
	
	cout<<minmax.max<<" "<<minmax.min<<endl;
	
	return 0;
}
