#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int x1,y1,x2,y2,diff1,diff2;
  cin>>x1>>y1>>x2>>y2;
  diff1=abs(x1-x2);
  diff2=abs(y1-y2);
  if(diff1==diff2)
   {
     cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1<<endl;
   }
  else if(diff1==0)
   {
     int x=x1+diff2; 
     cout<<x<<" "<<y1<<" "<<x<<" "<<y2<<endl;
   }
  else if(diff2==0)
   {
     int y=y1+diff1;
     cout<<x1<<" "<<y<<" "<<x2<<" "<<y<<endl;
   }  
  else
   cout<<"-1"<<endl; 
}
