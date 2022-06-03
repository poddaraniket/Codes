#include <bits/stdc++.h>
using namespace std;

bool isValid(long long int arr[],long long int mid,int chef,int paratha)
{
    int totalParatha=0,sum=0;
    for(int i=0;i<chef;i++)
     {
        int temp=arr[i];
        int p=1,count=0;
        while(temp<=mid)
         {
            count++;
            p++;
            temp+=(arr[i]*p);
         }
        totalParatha+=count;
        if(totalParatha>=paratha)
         return true;
     }
    return false; 
}

long long int findTime(long long int arr[],long long int start,long long int end,int chef,int paratha)
{
    long long int best=0;
    while(start<=end)
    {
        long long int mid=(start+end)/2;
        if(isValid(arr,mid,chef,paratha)){
            best=mid;
            end=mid-1;
        }
        else
         {
            start=mid+1; 
         }
    }
    return best;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int paratha;
        cin>>paratha;
        int chef;
        cin>>chef;
        long long int arr[chef];
        long long int start=0,end,maxi=0;
        for(int i=0;i<chef;i++)
         {
            cin>>arr[i]; 
            maxi=max(maxi,arr[i]);
         }
        end=maxi*((paratha*(paratha+1))/2);
      //  cout<<"*"<<end<<endl;
        cout<<findTime(arr,start,end,chef,paratha)<<endl;
    }
	return 0;
}
