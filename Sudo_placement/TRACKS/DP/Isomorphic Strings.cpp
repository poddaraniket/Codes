 bool areIsomorphic(string str1, string str2)
    {
        if(str1.length()!=str2.length())
         return false;
        int loc1[256]={0},loc2[256]={0};
        // memset(loc1,-1,loc1+256);
        // memset(loc2,-1,loc2+256);
        for(int i=0;i<str1.length();i++){
            if(loc1[str1[i]]==loc2[str2[i]]){
                loc1[str1[i]]=i+1;
                loc2[str2[i]]=i+1;
                continue;
            }
            return false; 
        }
        return true;
    }