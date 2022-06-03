//O(2^N)
void tohUtil(int N, int from, int to, int aux,long long &steps)
    {
        if(N==0)
         return;
        // faith that first n-1 disks are put in "aux" from "from" using "to"
        tohUtil(N-1,from,aux,to,steps);
        // now we have the nth disk put that in "to" from "from" 
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        steps++;
        // faith that remanining n-1 disks are put present in "aux" to "to" using "from" disk
        tohUtil(N-1,aux,to,from,steps);
    }
    
    long long toh(int N, int from, int to, int aux) {
        //Your code here
        long long steps=0;
        tohUtil(N,from,to,aux,steps);
        return steps;
    }