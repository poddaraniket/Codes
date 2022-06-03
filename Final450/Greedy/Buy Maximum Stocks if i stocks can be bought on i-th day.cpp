#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b)
{
    return a.first<b.first;
}

int buyMaximumProducts(int n,int k,int price[])
{
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
     {
         v.push_back({price[i],i+1});
     }
    sort(v.begin(),v.end(),cmp); 
    int stocks=0;
    for(int i=0;i<n;i++)
     {
        if(k==0)
         break;
        int val=k/v[i].first;
        stocks+=min(val,v[i].second);
        k=val>v[i].second?k-(v[i].second*v[i].first):0;
     }
    return stocks; 
}

int main()
{
    int price[] = {  7,10, 14 };
    int n = sizeof(price)/sizeof(price[0]);
    int k = 100;
 
    cout << buyMaximumProducts(n, k, price) << endl;
 
    return 0;
}