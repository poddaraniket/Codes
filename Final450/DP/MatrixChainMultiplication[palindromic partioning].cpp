//O(N^3)
import java.io.*;
import java.util.*;

public class Main {

	public static int mcm(int[] arr){
        int n=arr.length-1;
        int [][]dp=new int[n][n];
        
        for(int gap=0;gap<n;gap++)
         {
            for(int i=0,j=gap;j<n;i++,j++)
             {
                if(gap==0) dp[i][j]=0;
                else if(gap==1) dp[i][j]=arr[i]*arr[j]*arr[j+1];
                else{
                    int min=Integer.MAX_VALUE;
                    for(int k=i;k<j;k++)
                     {
                        min=Math.min(min,dp[i][k]+dp[k+1][j]+arr[i]*arr[k+1]*arr[j+1]);
                     }
                    dp[i][j]=min; 
                }
             }
         }
        // for( int i=0 ; i<n ; i++){
        //     for( int j=0 ; j<n ; j++){
        //         System.out.print( dp[i][j] +"  " );
        //     }
        //     System.out.println();
        // } 
		return dp[0][n-1];
	}
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int[] arr = new int[n];
		for(int i = 0 ; i < n; i++){
			arr[i] = scn.nextInt();
		}
		System.out.println(mcm(arr));
	}

	
}