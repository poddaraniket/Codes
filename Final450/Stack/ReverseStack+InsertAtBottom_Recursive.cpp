#include <iostream>
using namespace std;

stack<char> s;
string ns;

void insert_at_bottom(char x){
    if(s.size()==0)
     s.push(x);
    else{
        //empty the array first recursilvely and place the element at bottom and then push the rest
        char a=s.top();
        s.pop();
        insert_at_bottom(x);
        s.push(a);
    } 
}

void reverse(){
    if(s.size()>0){
        
        // Pick the top and then apply reverse on rest 
        char top=s.top();
        s.pop();
        reverse();
        
        //At the end place the top one at the bottom
        insert_at_bottom(top);
    }
}

int main() {
	// your code goes here
	st.push('1');
    st.push('2');
    st.push('3');
    st.push('4');
      
    cout<<"Original Stack"<<endl;
      
    // print the elements 
    // of original stack
    cout<<"1"<<" "<<"2"<<" "
        <<"3"<<" "<<"4"
        <<endl;
      
    // function to reverse 
    // the stack
    reverse();
    cout<<"Reversed Stack"
        <<endl;
      
    // storing values of reversed 
    // stack into a string for display
    while(!st.empty())
    {
        char p=st.top();
        st.pop();
        ns+=p;
    }
      
    //display of reversed stack
    cout<<ns[3]<<" "<<ns[2]<<" "
        <<ns[1]<<" "<<ns[0]<<endl;
    return 0;
}
	return 0;
}
