int minimumNumberOfSwaps(string s){
    vector<int> v;
    for(int i=0;i<s.length();i++){
        if(s[i]=='[')
         v.push_back(i);
    }
    int count=0,idx=0,ans=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='[')
         {
             count++;
             idx++;
         }
        else{
            count--;
            if(count<0){
                ans+=v[idx]-i;
                swap(s[i],s[v[idx]]);
                count=1;
                idx++;
            }
        } 
    }
    return ans;
  }