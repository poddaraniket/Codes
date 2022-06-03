#include <bits/stdc++.h>
using namespace std;

int getMedian(int a1[],int a2[],int small,int big)
{
    int start=0,end=small;
    while(start<=end){
        int partitionX=(end+start)/2;
        int partitionY=(small+big+1)/2-partitionX;
        
        //if partitionX is 0 it means nothing is there on left side. Use -INF for maxLeftX
        //if partitionX is length of input then there is nothing on right side. Use +INF for minRightX
        int maxLeftX=(partitionX==0)?INT_MIN:a1[partitionX-1];
        int minRightX=(partitionX==small)?INT_MAX:a1[partitionX];

        int maxLeftY=(partitionY==0)?INT_MIN:a2[partitionY-1];
        int minRightY=(partitionY==big)?INT_MAX:a2[partitionY];
        cout<<maxLeftX<<" "<<minRightX<<"*"<<maxLeftY<<" "<<minRightY<<endl;
        if(maxLeftX<=minRightY && maxLeftY<=minRightX){ 
                //We have partitioned array at correct place
                // Now get max of left elements and min of right elements to get the median in case of even length combined array size
                // or get max of left for odd length combined array size.
             cout<<maxLeftX<<" "<<minRightX<<"*"<<maxLeftY<<" "<<minRightY<<endl;
            if((small+big)%2!=0)
              return max(maxLeftX,maxLeftY);
            return (max(maxLeftX,maxLeftY) + min(minRightX,minRightY))/2;
        }
        else if(maxLeftX>minRightY)
         {
           //we are too far on right side for partitionX. Go on left side.
            end=partitionX-1; 
         }
        else
         {
            //we are too far on left side for partitionX. Go on right side.
            start=partitionX+1; 
         }
    }
}

int main() {
	int n,m;
	cin>>n>>m;
	int a1[n],a2[m];
	for(int i=0;i<n;i++)
      cin>>a1[i];
    //cout<<endl;
    for(int i=0;i<m;i++)
      cin>>a2[i];
    if(n<m)  
	 cout<<getMedian(a1,a2,n,m);
	else
	 cout<<getMedian(a2,a1,m,n);  
	return 0;
}
