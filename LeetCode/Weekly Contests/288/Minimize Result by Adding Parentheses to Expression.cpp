class Solution {
public:
    
    int calc(string m1,string m2,string a1,string a2){
        int m11=(m1.length()==0) ? 1 : stoi(m1);
        int m22=(m2.length()==0) ? 1 : stoi(m2);
        return m11 * (stoi(a1)+stoi(a2)) * m22;
    }
    
    void eval(int i,int j,string s1,string s2,int &sum,string &ans){
        if(i>=s1.length() || j>=s2.length())
            return;
        int len=s2.length();
        string m1=s1.substr(0,i);
        string m2=s2.substr(len-j,j);
        string a1=s1.substr(i);
        string a2=s2.substr(0,len-j);
        // cout<<m1<<" "<<m2<<" "<<a1<<" "<<a2<<endl;
        int val=calc(m1,m2,a1,a2);
        if(val<sum){
            // cout<<val<<endl;
            // cout<<m1<<" "<<m2<<" "<<a1<<" "<<a2<<endl;
            sum=val;
            string temp="";
            temp+=m1;
            temp+='(';
            temp+=a1;
            temp+='+';
            temp+=a2;
            temp+=')';
            temp+=m2;
            ans=temp;
        }
        eval(i+1,j,s1,s2,sum,ans);
        eval(i,j+1,s1,s2,sum,ans);
    }
    
    string minimizeResult(string expression) {
        string s1="",s2="";
        int i;
        for(i=0;expression.length();i++){
            if(expression[i]=='+')
              break;
            s1+=expression[i];
        }
        s2=expression.substr(i+1);
        int sum=INT_MAX;
        string ans;
        eval(0,0,s1,s2,sum,ans);
        return ans;
    }
};