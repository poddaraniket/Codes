int lps(string s)
	{
	    // Your code goes here
	    int n=s.length();
	    int lps[s.length()];
	    lps[0]=0;
	    int len=0,i=1;
	    while(i<s.length()){
	        if(s[i]==s[len]){
	            len++;
	            lps[i]=len;
	            i++;
	        }
	        else{
	            if(len!=0){
	                len=lps[len-1];
	            }
	            else{
	                lps[i]=0;
	                i++;
	            }
	        }
	    }
	    int res=lps[n-1];
	    return res;
	}