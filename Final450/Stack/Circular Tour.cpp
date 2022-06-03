int tour(petrolPump p[],int n)
    {
       //Your code here
       int start=0,capacity=0,deficiency=0;
       for(int i=0;i<n;i++)
       {
           capacity+=p[i].petrol-p[i].distance;
           if(capacity<0)
            {
                start=i+1;
                deficiency+=capacity;
                capacity=0;
            }
       }
       if(capacity+deficiency>0)
        return start;
       return -1;    
    }