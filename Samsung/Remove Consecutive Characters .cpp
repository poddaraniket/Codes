string removeConsecutiveCharacter(string S)
    {
        // code here.
        int n=S.length();
        if(n==0 || n==1)
         return S;
        if(S[0]==S[1])
        {
            int index=0;
            while(S[index]==S[0] && index<n)
             {
                 index++;
             }
            return S[0]+removeConsecutiveCharacter(S.substr(index)); 
        }
        return S[0]+removeConsecutiveCharacter(S.substr(1)); 
    }