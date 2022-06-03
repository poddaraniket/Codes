int palindromicPartition(string str)
    {
        // code here
        //label the palidromes
        int n=str.length();
        vector<vector<bool>> palindromes(n,vector<bool>(n));
        for(int i=0;i<n;i++){
            palindromes[i][i]=true;
        }
        for(int gap=1;gap<n;gap++){
            for(int i=0,j=gap;j<n;j++,i++){
                if(gap==1){
                    if(str[i]==str[j])
                     palindromes[i][j]=true;
                    else
                     palindromes[i][j]=false;
                }else{
                    if(str[i]==str[j]){
                        palindromes[i][j]=palindromes[i+1][j-1];
                    }else{
                        palindromes[i][j]=false;
                    }
                }
            }
        }
        vector<int> v(n);
        v[0]=0;
        if(str[0]==str[1])
         v[1]=0;
        else{
         v[1]=1;
        } 
        for(int j=2;j<str.length();j++){
            int mini=INT_MAX;
            if(palindromes[0][j]){
                v[j]=0;
                continue;
            }
            for(int i=j;i>=1;i--){
                if(palindromes[i][j]){
                    mini=min(mini,v[i-1]);
                }
            }
            v[j]=mini+1;
        }
        return v[n-1];
    }