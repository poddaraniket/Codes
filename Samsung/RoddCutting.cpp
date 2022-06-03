//O(N^2)

int val[n+1]={0};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i<=j)
                 {
                     val[j]=max(val[j],val[j-i]+price[i-1]);
                 }
            }
        }
        return val[n];