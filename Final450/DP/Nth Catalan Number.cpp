// C(n)= (2nCn)/(n+1)
    
    cpp_int findCatalan(int n) 
    {
        //code here
        int r=n;
        n*=2;
        cpp_int res=1;
        for(int i=0;i<r;i++){
            res*=(n-i);
            res/=(i+1);
        }
        return res/(r+1);
    }