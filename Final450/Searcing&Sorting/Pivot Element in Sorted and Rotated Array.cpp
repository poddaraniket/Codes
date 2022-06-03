#include<bits/stdc++.h>
using namespace std;

int binarySearch(int a[],int low,int high){
    int temp;
    int mid;
    while(low<=high)
     {
        int mid=(low+high)/2;
        if(a[mid]>a[low])
         {
            low=mid; 
         }
        else if(a[mid]<a[high])
         {
            high=mid-1; 
         }
        else
         {
            if(a[mid]>a[mid+1]){
             temp=mid;
             break;
            }
         }
     }
    return temp; 
}

int main()
{
    int arr[]={8,1,4,5,6,7};
    int pivot=binarySearch(arr,0,5);
    cout<<pivot<<endl;
}