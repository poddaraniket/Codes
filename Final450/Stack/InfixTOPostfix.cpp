bool isOperand(char s){
  // cout<<s<<endl;
    if((s>='a' && s<='z') || (s>='A' && s<='Z') || (s>= '0' && s<= '9'))
     return true;
    return false; 
}

int prec(char s){
    if(s=='^')
     return 3;
    if(s=='*' || s=='/')
     return 2;
    return 1; 
}

char opening(char s){
    if(s==']')
     return '[';
    if(s=='}')
     return '{';
    return '(';
}

bool isOpening(char s){
    if(s=='[' || s=='{' || s=='(')
     return true;
    return false; 
}

bool isClosing(char s){
    if(s==']' || s=='}' || s==')')
     return true;
    return false; 
}

class Solution
{
    public:
    //Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        // Your code here
        stack<char> op;
        string res="";
        for(int i=0;i<s.length();i++){
            //cout<<"$"<<endl;
            if(isOperand(s[i]))
            {
                //cout<<s[i]<<endl;
                res+=s[i];
            }
            else{
                //cout<<"#"<<endl;
                if(isOpening(s[i]))
                 op.push(s[i]);
                else if(isClosing(s[i]))
                {
                    char open=opening(s[i]);
                    while(!op.empty() && op.top()!=open){
                        res+=op.top();
                        op.pop();
                    } 
                    op.pop();
                }
                else{
                    while(!op.empty() && prec(s[i])<=prec(op.top()) && !isOpening(op.top())){
                      //  cout<<op.top()<<endl;
                        res+=op.top();
                        op.pop();
                    }
                    op.push(s[i]);
                }
            }
        }
        while(!op.empty()){
            res+=op.top();
            op.pop();
        }
        return res;
    }
};