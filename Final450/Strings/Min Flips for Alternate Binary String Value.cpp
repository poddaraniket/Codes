int minFlips (string S)
{
    // your code here
    string val1="";
    string val2="";
    int b=0;
    for(int i=0;i<S.length();i++){
        val1+=char(b+'0');
        b^=1;
        val2+=char(b+'0');
    }
  //  cout<<val1<<" "<<val2<<endl;
    int count1=0,count2=0;
    for(int i=0;i<S.length();i++){
        if(val1[i]!=S[i])
         count1++;
        if(val2[i]!=S[i])
         count2++;
    }
    return min(count1,count2);
}