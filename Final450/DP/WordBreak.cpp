bool dict(string s,vector<string> &B){
    for(int i=0;i<B.size();i++){
        if(s==B[i])
         return true;
    }
    return false;
}

int wordBreak(string A, vector<string> &B) {
    //code here
    if(A.length()==0)
      return 1;
    for(int i=1;i<=A.length();i++){
        if(dict(A.substr(0,i),B) && wordBreak(A.substr(i,A.length()),B)){
            return 1;
        }
    }
    return 0;
}