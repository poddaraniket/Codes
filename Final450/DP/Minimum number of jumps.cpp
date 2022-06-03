int minJumps(int arr[], int n){
        // Your code here
        int maxR=arr[0];
        int steps=arr[0];
        int jump=1;
        if(n==1)
         return 1;
        if(arr[0]==0)
         return -1;
        for(int i=1;i<n;i++)
         {
             if(i==n-1)
              return jump;
              // updatig the max possible reach 
             maxR=max(maxR,arr[i]+i);
             // maxR tak pahuchtey pahuctey steps -- kartey raho
             steps--;
             if(steps==0)
              {
                  // jaise steps 0 hua iska matlab wha sai jump marna hai
                  kaha tak wo maxR decide karta hai
                  jump++;
                  // agar maxR i sai bara hai iska matlab i kabhi wha nhi pahuh sakta 
                  if(i>maxR)
                   return -1;
                  // agar chota hai to humey maxR-i steps chaiye ab wha tak pahuchney kai liye 
                  steps=maxR-i; 
              }
         }
        return jump; 
    }