#include<bits/stdc++.h>
 
using namespace std;
 
void findAllAnagrams(string arr[],int n)
{
    map<string,vector<int>> mp;
    for(int i=0;i<n;i++)
     {
        string temp=arr[i]; 
        sort(temp.begin(),temp.end()); //O(|temp| log|temp|)
        mp[temp].push_back(i);
     }
    for(auto it=mp.begin();it!=mp.end();it++)
     {
         
        vector<int> v=it->second;
        if(v.size()>1){
        for(int i=0;i<v.size();i++)
         cout<<arr[v[i]]<<" ";
        cout<<endl; 
        }
     }
}
 
int main()
{
    string arr[] = {"geeksquiz", "geeksforgeeks", "abcd",
                    "forgeeksgeeks", "zuiqkeegs"};
    int n = sizeof(arr)/sizeof(arr[0]);
    findAllAnagrams(arr, n);
    return 0;
}