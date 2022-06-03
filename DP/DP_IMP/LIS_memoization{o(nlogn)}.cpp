#include <bits/stdc++.h>
using namespace std;

int LIS(int arr[],int n)
{
    int lis[n]={1};
    int sub[n];
    sub[0]=-1;
    vector<int> ans;
     int i,j,max=0,loc;
    for(i=1;i<n;i++)                  // setting up the length of LIS
      {
          for(j=0;j<i;j++)
           {
               if(arr[i]>arr[j] && lis[i]<lis[j]+1)
               {
                lis[i]=lis[j]+1;
                sub[i]=j;
               }
           }
      }
    for(i=0;i<n;i++)    length of LIS
     {
         if(max<=lis[i])
         {
            max=lis[i]; 
            loc=i;
         }
     }
    i=loc;
    while(i>=0)
     {
        ans.push_back(i);
        i=sub[i];
     }
    for(i=ans.size()-1;i>=0;i--)  //longest increasing subsequence 
      cout<<arr[ans[i]]<<" ";
    cout<<endl;   
    return max;
}

int main() {
	// your code goes here
	int arr[]={ 10, 22, 9, 33, 21, 50, 41, 60 };
	int n;
	cout<<LIS(arr,8)<<endl;
}
