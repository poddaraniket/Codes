#include <bits/stdc++.h>
using namespace std;

int arr[9]={10,16,8,12,15,6,3,9,5};

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  

int Partition(int l,int h)
{
   // cout<<l<<" "<<h<<endl;
    int i=l,j=h;
    int pivot=arr[l];
    //cout<<pivot<<endl;
    while(i<=j)
     {
         //cout<<i<<" "<<j<<endl;
        if(arr[i]>pivot && arr[j]<pivot)
         {
            swap(&arr[i],&arr[j]);
            i++;
            j--;
            continue;
         }
        if(arr[i]<=pivot)
         i++;
        if(arr[j]>pivot)
         j--;
     }
    swap(&arr[l],&arr[j]);
    return j;
}

void QuickSort(int l,int h){
    //cout<<"*"<<endl;
   if(l<h)
    {
       int j=Partition(l,h);
    //   for(int i=0;i<9;i++)
	   //  cout<<arr[i]<<" ";
	   // cout<<endl; 
       //cout<<"p"<<j<<endl;
       QuickSort(l,j);
       QuickSort(j+1,h);
    }
}

int main() {
	// your code goes here
	QuickSort(0,8);
	for(int i=0;i<9;i++)
	 cout<<arr[i]<<" ";
	cout<<endl; 
	return 0;
}
