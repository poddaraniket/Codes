int value(char r){
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;

    return -1;
}

int romanToDecimal(string &str) {
    int ans=value(str[0]);
    for(int i=1;i<str.length();i++){
        // if(val[str[i]-t]>val[str[i-1]-t])
        int a=value(str[i-1]);
        int b=value(str[i]);
        if(a<b)
        {
            ans-=a;
            ans+=(b-a);
        }
        else{
            ans+=b;
        }
    }
    return ans;
}