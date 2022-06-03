int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int b=s.top();
                s.pop();
                int a=s.top();
                s.pop();
                int c;
                if(tokens[i]=="+")
                  c=a+b;
                else if(tokens[i]=="*")
                  c=a*b;
                else if(tokens[i]=="/")
                  c=a/b;
                else if(tokens[i]=="-")
                  c=a-b;
                s.push(c);
            }else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }