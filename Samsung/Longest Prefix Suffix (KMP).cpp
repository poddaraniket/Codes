//O(N)

int lps(string s) {
	    // Your code goes here
	    int n=s.length(); 
	    int lp[n]={0};
	    int i=1,j=0;
	    while(i<n)
	    {
	        if(s[i]==s[j])
	         {
	             j++;
	             lp[i]=j; // kaha tak common hai
	             i++;
	         }
	        else{
	            if(j!=0)
	             {
	                 j=lp[j-1];
	             }
	            else
	             {
	                 lp[i]=0;
	                 i++;
	             }
	        } 
	    }
	    return lp[n-1];
	}