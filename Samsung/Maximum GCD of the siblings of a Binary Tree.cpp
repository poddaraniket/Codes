// GCD of the siblings of a binary tree [O(N)]
 
#include <bits/stdc++.h>
using namespace std;
 
int gcd(int a,int b)
{
    if(a==0)
     return b;
    return gcd(b%a,a); 
}
 
// Function to find maximum GCD
int max_gcd(vector<pair<int, int> >& v)
{
    if(v.size()==0 || v.size()==1)
     return 0;
    sort(v.begin(),v.end());
    pair<int,int> a=v[0];
    pair<int,int> b;
    int maxGcd=0;
    for(int i=0;i<v.size();i++)
     {
        b=v[i];
        if(a.first==b.first)
         {
            maxGcd=max(maxGcd,gcd(a.second,b.second)); 
         }
        a=b; 
     }
}
 
// Driver function
int main()
{
    vector<pair<int, int> > v;
    v.push_back(make_pair(5, 4));
    v.push_back(make_pair(5, 8));
    v.push_back(make_pair(4, 6));
    v.push_back(make_pair(4, 9));
    v.push_back(make_pair(8, 10));
    v.push_back(make_pair(10, 20));
    v.push_back(make_pair(10, 30));
 
    cout << max_gcd(v);
    return 0;
}