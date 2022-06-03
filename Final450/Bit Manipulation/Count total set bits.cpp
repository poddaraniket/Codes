//O(logN)

int countSetBits(int n)
    {
        // Your logic here
        if(n==0)
         return 0;
        int p=log2(n);
        int ans=pow(2,p-1)*p+(n-pow(2,p)+1)+countSetBits(n-pow(2,p));
        return ans;
    }