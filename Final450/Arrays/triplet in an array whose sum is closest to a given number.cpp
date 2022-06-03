#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> arr,int x)
{
    int n=arr.size();
    if(n<3)
     return -1;
    //int maxi=-1000000;
    int diff=10000000;
    int ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<=n-3;i++)
    {
        int val=arr[i];
        int low=i+1;
        int high=n-1;
        while(low<high)
         {
            int sum=val+arr[low]+arr[high];
            if(abs(x-sum)<diff)
             {
                diff=abs(x-sum);
                ans=sum;
             }
            else
             {
                if(x-sum>0)
                 {
                    high--; 
                 }
                else
                 {
                     low++;
                 }
             }
         }
    }
    return ans;
}

int main()
{
    vector<int> arr = { 1, 2, 3, 4, -5 };
    int x = 10;
    cout << solution(arr, x);
 
    return 0;
}