//O(logN^2)
int divide(int dividend, int divisor) {
        if(dividend==INT_MIN  && divisor==-1)
            return INT_MAX;
        bool isNeg=(dividend>=0) == (divisor>=0) ? true : false;
        long long x=abs((long)dividend);
        long long y=abs((long)divisor);
        // cout<<isNeg<<endl;
        long long result=0;
        while(x>=y){
            long long temp=y;
            long long count=1;
            while(x>=(temp<<1)){
                temp=temp<<1;
                count=count<<1;
            }
            // cout<<(1<<count)<<endl;
            // cout<<(divisor<<count)<<endl;
            result+=(count);
            x-=(temp);  //divisor * 2^count
        }
       return isNeg ? result : -result;
    }