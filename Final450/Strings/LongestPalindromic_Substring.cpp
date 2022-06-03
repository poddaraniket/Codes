//O(N^2)

string longestPalin (string S)
{
    // your code hereh;
    int l,h;
    int start=0,end=1;
    for(int i=1;i<S.length();i++){
        
        //even substring
        l=i-1;
        h=i;
        while(l>=0 && h<S.length() && S[l]==S[h])
        {
            if(h-l+1>end){
                start=l;
                end=h-l+1;
            }
            l--;
            h++;
        }
        
        //Odd Substring
        l=i-1;
        h=i+1;
        while(l>=0 && h<S.length() && S[l]==S[h])
        {
            if(h-l+1>end){
                start=l;
                end=h-l+1;
            }
            l--;
            h++;
        }
    }
    return S.substr(start,end);
}