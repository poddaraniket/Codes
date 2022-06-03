priority_queue<int> right;
    priority_queue<int,vector<int>,greater<int>> left;
    void insertHeap(int &x)
    {
        if(left.empty())
         left.push(x);
        else
         {
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
        if(left.size()-right.size()==2)
         {
             right.push(left.top());
             left.pop();
         }
        else if(right.size()>left.size())
         {
            left.push(right.top());
            right.pop();
         }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(left.size()==right.size())
         return (left.top()+right.top())/2;
        return left.top(); 
    }