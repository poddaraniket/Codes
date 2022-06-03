// Only 1 & 7 are Happy NUmbers < 10

class Solution {
public:
    bool isHappy(int n) {
        if(n==1 || n==7)
            return true;
        int sum=0;
        while(n){
            int rem=n%10;
            sum+=(rem*rem);
            n/=10;
            if(n==0)
            {
                if(sum==1 || sum==7)
                  return true; 
                if(sum<10)
                  return false;  
                n=sum;
                sum=0;
            }
        }
       return (sum==7) ? true : false; 
    }
};