int maxSubstring(string S)
	{
	    // Your code goes here
	    int curr_max=0,max_so_far=0;
	    for(int i=0;i<S.length();i++)
	     {
	         curr_max+=S[i]=='0'?1:-1;
	         if(curr_max<0)
	          curr_max=0;
	         max_so_far=max(max_so_far,curr_max); 
	     }
	    return max_so_far==0?-1:max_so_far; 
	}