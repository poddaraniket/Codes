#include <boost/multiprecision/cpp_int.hpp>
#include<bits/stdc++.h>
using namespace boost::multiprecision; 
using namespace std;
void binomial(unsigned int n,unsigned int r)
{
    int1024_t res=1;
    int i;
    if (r > n - r) 
        r = n - r; 
    for(i=0;i<r;i++)
     {
         res*=(int1024_t)(n-i);
         res/=(int1024_t)(i+1);
     }
    cout<<res<<endl;  
}
 
int main()
{
    int t;
    cin>>t;
    while(t--)
     {
      int n,m;
      cin>>n>>m;
      binomial(m+n,n);
     }
}