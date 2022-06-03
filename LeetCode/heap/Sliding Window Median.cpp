#include <bits/stdc++.h>
using namespace std;

multiset<int> mini;
multiset<int,greater<int>> maxi; 
multiset<int> :: iterator it;
multiset<int,greater<int>> :: iterator it1;

void del(int num)
{
    if(mini.find(num)!=mini.end())
      mini.erase(mini.find(num));
    else if(maxi.find(num)!=maxi.end())
      maxi.erase(maxi.find(num));  
}

double findMedian()
{
    it=mini.begin();
    it1=maxi.begin();
    cout<<*it<<" "<<*it1<<endl;
    if(mini.size()==maxi.size())
     return ((double)(*it)+(double)(*it1))/2.0;
    else
     return (double)*it;
}

void addNum(int num)
{
       if(mini.empty())
             mini.insert(num);
         else
          {
             it=mini.begin();
             if(*it>num)
                 maxi.insert(num);
             else
                 mini.insert(num);
          }
         if(mini.size()>maxi.size() && mini.size()-maxi.size()>1)
          {
             it=mini.begin();
             int u=*it;
             mini.erase(mini.begin());
             maxi.insert(u);
          }
         else if(maxi.size()>mini.size())
         {
             it1=maxi.begin();
             int u=*it1;
             maxi.erase(maxi.begin());
             mini.insert(u); 
         } 
}
    
vector<double> medianSlidingWindow(vector<int>& nums, int k) 
{ 
     vector<double> v;    
     for(int i=0;i<k;i++)
      {
         addNum(nums[i]);
      }
     v.push_back(findMedian());   
        
        
     for(int i=k;i<nums.size();i++)
      {
         del(nums[i-k]); 
         addNum(nums[i]);
         v.push_back(findMedian());
      }
     return v;   
    }


int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<int> nums;
	for(int i=0;i<n;i++)
	  {
	      int a;
	      cin>>a;
	      nums.push_back(a);
	  }
	int k;
	cin>>k;
	vector<double> result=medianSlidingWindow(nums,k);  
	for(int i=0;i<result.size();i++)
       cout<<result[i]<<" ";
    cout<<endl;   
	return 0;
}
