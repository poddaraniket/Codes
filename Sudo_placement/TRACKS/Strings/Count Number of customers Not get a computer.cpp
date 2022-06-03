#include <bits/stdc++.h>
using namespace std;

int runCustomerSimulation(int n,string s){
    int a[26]={0};
    int count=0;
    for(int i=0;i<s.length();i++){
        if(a[s[i]-'A']==0)
         {
            if(n<=0)
             {
              //   cout<<"*"<<i<<endl;
                 count++;
                 a[s[i]-'A']=-1;
                 continue;
             } 
            else{
                n--;
                a[s[i]-'A']=1;
            } 
         }
        else if(a[s[i]-'A']==1){
            n++;
            a[s[i]-'A']=0;
        } 
        else{
          continue;  
        }
    }
    return count;
}

int main() {
	// your code goes here
	int n;
	string s;
	cin>>n>>s;
	cout<<runCustomerSimulation(n,s)<<endl;
	return 0;
}
