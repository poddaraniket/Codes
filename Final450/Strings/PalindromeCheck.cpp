int isPlaindrome(string S)
	{
	    int size=S.length();
        for(int i=0;i<size/2;i++){
            if(S[i]!=S[size-i-1])
               return 0;
        }
        return 1;
	}