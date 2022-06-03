//O(N)	

	int lps(string s) {
	    // Your code goes here
	    int n=s.length();
	    int lp[n];
	    lp[0]=0;
	    int l=0,r=1;
	    while(r<n)
	     {
	         if(s[r]==s[l])
	          {
	              lp[r]=l+1;
	              l++;
	              r++;
	          }
	         else{
	             if(l!=0)
	              l=lp[l-1];
	             else
	              {
	                  lp[r]=0;
	                  r++;
	              }
	         } 
	     }
	    return lp[n-1]; 
	}