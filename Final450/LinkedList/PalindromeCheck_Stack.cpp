bool isPalindrome(Node *head)
    {
       stack<int> s;
       int len=0;
       Node *temp=head;
       while(temp){
           s.push(temp->data);
           temp=temp->next;
           len++;
       }
       int count=len/2;
       temp=head;
       while(count){
           if(s.top()!=temp->data || s.empty())
            return false;
           s.pop();
           temp=temp->next;
           count--;
       }
       return true;
    }