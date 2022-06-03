
priority_queue<int,vector<int>> maxheap; 
priority_queue<int, vector<int>, greater<int> > minheap;
int num=0;

void getmedian()
{
    if(num%2==0)
     {
        cout<<(maxheap.top()+minheap.top())/2<<endl; 
     }
    else
     cout<< maxheap.top()<<endl;
}


void balanceheap()
{
    if(minheap.size()>maxheap.size())
     {
        maxheap.push(minheap.top());
        minheap.pop();
     }
    else if(maxheap.size()-minheap.size()==2)
     {
        minheap.push(maxheap.top());
        maxheap.pop();
     }
}

void insertheap(int &x)
{
    num++;
    if(maxheap.size()==0)
    {
     maxheap.push(x);
     getmedian();
    }
    else
     {
         if(x<=maxheap.top())
          maxheap.push(x);
         else
          minheap.push(x);
         balanceheap(); 
         getmedian();
     }
}

int main() {
	//code
	int n,num;
	cin>>n;
	for(int i=0;i<n;i++)
	 {
	     cin>>num;
	     insertheap(num);
	 }
	return 0;
}