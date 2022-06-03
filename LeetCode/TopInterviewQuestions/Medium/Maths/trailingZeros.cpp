//O(log5(N))

class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        int i=1;
        while(1)
        {
            if(pow(5,i)>n)
              break;
            count+=n/(pow(5,i));
            i++;        
        }
       return count;
    }
};