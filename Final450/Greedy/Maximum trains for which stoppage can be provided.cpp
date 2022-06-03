#include <bits/stdc++.h>
using namespace std;

#define n 2
#define m 5

bool cmp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b)
{
    return a.second.second<b.second.second;
}

int maxStop(int arr[][3])
{
    vector<pair<int,pair<int,int>>> trains;
    int platforms=0;
    for(int i=0;i<m;i++)
     {
        trains.push_back({arr[i][2],{arr[i][0],arr[i][1]}}); 
        platforms=max(platforms,arr[i][2]);
     }
    sort(trains.begin(),trains.end(),cmp); 
    int lastTrain[platforms+1]={0};
    int count=0;
    for(int i=0;i<trains.size();i++)
     {
        if(trains[i].second.first>=lastTrain[trains[i].first]) 
         {
            count++;
            lastTrain[trains[i].first]=trains[i].second.second;
         }
     }
    return count; 
}

int main()
{
    int arr[m][3] = { 1000, 1030, 1,
                      1010, 1020, 1,
                      1025, 1040, 1,
                      1130, 1145, 2,
                      1130, 1140, 2 };
    cout << "Maximum Stopped Trains = "
         << maxStop(arr);
    return 0;
}