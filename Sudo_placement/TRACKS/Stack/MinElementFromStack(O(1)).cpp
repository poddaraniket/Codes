class MinStack {
public:
    stack<long long int> s;
    long long int minElement,topElement;
    MinStack() {
        s=stack<long long int> () ;
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            minElement=val;
        }else{
            if(minElement>val){
                long long int valueInserted=(long long int)val*2-minElement; // making smaller element more smaller
                minElement=val;
                s.push(valueInserted);
            }else{
                s.push(val);
            }
        }
        // top();
    }
    
    void pop() {
        if(!s.empty()){
            topElement=s.top();
            if(topElement<minElement){
                minElement=2*minElement-topElement;
            }
            s.pop();
        }
       // if(!s.empty())
         // top();
    }
    
    int top() {
        topElement=s.top();
        if(topElement<minElement){
            topElement=minElement;
        }
        return topElement;
    }
    
    int getMin() {
        return minElement;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */