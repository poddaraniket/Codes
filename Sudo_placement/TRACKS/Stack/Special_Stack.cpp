#include<iostream>
#include<stack>
using namespace std;
void push(int a);
bool isFull(int n);
bool isEmpty();
int pop();
int getMin();
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty()){
		    pop();
		}
		while(!isFull(n)){
			cin>>a;
			push(a);
		}
		cout<<getMin()<<endl;
	}
}// } Driver Code Ends


/*Complete the function(s) below*/
void push(int a)
{
     //add code here.
     s.push(a);
}

bool isFull(int n)
{
     //add code here.
     if(s.size()==n)
      return true;
}

bool isEmpty()
{
    //add code here.
    if(s.size()==0)
     return true;
}

int pop()
{
    //add code here.
    s.pop();
}

int getMin()
{
   //add code here.
   int mini=1000000;
   while(!isEmpty())
    {
        mini=min(mini,s.top());
        s.pop();
    }
   return mini;    
}