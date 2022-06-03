// TC->O(N) SC-> O(power(2,|s|))

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>s.length()){
            return false;
        }
        int p=0,val=0;
        for(int i=k-1;i>=0;i--){
            val+=(s[i]-48)*pow(2,p++);
        }
        set<int> st;
        int limit=pow(2,k)-1;
        st.insert(val);
        for(int i=k;i<s.length();i++){
            val<<=1;
            val&=limit;
            val|=(s[i]-48);
            st.insert(val);
        }
        return st.size()==limit+1;
    }
};