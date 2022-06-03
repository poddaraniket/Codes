vector<int> find(int a[], int n , int x )
{
    // code here
    int first=0,last=n-1;
    vector<int> v(2,-1);
    while(first<=last)
    {
        int mid=(first+last)/2;
        //cout<<mid<<endl;
        if((mid==0 || a[mid-1]<x) && a[mid]==x){
            v[0]=mid;
            break;
         }
        else if(a[mid]<x){
            first=mid+1;
            //cout<<"*"<<endl;
        }
         
        else
         {
            last=mid-1;
         }
    }
    //cout<<lo
    first=0,last=n-1;
    while(first<=last)
    {
        int mid=(first+last)/2;
       // cout<<mid<<endl;
        if((mid==n-1 || a[mid+1]>x) && a[mid]==x){
            v[1]=mid;
            break;
         }
        else if(a[mid]>x)
         last=mid-1;
        else
         {
            first=mid+1;
         }
    }
    return v;
}