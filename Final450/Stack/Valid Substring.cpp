 int findMaxLen(string s) {
        // code here
        int maxlength=0;
        stack<int> st;
        st.push(-1);
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
             st.push(i);
            else{
                if(!st.empty()){
                    st.pop();
                }
                if(!st.empty())
                 maxlength=max(maxlength,i-st.top());
                else
                 st.push(i);
            }
        }
        return maxlength;
    }