#include <bits/stdc++.h>
using namespace std;

void combination(int n,int elmnt,vector<int> &arr)
{
   if(elmnt>n)
    {
        for(int i=0;i<2*n;i++)
         cout<<arr[i]<<" ";
        cout<<endl;
        return;
    }
   for(int i=0;i<2*n;i++)
   {
       if(arr[i]==-1 && (i+elmnt+1)<2*n && arr[i+elmnt+1]==-1)
        {
            arr[i]=elmnt;
            arr[i+elmnt+1]=elmnt;
            combination(n,elmnt+1,arr);
            arr[i]=-1;
            arr[elmnt+i+1]=-1;
        }
   }
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<int> arr(2*n,-1);
	//memset(arr,-1,sizeof(arr));
	combination(n,1,arr);
	return 0;
}
