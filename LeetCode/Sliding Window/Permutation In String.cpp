class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      if(s1.length()>s2.length())
          return false;  
      int hash_str[26]={0};
      int hash_patt[26]={0};
      int count=0;  
      for(int i=0;i<s1.length();i++)
       {
          hash_patt[s1[i]-'a']++;
       }
      for(int i=0;i<s1.length();i++)
       {
          hash_str[s2[i]-'a']++;
          if(hash_str[s2[i]-'a']<=hash_patt[s2[i]-'a'])
             count++; 
       }
      if(count==s1.length())
         return true;
      for(int i=s1.length();i<s2.length();i++)
       {
          hash_str[s2[i-s1.length()]-'a']--;
          if(hash_str[s2[i-s1.length()]-'a']<hash_patt[s2[i-s1.length()]-'a'])
             count--;
          hash_str[s2[i]-'a']++;
          if(hash_str[s2[i]-'a']<=hash_patt[s2[i]-'a'])
             count++;
          if(count==s1.length())
             return true; 
       }
      return false;  
    }
};