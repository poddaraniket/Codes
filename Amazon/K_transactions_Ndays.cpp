#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int k,day,i,j,m;
    cin>>day>>k;
    int price[day];
    for(i=0;i<day;i++)
     cin>>price[i];
    int profit[k+1][day];
    for(i=0;i<day;i++)
     profit[0][i]=0;
    for(i=0;i<=k;i++)
     profit[i][0]=0;
    for(i=1;i<=k;i++)
     {
        int maxdiff=INT_MIN; 
        for(j=1;j<day;j++)
         {
            maxdiff=max(maxdiff,profit[i-1][j-1]-price[j-1]);
            profit[i][j]=max(profit[i][j-1],price[j]+maxdiff); 
         }
     }
    cout<<profit[k][day-1]; 
}