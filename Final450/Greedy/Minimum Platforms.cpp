int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code
    	int a=0,d=0,lastPlatform=0,ans=0;
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	while(a<n && d<n)
    	 {
    	    if(arr[a]<=dep[d]){
    	      a++;     
    	      lastPlatform++;
    	      ans=max(ans,lastPlatform);
    	    }
    	    else{
    	        lastPlatform--;
    	        d++;
    	    }
    	    
    	 }
    	return ans; 
    }