/*

// step 1 : find the min no. of removals needed to get the parenthensis valid(k)
(index,more brackets left to remove)



          )())()  (())()    ()))()     ()()()     ()()()     ()()))     ()())(
        (0,0)\  (1,0)\  (2,0) \    (3,0) |     (4,0) /    (5,0) /    (6,0) /
              \       \        \         |          /          /          /
                                   ()())() -> k=1 




TC -> 

*/





class Solution {
public:
    
    int getMin(string s){
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]>='a' && s[i]<='z')
                continue;
            if(st.empty() || s[i]=='(')
                st.push(s[i]);
            else{
                if(s[i]==')' && st.top()=='(')
                  st.pop();
                else{
                    st.push(s[i]);
                } 
            }
            
        }
        return st.size();
    }
    
    void valid(string s,set<string> &ans,int k){
        if(k==0){
            int noOfRemoval=getMin(s);
            // cout<<s<<" "<<noOfRemoval<<endl;
            if(noOfRemoval==0){
                ans.insert(s);
            }
            return;
        }
        for(int i=0;i<s.length();i++){
            if(s[i]!='(' && s[i]!=')')
                continue;
            string left=s.substr(0,i);
            string right=s.substr(i+1);
            // cout<<left+right<<"  "<<i<<endl;
            valid(left+right,ans,k-1);
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int noOfRemoval=getMin(s);
        cout<<noOfRemoval<<endl;
        set<string> ans;
        valid(s,ans,noOfRemoval);
        vector<string> v;
        for(string it : ans){
            v.push_back(it);
        }
        return v;
    }
};