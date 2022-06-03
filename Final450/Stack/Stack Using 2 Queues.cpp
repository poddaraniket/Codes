void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code  
        if(q1.empty())
         return -1;
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int t=q1.front();
        q1.pop();
        queue<int>q=q1;
        q1=q2;
        q2=q;
        return t;
}
