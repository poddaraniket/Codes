//Solve one at a time

import java.io.*;
import java.util.*;

public class Main {

  public static void solution(char[][] arr, String[] words, int vidx) {
    //write your code here
    
    if(vidx==words.length){
        print(arr);
        return;
    }
    
    String word=words[vidx];
    for(int i=0;i<arr.length;i++){
        for(int j=0;j<arr[0].length;j++){
            if(arr[i][j]=='-' || arr[i][j]==word.charAt(0)){
                if(canPlaceHorizantally(arr,word,i,j)){
                    boolean[] wePlaced=placeHorizantally(arr,word,i,j);
                    solution(arr,words,vidx+1);
                    unPlaceHorizantally(arr,wePlaced,i,j);
                }
            }
            
            if(arr[i][j]=='-' || arr[i][j]==word.charAt(0)){
                if(canPlaceVertically(arr,word,i,j)){
                    boolean[] wePlaced=placeVertically(arr,word,i,j);
                    solution(arr,words,vidx+1);
                    unPlaceVertically(arr,wePlaced,i,j);
                }
            }
            
        }
    }

  }
  
  public static boolean canPlaceHorizantally(char[][] arr,String word,int i,int j){
      if(j-1>=0 && arr[i][j-1]!='+'){
          return false;
      }else if(j+word.length()<arr[0].length && arr[i][j+word.length()]!='+'){
          return false;
      }
      
      for(int k=0;k<word.length();k++){
           if(k+j>=arr[0].length)
             return false;
           if(arr[i][k+j]=='-' || arr[i][k+j]==word.charAt(k)){
               continue;
           }else{
               return false;
           }     
      }
    return true;  

  }
  
  public static boolean[] placeHorizantally(char[][] arr,String word,int i,int j){
      boolean[] wePlaced=new boolean[word.length()];
      for(int k=0;k<word.length();k++){
          if(arr[i][k+j]=='-'){
            arr[i][k+j]=word.charAt(k);
            wePlaced[k]=true;
          }
      }
      return wePlaced;
  }
  
  
  public static void unPlaceHorizantally(char[][] arr,boolean[] wePlaced,int i,int j){
      for(int k=0;k<wePlaced.length;k++){
          if(wePlaced[k]==true){
              arr[i][k+j]='-';
          }
      }
  }
  
  public static boolean canPlaceVertically(char[][] arr,String word,int i,int j){
      if(i-1>=0 && arr[i-1][j]!='+'){
          return false;
      }else if(i+word.length()<arr.length && arr[i+word.length()][j]!='+'){
          return false;
      }
      
      for(int k=0;k<word.length();k++){
           if(k+i>=arr.length)
             return false;
           if(arr[k+i][j]=='-' || arr[k+i][j]==word.charAt(k)){
               continue;
           }else{
               return false;
           }     
      }
    return true;  

  }
  
   public static boolean[] placeVertically(char[][] arr,String word,int i,int j){
      boolean[] wePlaced=new boolean[word.length()];
      for(int k=0;k<word.length();k++){
          if(arr[k+i][j]=='-'){
            arr[k+i][j]=word.charAt(k);
            wePlaced[k]=true;
          }
      }
      return wePlaced;
  }
  
  public static void unPlaceVertically(char[][] arr,boolean[] wePlaced,int i,int j){
      for(int k=0;k<wePlaced.length;k++){
          if(wePlaced[k]==true){
              arr[k+i][j]='-';
          }
      }
  }

  public static void print(char[][] arr) {
    for (int i = 0 ; i < arr.length; i++) {
      for (int j = 0 ; j < arr.length; j++) {
        System.out.print(arr[i][j]);
      }
      System.out.println();
    }

  }
  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    char[][] arr = new char[10][10];
    for (int i = 0 ; i < arr.length; i++) {
      String str = scn.next();
      arr[i] = str.toCharArray();
    }
    int n = scn.nextInt();
    String[] words = new String[n];
    for (int i = 0 ; i  < words.length; i++) {
      words[i] = scn.next();
    }
    solution(arr, words, 0);
  }
}