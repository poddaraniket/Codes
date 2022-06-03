// for precision
double actualSol(int tempSol,int pre,int x){
    int factor=1;
    double ans=tempSol;
    for(int i=0;i<pre;i++)
    {
        factor=factor/10;
        for(double t=ans;t*t<x;t+=factor){
           ans=t;
        }
    }
    return ans;
}



int sqrtInteger(int x) {
        int s=0,e=x;
        long long int best=-1;
        while(s<=e){
            long long int m=(s+e)/2;
            long long int sqredVal=m*m;
            if(sqredVal>x)
               e=m-1;
            else{
              best=m;  // bcoz mid can be a possible solution
              s=m+1;
            }
        }
        return best;
    }

 int main(){
    int tempSol=sqrtInteger(x);
    cout<<actualSol(tempSol,precision,x);
 }   