bool containsWord(vector<string> &B,vector<string> &ans,string word)
    {
        for(int i=0;i<B.size();i++)
         {
             if(B[i]==word)
              {
                  ans.push_back(B[i]);
                  return true;
              }
         }
        return false; 
    }

    bool wordBreakUtil(string A,vector<string> &B,vector<string> &ans)
    {
        if(A.length()==0)
         {
             return true;
         }
        for(int i=1;i<=A.length();i++)
         {
             if(containsWord(B,ans,A.substr(0,i)) && wordBreakUtil(A.substr(i),B,ans))
              return true;
         }
        return false; 
    }
 
    int wordBreak(string A, vector<string> &B) {
        //code here
        vector<string> ans;
        return wordBreakUtil(A,B,ans);
    }