#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[],int l,int h){
   // cout<<"*"<<endl;
    int temp=arr[h];
    for(int i=h-1;i>=l;i--){
        arr[i+1]=arr[i];
    }
    arr[l]=temp;
    // for(int i=l;i<=h;i++){
    //     cout<<arr[i]<<endl;
    // }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int wrongIndex=-1;
    for(int i=0;i<n;i++)
    {
        //cout<<wrongIndex<<endl;
        // if wrongIndex is found 
        if(wrongIndex!=-1)
        {
            //cout<<"%"<<endl;
            //looking for the oppsite sign for rotation
            if((arr[wrongIndex]<0 && arr[i]>=0) || (arr[wrongIndex]>=0 && arr[i]<0)){
               // cout<<"&"<<endl;
                rotate(arr,wrongIndex,i);
                // if distance between wrongIndex and opposite val is > 2 it means there are more wring indexed val in between so go to it
                if(i-wrongIndex>=2){
                  wrongIndex+=2;
                } 
                else{
                  wrongIndex=-1; // if it was adjacent 
                }
            }
        }
        // look for wrongIndex
        else{
            if((arr[i]<0 && i%2!=0) ||(arr[i]>0 && i%2==0)){
                 wrongIndex=i;
                 //cout<<"*"<<wrongIndex<<endl;
            }
             
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
	return 0;
}
