bool isPalindrome(string s){
        // if(s.length()==0)
        //  return false;
        string t=s;
        reverse(s.begin(),s.end());
        return s==t;
    }
    
    bool palindromepair(int N, string arr[]) {
        // code here
        if(N==1)
         return false;
        unordered_map<string,int> mp;
        for(int i=0;i<N;i++)
         {
             string s=arr[i];
             reverse(s.begin(),s.end());
             mp[s]=i;
         }
        for(int i=0;i<N;i++)
         {
            for(int j=1;j<=arr[i].length();j++)
             {
                 string left=arr[i].substr(0,j);
                 string right=arr[i].substr(j);
                 
                 // geekf , keeg [left=geek right=f]
                 //cout<<left<<" "<<mp[left]<<endl;
                 if(mp.find(left)!=mp.end() && mp[left]!=i &&  isPalindrome(right)){
                    // cout<<left<<" "<<right<<endl;
                  return true;
                 }
                 // xyxabc , cba [right=abc left=xyx]
                 if(mp.find(right)!=mp.end() && mp[right]!=i && isPalindrome(left)){
                  return true;
                 }
             }
         }
        return false; 
    }