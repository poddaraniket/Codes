#include <bits/stdc++.h>
using namespace std;

class FindMedian
{
	public:
		void insertHeap(int &);
		double getMedian();
	private:
		double median; //Stores current median
		priority_queue<int> max; //Max heap for lower values
		priority_queue<int, vector<int>, greater<int> > min; //Min heap for greater values
		void balanceHeaps(); //Method used by insertHeap
};


 // } Driver Code Ends

int num=0;
// Function to insert heap
void FindMedian::insertHeap(int &x)
{
    num++;
	// Your code here
	if(max.size()==0)
	 {
	     max.push(x);
	     getMedian();
	 }
	else
	 {
	     if(x<=max.top())
	      max.push(x);
	     else
	      min.push(x);
	     balanceHeaps();
	     getMedian(); 
	 }
}

// Function to balance heaps
void FindMedian::balanceHeaps()
{
	// Your code here
	if(min.size()>max.size())
	 {
	     max.push(min.top());
	     min.pop();
	 }
	else
	 {
	     if(max.size()-min.size()==2)
	      {
	          min.push(max.top());
	          max.pop();
	      }
	 }
}

// Function to return getMedian
double FindMedian::getMedian()
{
	// Your code here
	if(num%2==0)
	 return((max.top()+min.top())/2);
	else
	 return max.top();
}


// { Driver Code Starts.

int main()
{
    int n, x;
	FindMedian Ans;
	cin >> n;
	for(int i = 1;i<= n; ++i)
	{
		cin >> x;
		Ans.insertHeap(x);
	    cout << floor(Ans.getMedian()) << endl;
	}
	// }
	return 0;
}  // } Driver Code Ends