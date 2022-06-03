#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void jump(int x,int num)
{
    queue<int> q;
    q.push(num);
    while(!q.empty())
    {
        num=q.front();
        q.pop();
        if(num<=x)
        {
            v.push_back(num);
            int last_digit=num%10;
            if(last_digit==0)
             q.push((num*10)+(last_digit+1));
            else if(last_digit==9)
             q.push((num*10)+(last_digit-1));
            else
             {
                q.push((num*10)+(last_digit-1)); 
                q.push((num*10)+(last_digit+1)); 
             }
        }
    }
}


void printing_jump(int x)
{
    for(int i=1;i<=9 && i<=x;i++)
    {
        jump(x,i);
    }
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	   int n;
	   cin>>n;
	   printing_jump(n);
	   sort(v.begin(),v.end());
	   cout<<"0"<<" ";
	   for(int i=0;i<v.size();i++)
	    cout<<v[i]<<" ";
	   cout<<endl;
	   v.clear();
	}
	return 0;
}