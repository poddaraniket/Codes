int countMin(string str){
    //complete the function here
      string newStr=str+'$';
      for(int i=str.length()-1;i>=0;i--)
       {
           newStr+=str[i];
       }
      int n=newStr.length(); 
      int lps[n];
      lps[0]=0;
      int l=0;
      for(int r=1;r<n;)
       {
           if(newStr[l]==newStr[r])
            {
                lps[r]=l+1;
                l++;
                r++;
            }
            else
             {
                 if(l!=0)
                   l=lps[l-1];
                 else
                  {
                      lps[r]=0;
                      r++;
                  }
             }
       }
      return str.length()-lps[n-1]; 
    }