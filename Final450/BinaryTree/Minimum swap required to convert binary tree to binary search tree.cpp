#include <bits/stdc++.h>
using namespace std;


// Inorder gives ascending value in BST 
void inorder(int a[],vector<int> &v,int n,int index){
    if(index>=n)
     return;
    inorder(a, v, n, 2*index+1);
    v.push_back(a[index]);
    inorder(a, v, n, 2*index+2);
}

int minSwaps(std::vector<int> &v)
{
    vector<pair<int,int>> val;
    for(int i=0;i<v.size();i++)
     {
        val.push_back({v[i],i});
     }
    int c=0; 
    sort(val.begin(),val.end());
    for(int i=0;i<val.size();i++)
     {
        if(val[i].second==i)
         continue;
        swap(val[i],val[val[i].second]) ;
        c++;
        i--;
     }
    return c; 
}

int main()
{
    int a[] = { 5, 6, 7, 8, 9, 10, 11 };
    int n = sizeof(a) / sizeof(a[0]);
    std::vector<int> v;
    inorder(a, v, n, 0);
    cout << minSwaps(v) << endl;
    
}