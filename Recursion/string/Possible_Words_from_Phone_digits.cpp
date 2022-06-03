#include <bits/stdc++.h>
using namespace std;

string mobile[8]={"ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

unordered_set<string> coll;

void possible(int a[],string s,int index,int n)
{
    if(index==n)
     {
        coll.insert(s);
        return;
     }
    int dig=a[index];
    string temp=mobile[dig-2];
    for(int i=0;i<temp.length();i++)
     {
        possible(a,s+temp[i],index+1,n);
     }
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	 {
	     cin>>a[i];
	 }
	possible(a,"",0,n); 
	for(auto it=coll.begin();it!=coll.end();it++)
	  cout<<*it<<endl;
	return 0;
}
