//unimodal permuataion is the permutaion of set of numbers such that first its increasing the nuumbers are in decreasing order
// here all permutaions except unimodal will form a cycle

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    long long int n,fact=1,res=1;
    cin>>n;
    for(int i=1;i<=n-1;i++)
     {
        fact*=i;
        res*=2;
        fact%=1000000007;
        res%=1000000007;
     }
    fact*=n;
    fact%=1000000007;
    fact-=res;
    fact%=1000000007;
    if(fact<0)
     fact+=1000000007;
    cout<<fact<<endl; 
}