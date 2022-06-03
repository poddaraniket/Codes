string LCP(string s1,string s2){
        //cout<<s1<<" "<<s2<<endl;
        int p=0;
        string ans="";
        while(1){
            //cout<<"*"<<endl;
            if(p>=s1.length() || p>=s2.length())
              break;
            if(s1[p]!=s2[p])
             break;
            ans+=s1[p];
            p++;
        }
        return ans;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
       string prefix=strs[0];
       for(int i=1;i<strs.size();i++){
           prefix=LCP(prefix,strs[i]);
       } 
       return prefix; 
    }