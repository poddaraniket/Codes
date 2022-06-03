//O(N)
ull getNthUglyNo(int n) {
	    // code here
	    ull ugly[n]={0};
        ugly[0]=1;
        ull i2=0,i3=0,i5=0;
        // Every number is the sequence of multiple of either 2 , 3 or 5
        for(ull i=1;i<n;i++)
        {
            ugly[i]=min(min(ugly[i2]*2,ugly[i3]*3),ugly[i5]*5);
            if(ugly[i]==ugly[i2]*2) 
             i2++;
            if(ugly[i]==ugly[i3]*3) 
             i3++;
            if(ugly[i]==ugly[i5]*5) 
             i5++; 
        }
        return ugly[n-1];
	}