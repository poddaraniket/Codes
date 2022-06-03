import java.io.*;
import java.util.*;

public class Main {

//Maximum Sum Of Three Non-overlapping Subarrays
// left and right sub array will be 2D bcoz one column will contain value other will be index


    public static void solution(int[] arr, int k){
        
        int n = arr.length;
        int[][] dp1  = new int[n][2]; // left
        int[][] dp2  = new int[n][2]; // right
        int[] mid = new int[n]; // mid  
        
        int sum = 0;
        
        //for left subarray
        for( int i=0 ; i<n ; i++ ){
            if( i<k ){
                sum += arr[i];
                dp1[i][0] = sum;
                dp1[i][1]=0;
            }
            else{
                sum += arr[i] - arr[i-k];
                // Make sure if sum we get is max and also from min index
                if(sum>dp1[i-1][0])
                {
                    dp1[i][0]=sum;
                    dp1[i][1]=i-k+1;
                }
                else
                 {
                    dp1[i][0]=dp1[i-1][0];
                    dp1[i][1]=dp1[i-1][1]; 
                 }
            }
        }
        
        // for right subarray
        sum = 0;
        for( int i=n-1 ; i>=0 ; i-- ){
            if( n-i <= k  ){
                sum += arr[i];
                dp2[i][0] = sum;
                dp2[i][1]=i;
            }
            else{
                sum += arr[i] - arr[i+k];
                // Make sure if sum we get is max and also from min index
                if(sum>=dp2[i+1][0]){
                    dp2[i][0]=sum;
                    dp2[i][1]=i;
                }
                else
                 {
                    dp2[i][0]=dp2[i+1][0];
                    dp2[i][1]=dp2[i+1][1]; 
                 }
            }
           
        }
           // for checkng left and right subarray
        // for(int i=0;i<n;i++)
        //  {
        //     System.out.println(dp2[i][0]+" "+dp2[i][1]); 
        //  }
        
        // mid 
        mid[0]=arr[0];
        for(int i=1;i<n;i++)
            {
                mid[i]=arr[i]+mid[i-1];
            }

        // index           0 1  2  3  4  5  6  7
        
        // Actual          1 2  1  2  6  7  5  1                    
        
        // left(dp1) ->    1 3  3  3  8  13 13 13
        //     mid         1 3  4  6  12 19 24 25         
        // right(dp2) ->  13 13 13 13 13 12 6  1    
            
        //     val=3+
            
        int ans=0,left=0,midd=0,right=0;    
        for(int i=k-1,j=i+k+1;j<=n-k;i++,j++)
         {
            // System.out.println(dp1[i]+" "+(mid[j-1]-mid[i])+" "+dp2[j]);
            int val=dp1[i][0]+(mid[j-1]-mid[i])+dp2[j][0];
            if(val>ans)
             {
                ans=val;
                left=dp1[i][1];
                midd=i+1;
                right=dp2[j][1];
             }
         }
        System.out.print(ans+" "+left+" "+midd+" "+right); 
    }
    
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] arr = new int[n];
        for(int i = 0 ; i < arr.length; i++){
            arr[i] = scn.nextInt();
        }
        int k = scn.nextInt();
        solution(arr,k);
    }

}