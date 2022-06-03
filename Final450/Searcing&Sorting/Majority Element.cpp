{
        
        // your code here
    int majority,count=0;
    majority=a[0];
    count++;
    for(int i=1;i<size;i++)
    {
        if(a[i]!=majority)
         count--;
        else
         count++;
        if(count==0){
            majority=a[i];
            count++;
        } 
    }
    int val=0;
    //cout<<majority<<" "<<count<<endl;
    for(int i=0;i<size;i++)
     {
         if(a[i]==majority)
          val++;
     }
    if(val>(size/2))
     return majority;
    return -1;
    }
