void reverseQueue(queue<int> &q){
    //base case
    if(q.empty())
     return;
    // processing
    int temp=q.front();
    q.pop();

    //Recursion Call
    reverseQueue(q);
    //Processing
    q.push(temp);
}

queue<int> rev(queue<int> q)
{
    // add code here.
    reverseQueue(q);
    return q;
}