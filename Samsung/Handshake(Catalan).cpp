  //(O(r))
 int count(int N){
        // code here
        int r=N/2;
        long long res=1;
        for(int i=0;i<r;i++)
        {
            res*=(N-i);
            res/=(i+1);
            //cout<<res<<" ";
        }
       // cout<<endl;
        return res/(r+1);
    }