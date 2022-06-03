 vector<string> v;
    void letterCombinationsUtil(string number,string s,string alpha[])
    {
        if(number.length()==0)
        {
          v.push_back(s);
          return;
        }
        int pos=number[0]-'0';
        for(int k=0;k<alpha[pos-2].length();k++)
         {
            letterCombinationsUtil(number.substr(1),s+alpha[pos-2][k],alpha); 
         }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)
             return v;
        string alpha[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        letterCombinationsUtil(digits,"",alpha);
        return v;
    }