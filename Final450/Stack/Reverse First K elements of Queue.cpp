queue<int> modifyQueue(queue<int> q, int k)
{
    //add code here.
    stack<int> s1;
    queue<int> q1;
    while(k--)
     {
         s1.push(q.front());
         q.pop();
     }
    while(!q.empty()){
        q1.push(q.front());
        q.pop();
    } 
    while(!s1.empty()){
        q.push(s1.top());
        s1.pop();
    }
    while(!q1.empty()){
        q.push(q1.front());
        q1.pop();
    }
    return q;
}