void paren(string word,int op,int cl,vector<string> &v)
    {
        if(cl==0 && op==0){
           v.push_back(word);
           return;
        }
        if(op>0)
         {
            paren(word+"(",op-1,cl,v);
         }
        if(cl>op)
        {
            paren(word+")",op,cl-1,v);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> s;
        paren("",n,n,s);
        return s;
    }