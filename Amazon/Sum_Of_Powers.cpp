#include <bits/stdc++.h>
using namespace std;

int count(int sum,int po,int num)
{
    int val=sum-pow(num,po);
    if(val==0)
     return 1;
    if(val<0) 
     return 0;
    return count(sum,po,num+1)+count(val,po,num+1); 
}

int main() {
    int x,n;
    cin>>x>>n;
    cout<<count(x,n,1)<<endl;
	// your code goes here
	return 0;
}
