#include <bits/stdc++.h>
using namespace std;

int divide(int dividend,int divisor)
{
    int sign = ((dividend < 0) ^
              (divisor < 0)) ? -1 : 1;
 
  // remove sign of operands
  dividend = abs(dividend);
  divisor = abs(divisor);
  
  int rsult=0;
  while(dividend-divisor>=0)
   {
       int count=0;
       //kitni baar double karne mai humey dividend-divisor>0 milega
       // <<1 means double
    while(dividend-(divisor<<1<<count)>=0)  // 3*2 or 3*(2*2) or 3*(2*2*2) -> how many times 2 will come will depend in count
     {
         count++;
     }
    rsult+=1<<count;
    dividend-=divisor<<count;
   }
   return sign>0?rsult:-rsult;
}


int main() {
  int a = 10, b = 3;
  cout << divide(a, b) << "\n";
 
  a = 43, b = -8;
  cout << divide(a, b);
 
  return 0;
}


/*#include <bits/stdc++.h>
using namespace std;

int divide(int dividend,int divisor)
{
    int sign = ((dividend < 0) ^
              (divisor < 0)) ? -1 : 1;
 
  // remove sign of operands
  dividend = abs(dividend);
  divisor = abs(divisor);
  
  int rsult=0;
  while(dividend-divisor>=0)
   {
       int count=0;
       //kitni baar double karne mai humey dividend-divisor>0 milega
       // <<1 means double
    while(dividend-(divisor<<count)>=0)  // 3*2 or 3*(2*2) or 3*(2*2*2) -> how many times 2 will come will depend in count
     {
         count++;
     }
    rsult+=1<<(count-1);
    dividend-=divisor<<(count-1);
   }
   return sign>0?rsult:-rsult;
}


int main() {
  int a = 10, b = 3;
  cout << divide(a, b) << "\n";
 
  a = 43, b = -8;
  cout << divide(a, b);
 
  return 0;
} */