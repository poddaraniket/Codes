class Solution {
    int m=1000000007;
public:
    
    int mul(int a,int b)
    {
        return (a%m)*(b%m);
    }
    
    int uniqueLetterString(string s) {
       vector<int> v[26];
       int n=s.length(); 
       for(int i=0;i<s.length();i++)
        {
           if(v[s[i]-'A'].size()==0)
              v[s[i]-'A'].push_back(-1);
           v[s[i]-'A'].push_back(i);
        }
       int ans=0; 
       for(int i=0;i<26;i++)
       {
           if(v[i].size()==0)
               continue;
           v[i].push_back(n);
           for(int j=1;j<v[i].size()-1;j++)
           {
              int temp=mul((v[i][j]-v[i][j-1]),(v[i][j+1]-v[i][j]));
              ans=(ans+temp)%m;
           }
       }
       return ans; 
    }
};