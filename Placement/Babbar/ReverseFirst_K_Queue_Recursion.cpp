void reverseQueue(queue<int> &q,int k){
    if(k==0)
     return;
    int temp=q.front();
    //cout<<temp<<endl;
    q.pop();
   // k--;
    reverseQueue(q,k-1);
    q.push(temp);
}

queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    reverseQueue(q,k);
    int t=q.size()-k;
    //cout<<""<<t<<endl;
    while(t--){
        int val=q.front();
        //cout<<val<<endl;
        q.pop();
        q.push(val);
    }
    return q;    
}