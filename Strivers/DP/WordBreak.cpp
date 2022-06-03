bool isPresent(string s,vector<string> &B){
        for(string word : B){
            if(word==s){
                return true;
            }
        }
        return false;
    }

    int wordBreak(string A, vector<string> &B) {
        //code here
        if(A.length()==0)
         return 1;
        for(int i=1;i<=A.length();i++){
            if(isPresent(A.substr(0,i),B) && wordBreak(A.substr(i),B)){
                return 1;
            }
        }
        return 0;
    }