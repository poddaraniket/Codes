#include <bits/stdc++.h>
using namespace std;
 
void prob(int c,int t)
{
  int i,pro1=1,pro2=1;
  double ans;
  for(i=t+1;i<=c;i++)
    pro1*=i;
  for(i=1;i<=c-t;i++)
    pro2*=i;
  ans=pro1/pro2;
  ans/=pow(2,c);
  cout<<setprecision(12)<<ans<<endl;
}
 
int main() {
	string sent,recv;
	cin>>sent>>recv;
	int i,sen=0,rev=0,c=0;
	for(i=0;i<sent.size();i++)
	 {
	 	if(sent[i]=='+')
	 	  sen++;
	 	else
	 	  sen--;
	 	if(recv[i]=='+')
	 	  rev++;
	 	else if(recv[i]=='-')
	 	  rev--;
	 	else
	 	  c++;
	 }
	if(c==0)
	 {
	 	if(sen==rev)
	 	  cout<<"1.000000000000"<<endl;
	 	else
	 	  cout<<"0.000000000000"<<endl;
	 }
	else
	 {
	 	int diff=sen-rev;
    int diff1=c-abs(diff); 
    if(c>=0 && diff1%2==0 && diff1>=0)
     {
      if(diff==0)
	 	  {
	 	  	if(c%2!=0)
	 	  	  cout<<"0.000000000000"<<endl;
	 	  	else
	 	  	  {
	 	  	  	int temp=c/2;
            prob(c,temp);
	 	  	  }
       }
      else
        {
          int t=abs(diff)+(diff1/2);
          prob(c,t);    
        }      
     } 
	 	else
      cout<<"0.000000000000"<<endl;
	 }  
}