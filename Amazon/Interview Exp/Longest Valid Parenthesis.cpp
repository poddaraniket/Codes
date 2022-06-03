int maxLength(string S){
        // code here
        stack<int> s;
        int maxLength=0;
        for(int i=0;i<S.length();i++)
         {
             if(s.empty() || S[i]=='(')
              s.push(i);
             else
              {
                  if(S[s.top()]=='(')
                   {
                       s.pop();
                       if(s.empty())
                        maxLength=max(maxLength,i+1);
                       else
                        maxLength=max(maxLength,i-s.top());
                   }
                  else
                   s.push(i);
              }
         }
        return maxLength; 
    }