class Solution {
public:
    
    bool isOperand(char a){
        if(a=='+' || a=='-' || a=='*' || a=='/')
            return true;
        return false;
    }
    
    int eval(int a,int b,char exp){
        // cout<<a<<" "<<b<<" "<<exp<<endl;
        if(exp=='+')
            return a+b;
        else if(exp=='-')
            return a-b;
        else if(exp=='*')
            return a*b;
        else 
            return a/b;
    }
    
    int calculate(string s) {
        map<char,int> mp;
        mp['+']=0;
        mp['-']=0;
        mp['*']=1;
        mp['/']=1;
        stack<char> operands;
        stack<int> operators;
        int i=0;
        while(i<s.length()){
            int temp=0;
            while(i<s.length() && !isOperand(s[i])){
                if(s[i]!=' '){
                    int digit=s[i]-'0';
                    temp*=10;
                    temp+=digit;
                }
                i++;
            }
            operators.push(temp);
            if(i==s.length())
                break; 
            // cout<<temp<<" "<<s[i]<<endl;
            while(!operands.empty() && mp[operands.top()]>=mp[s[i]]){
                // cout<<operands.top()<<" "<<mp[operands.top()]<<endl;
                char operand=operands.top();
                operands.pop();
                int b=operators.top();
                operators.pop();
                int a=operators.top();
                operators.pop();
                operators.push(eval(a,b,operand));
            }
            operands.push(s[i]);
            i++;
        }
        // cout<<"$"<<endl;
        while(!operands.empty()){
            char operand=operands.top();
            operands.pop();
            int b=operators.top();
            operators.pop();
            int a=operators.top();
            operators.pop();
            // cout<<a<<" "<<b<<" "<<operand<<endl;
            operators.push(eval(a,b,operand));
        }
        return operators.top();
    }
};