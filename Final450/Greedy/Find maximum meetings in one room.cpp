#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b)
{
    return a.second.second<b.second.second;
}

void maxMeeting(int s[],int f[],int n)
{
    vector<pair<int,pair<int,int>>> timing;
    for(int i=0;i<n;i++)
     {
         timing.push_back({i+1,{s[i],f[i]}});
     }
    sort(timing.begin(),timing.end(),cmp); 
    cout<<timing[0].first<<" ";
    int tym=timing[0].second.second;
    for(int i=1;i<n;i++){
        if(timing[i].second.first>tym)
         {
            tym=timing[i].second.second;
            cout<<timing[i].first<<" ";
         }
    }
    cout<<endl;
}

int main()
{
    // Starting time
    int s[] = {75250, 50074, 43659, 8931, 11273, 27545, 50879, 77924};
     
    // Finish time
    int f[] = {112960, 114515, 81825, 93424, 54316, 35533, 73383, 160252 } ;
     
    // Number of meetings.
    int n = sizeof(s) / sizeof(s[0]);
 
    // Function call
    maxMeeting(s, f, n);
 
    return 0;
}