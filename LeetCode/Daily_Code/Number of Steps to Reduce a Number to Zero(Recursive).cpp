//Recursive Solution

class Solution {
public:
    int numberOfSteps(int num) {
      if(num==0){
          return 0;
      }
      int oddSteps=0;
      if(num%2){
          oddSteps=1;
          num-=1;
      } 
      int evenSteps=0;  
      if(num>0)  
        evenSteps=1+numberOfSteps(num/2);
      return oddSteps+evenSteps;  
    }
};