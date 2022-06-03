#include <bits/stdc++.h>
using namespace std;

void printNSE(int arr[],int n)
{
    int temp[n];
    temp[n-1]=-1;
    stack<int> st;
    st.push(n-1);
    for(int i=n-2;i>=0;i--)
    {
        while(!st.empty()){
            if(arr[i]<arr[st.top()])
             {
                 st.pop();
             }
            else
             break;
        }
        if(st.empty())
         temp[i]=-1;
        else
         temp[i]=arr[st.top()];
    }
    for(int i=0;i<n;i++)
     {
        cout<<arr[i]<<"-->"<<temp[i]<<endl; 
     }
}


int main() {
    
    int arr[]= {11, 13, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNSE(arr, n);
    return 0;
}
