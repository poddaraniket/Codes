int findMaxSum(int arr[], int n) {
	    // code here
	    int inc=arr[0];
	    int excl=0;
	    int excl_new;
	    for(int i=1;i<n;i++){
	        excl_new=(inc>excl)?inc:excl;
	        inc=excl+arr[i];
	        excl=excl_new;
	    } 
	    return max(inc,excl);
	}