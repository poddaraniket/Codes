void insert(stack<int> &s,int temp){
    // Keep removing element till u get its place then push it
    if(s.empty() || s.top()<=temp)
     {
        s.push(temp);
        return;
     }
    int x=s.top();
    s.pop();
    insert(s,temp);
    s.push(x);
    return;
}

void sort_util(stack<int> &s){
    // Last element is always sorted
    if(s.size()==1)
     return;
    // Remove Last element an sort the rest
    int temp=s.top();
    s.pop();
    sort_util(s);
    // Add the last element to proper location in the sotred array
    insert(s,temp);
    return;
}

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   //Your code here
   
   sort_util(s);
   
}