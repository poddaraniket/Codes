int tour(petrolPump p[],int n)
    {
       //Your code here
       int balance=0,deficit=0,start=0;
       for(int rear=0;rear<n;rear++){
           balance+=p[rear].petrol-p[rear].distance;
           if(balance<0){
               // itni to deficit hai yaha tak
               deficit+=balance;
               start=rear+1;
               // naya start kar rha hu
               balance=0;
           }
       }
       if(balance+deficit>=0){
           return start;
       }
       return -1;
    }