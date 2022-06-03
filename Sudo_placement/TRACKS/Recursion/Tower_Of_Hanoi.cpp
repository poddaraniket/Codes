#include <bits/stdc++.h>

using namespace std;

void toh(int n, int from, int to, int aux, long long &moves);

int main() {

    int T;
    cin >> T;
    while (T--) {
        long long moves = 0;
        int N;
        cin >> N;
        toh(N, 1, 3, 2, moves);
        cout << moves << endl;
    }
    return 0;
}
// } Driver Code Ends


// You need to complete this function

// avoid space at the starting of the string in "move disk....."
void toh(int n, int from, int to, int aux, long long &moves) {
    // Your code here
    ++moves;
    if(n==1)
    {
     cout<<"move disk 1 from rod "<<from<<" to rod "<<to<<endl;
     //cout<<moves<<endl;
     return;
    }
    toh(n-1,from,aux,to,moves);
    cout<<"move disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
    toh(n-1,aux,to,from,moves);
}


/*
 long long toh(int N, int from, int to, int aux) {
        // Your code here
    if(N==0)
     return 0;
    //using instruction it will move teh first n-1 disk from "from" to "aux" using "to" 
    long long left=toh(N-1,from,aux,to);
    // print the disk from "from" to "to"
    cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
    // using instruction it will move the remaining n-1 disk from "aux" to "to" using "from"
    long long right=toh(N-1,aux,to,from);
    return left+right+1;
}
*/