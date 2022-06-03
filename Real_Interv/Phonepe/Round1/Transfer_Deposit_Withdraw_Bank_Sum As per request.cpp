vector<int> f(vector<int> balances, vector<string> requests) {
    for(int i = 0;i<requests.size();i++) {
        if(requests[i][0] == 'w') {
            int j = 9,ind = 0, num = 0;
            while(j < requests[i].length() and requests[i][j] != ' '){
                ind = ind * 10 + (requests[i][j] - '0');
                j ++;
            }j++;
            while(j < requests[i].length() and requests[i][j] != ' '){
                num = num * 10 + (requests[i][j] - '0');
                j ++;
            }      
            ind --;      
            if(ind < balances.size() and num <= balances[ind]) {
                balances[ind] -= num;
            }
            else
                return {-(i+1)};
        }
        else if(requests[i][0] == 'd') {
            int j = 8,ind = 0, num = 0;
            while(j < requests[i].length() and requests[i][j] != ' '){
                ind = ind * 10 + (requests[i][j] - '0');
                j ++;
            }j++;
            while(j < requests[i].length() and requests[i][j] != ' '){
                num = num * 10 + (requests[i][j] - '0');
                j ++;
            }    
            ind --;      
            if(ind < balances.size()) {
                balances[ind] += num;
            }
            else
                return {-(i+1)};
        }
        else {
            int j = 9,from = 0,to = 0, num = 0;
            while(j < requests[i].length() and requests[i][j] != ' '){
                from = from * 10 + (requests[i][j] - '0');
                j ++;
            }j++;
            while(j < requests[i].length() and requests[i][j] != ' '){
                to = to * 10 + (requests[i][j] - '0');
                j ++;
            }j++; 
            while(j < requests[i].length() and requests[i][j] != ' '){
                num = num * 10 + (requests[i][j] - '0');
                j ++;
            }       
            from --, to --;   
            if(from < balances.size() and to < balances.size() and num <= balances[from]) {
                balances[to] += num;
                balances[from] -= num;
            }
            else
                return {-(i+1)};            
        }
    }
    return balances;
} 