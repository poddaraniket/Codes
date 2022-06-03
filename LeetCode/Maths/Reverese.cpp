class Solution {
public:
    int reverse(int y) {
        long long int sum=0,neg=0;
        long long int x=(long long int)y;
        if(x<0)
         {
            x*=(-1);
            neg=1; 
         }
        while(x>0)
         {
            int mod=x%10;
            sum=(sum*10)+mod;
            x/=10;
         }
        if(neg==1)
         {
          sum*=-1;
            if(sum>=-2147483648)
                return sum;
         }
        else
        {
            if(sum<2147483648)
                return sum;
        }
        return 0;
    }
};