class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length())
            return "";
        int len=t.length();
        int freq_str[256]={0};
        int freq_pat[256]={0};
        for(int i=0;i<len;i++){
            freq_pat[t[i]]++;
        }
        int minLength=s.length()+5,index=-1,count=0,start=0;
        for(int i=0;i<s.length();i++){
            freq_str[s[i]]++;
            if(freq_str[s[i]]<=freq_pat[s[i]])
               count++; 
            // remove the extra chracters added
            if(count==t.length()){
                while(freq_str[s[start]]>freq_pat[s[start]]){
                    freq_str[s[start]]--;
                    start++;
                }
                if(i-start+1<minLength){
                    cout<<"*"<<endl;
                    minLength=i-start+1;
                    index=start;
                }
            }
        }
        return (index==-1) ? "" : s.substr(index,minLength);
    }
};