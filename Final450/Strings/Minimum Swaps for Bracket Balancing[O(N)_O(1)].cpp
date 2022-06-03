int minimumNumberOfSwaps(string s){
    
    int openB=0,closeB=0,fault=0,ans=0;
    for(int i=0;i<s.length();i++){
        if(s[i]==']')
         {
            closeB++;
            fault=closeB-openB;
         }
        else{
            openB++;
            if(fault>0){
                ans+=fault;
                fault--;
            }
        } 
    }
    return ans;
  }