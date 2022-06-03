#include <bits/stdc++.h>
using namespace std;

vector<string> lis[3] ={{ "John", "Emma" },{ "Plays", "Hates", "Watches" },{ "Cricket", "Soccer", "Chess" }};

set<string> coll;

void combination(string ans,int dig,int n)
{
    if(dig==n)
     coll.insert(ans);
    int m=lis[dig].size();
    for(int i=0;i<m;i++)
     {
        combination(ans+lis[dig][i]+" ",dig+1,n);
     }
}


int main() {
	// your code goes here
	//int n= sizeof(list)/sizeof(list[0]);
	combination("",0,3);
	for(auto it=coll.begin();it!=coll.end();it++)
	 {
	     cout<<*it<<endl;
	 }
	//cout<< 
	return 0;
}
