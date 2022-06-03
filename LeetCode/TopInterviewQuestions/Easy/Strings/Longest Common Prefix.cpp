class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1)
            return strs[0];
        int l=0;
        string str=strs[0]; 
        while(1){
             if(l==str.length())
                 break;
             char s=str[l];   
             for(int i=1;i<strs.size();i++){
                 if(l==strs[i].length() || s!=strs[i][l])
                     return str.substr(0,l);
              }
             l++;
        }
        return str.substr(0,l);
    }
};