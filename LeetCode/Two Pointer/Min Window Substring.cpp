class Solution {
public:
    string minWindow(string s, string t) {  
      if(s.length()<t.length())
          return "";
      int hash_str[256]={0};
      int hash_pat[256]={0};
      for(int i=0;i<t.length();i++)
       {
          hash_pat[t[i]]++;
       }
      int start=0,count=0,min_length=s.length()+5,index=-1;  
      for(int i=0;i<s.length();i++)
       {
          hash_str[s[i]]++;
          if(hash_str[s[i]]!=0 && hash_str[s[i]]<=hash_pat[s[i]])
             count++;  
          if(count==t.length())
           {
             while(hash_str[s[start]]>hash_pat[s[start]] || hash_str[s[start]]==0)
              {
                if(hash_str[s[start]]>hash_pat[s[start]])
                    hash_str[s[start]]--;
                start++; 
              }
             if(i-start+1<min_length)
              { 
                min_length=i-start+1;
                index=start;  
                //cout<<min_length<<endl;   
              } 
           }
       }
      if(index==-1) 
          return "";
      return s.substr(index,min_length);
    }
};