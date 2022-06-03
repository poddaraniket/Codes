#include<bits/stdc++.h>
using namespace std;


int maxArea(vector<int>& height)
{
    int l=0,r=height.size()-1,area=0;
    while(l<r)
     {
        area=max(area,min(height[l],height[r])*(r-l));
        if(height[l]<height[r])
          l++;
        else
          r--;
     }
   return area;
} 

int main()
{
	int n;
	cin>>n;
	vector<int> height(n);
	for(int i=0;i<n;i++)
	 {
	 	cin>>height;
	 }
	cout<<maxArea(height)<<endl; 
}