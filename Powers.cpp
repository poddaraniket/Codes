#include<bits/stdc++.h>
using namespace std;

int power(int x,int y)
{
	if(y==0)
		return 1;
	int temp=power(x,y/2);
	if(y%2==0)
		return temp*temp;
	else
	{
		if(y>0)
			retrun x*temp*temp;
		else
			return (temp*temp)/x;
	}
}

int main(){
	int x,y;
    cin>>x>>y;
    cout<<power(x,y)<<endl;
}