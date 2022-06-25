import java.io.*;
import java.util.*;

public class Main {
    
    
	static String max;
	public static String swap(String str,int i,int j){
	    String left=str.substring(0,i);
	    char l=str.charAt(i);
	    String mid=str.substring(i+1,j);
	    char r=str.charAt(j);
	    String right=str.substring(j+1);
	    return left+r+mid+l+right;
	}
	
	public static void findMaximum(String str, int k) {
		//write your code here

		if(Integer.parseInt(str)>Integer.parseInt(max)){
		    max=str;
		    
		}
		if(k==0){
		    
		    return;
		}
		for(int i=0;i<str.length();i++){
		    char lar=str.charAt(i);
		    int index=i;
		    for(int j=i+1;j<str.length();j++){
		        if(str.charAt(j)>=lar){
		            index=j;
		            lar=str.charAt(j);
		        }
		    }
		    if(lar>str.charAt(i)){
		        str=swap(str,i,index);
		        findMaximum(str,k-1);
		        str=swap(str,i,index);
		    }
		}
	}
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
		int k = scn.nextInt();
		 max = str;
		findMaximum(str, k);
		System.out.println(max);
	}

}