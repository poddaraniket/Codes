//O(N)

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int oddFreq[100001]={0};
        int evenFreq[100001]={0};
        for(int i=0;i<nums.size();i++){
            if(i%2!=0){
                oddFreq[nums[i]]++;
            }else{
                evenFreq[nums[i]]++;
            }
         }
       int oddMax,oddMaxFreq=0;
       for(int i=0;i<=100000;i++){
           if(oddMaxFreq<oddFreq[i]){
               oddMax=i;
               oddMaxFreq=oddFreq[i];
           }
       }
        int oddSecondMax,oddSecondMaxFreq=0;
       for(int i=0;i<=100000;i++){
           if(oddSecondMaxFreq<oddFreq[i] && i!=oddMax){
               oddSecondMax=i;
               oddSecondMaxFreq=oddFreq[i];
           }
       }
       int evenMax,evenMaxFreq=0;
       for(int i=0;i<=100000;i++){
           if(evenMaxFreq<evenFreq[i]){
               evenMax=i;
               evenMaxFreq=evenFreq[i];
           }
       }
        int evenSecondMax,evenSecondMaxFreq=0;
       for(int i=0;i<=100000;i++){
           if(evenSecondMaxFreq<evenFreq[i] && i!=evenMax){
               evenSecondMax=i;
               evenSecondMaxFreq=evenFreq[i];
           }
       }
       if(oddMax!=evenMax){
           return n-oddMaxFreq-evenMaxFreq;
       }
       return min(n-oddMaxFreq-evenSecondMaxFreq,n-oddSecondMaxFreq-evenMaxFreq);
    }
};