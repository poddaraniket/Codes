void pushZerosToEnd(int arr[], int n) {
	    // code here
	    int l=0,r=0;
	    while(r<n){
	        if(arr[l]==0 && arr[r]!=0)
	         {
	             swap(arr[l],arr[r]);
	             l++;
	             r++;
	         }
	        else if(arr[l]==0 && arr[r]==0){
	            r++;
	        }
	        else
	         {
	             l++;
	             r++;
	         }
	    }
	}