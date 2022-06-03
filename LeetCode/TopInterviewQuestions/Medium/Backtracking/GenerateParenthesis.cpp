//O(N*2^N)

class Solution {
public:
    
    void generate(vector<string> &ans,int n,int &open,int &close,string &s){
        if(close==n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            //do
            s.push_back('(');
            open++;
            //recur
            generate(ans,n,open,close,s);
            //undo
            s.pop_back();
            open--;
        }
        if(close<open){
           //do
           s.push_back(')');
           close++;
           //recur
           generate(ans,n,open,close,s); 
           //undo
           s.pop_back();
           close--;
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        int open=0,close=0;
        generate(ans,n,open,close,s);
        return ans;
    }
};