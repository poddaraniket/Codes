int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> LIS(n);
	    for(int i=0;i<n;i++){
	        LIS[i]=arr[i];
	    }
	    int maxi=0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(arr[i]>arr[j]){
	                LIS[i]=max(LIS[i],arr[i]+LIS[j]);
	            }
	        }
	        maxi=max(maxi,LIS[i]);
	    }
	    return maxi;
	}  