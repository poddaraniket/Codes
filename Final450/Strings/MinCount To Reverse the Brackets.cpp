int countRev (string s)
{
    // your code here
    if(s.length()%2!=0)
     return -1;
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='{' || st.empty())
         st.push(s[i]);
        else{
            if(st.top()=='{')
              st.pop();
            else
              st.push(s[i]);
        } 
    }
    //cout<<st.size()<<endl;
    double openB=0,closeB=0;
    while(!st.empty()){
        if(st.top()=='{')
         openB++;
        else
         closeB++;
        st.pop(); 
    }
    return ceil(openB/2.0)+ceil(closeB/2.0);