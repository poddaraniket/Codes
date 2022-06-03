void StackQueue :: push(int x)
{
    // Your Code
    s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
        // Your Code 
        int t=-1;
        while(s1.size()>1){
            s2.push(s1.top());
            s1.pop();
        }
        if(s1.size()==1){
           t=s1.top();
           s1.pop(); 
        }
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return t;
}