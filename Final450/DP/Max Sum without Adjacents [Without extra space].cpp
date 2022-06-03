int findMaxSum(int *arr, int n) {
	    // code here
	    int inc=arr[0],exc=0,exc_max;
	    for(int i=1;i<n;i++){
	        exc_max=max(inc,exc);
	        inc=exc+arr[i];
	        exc=exc_max;
	    }
	    return max(exc,inc);
	}