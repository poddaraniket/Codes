 bool ispar(string x)
    {
        stack<char> s;
        for(int i=0;i<x.length();i++){
            if(x[i]=='{' || x[i]=='(' || x[i]=='[') 
             s.push(x[i]);
            else{
                if(x[i]=='}'){
                    if(!s.empty() && s.top()=='{')
                     s.pop();
                    else
                     return false;
                }else if(x[i]==')'){
                    if(!s.empty() && s.top()=='(')
                     s.pop();
                    else
                     return false;
                }else if(x[i]==']'){
                    if(!s.empty() && s.top()=='[')
                     s.pop();
                    else
                     return false;
                }
            } 
        }
    if(s.size()>0)
     return false;
    return true; 
    }