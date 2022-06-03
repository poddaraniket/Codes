int num=0;
    priority_queue<int> right;
    priority_queue<int,vector<int>,greater<int>> left;
    void insertHeap(int &x)
    {
        num++;
        if(left.empty()){
            left.push(x);
        }
        else{
            if(left.top()<x)
             left.push(x);
            else 
             right.push(x);
            balanceHeaps();     
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(left.size()-right.size()==2){
            int data=left.top();
            left.pop();
            right.push(data);
        }
        else if(right.size()>left.size())
         {
            int data=right.top();
            right.pop();
            left.push(data); 
         }
    }
    
    //Function to return Median.
    double getMedian()
    {
        //cout<<left.size()<<" "<<right.size()<<endl;
        if(num%2==0) 
         return (left.top()+right.top())/2;
        return left.top();
    }