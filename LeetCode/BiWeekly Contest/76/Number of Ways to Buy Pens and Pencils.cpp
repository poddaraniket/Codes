class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long sum=total/cost2 + 1;
        while(total){
            total-=cost1;
            if(total<0)
                break;
            if(total==0)
             {
                sum++;
                break;
             }
            sum+=(total/cost2)+1;
        }
        return sum;
    }
};