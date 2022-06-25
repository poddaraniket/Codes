/*



                                  \
                         edge pre  \
                     (node pre)     1

If recursion is in loop :

         //preNode
         loop{
            //preEdge
           fn()
            //postedge
         }
         //postNode
 
*/



import java.io.*;
import java.util.*;

public class Main {
  static int counter = 1;

  public static void solution(int i, int n, boolean[] used, String asf) {
    // write your code here
    if(i>n){
        System.out.println(counter+"."+asf);
        counter++;
        return;
    }
    if(used[i]==true){
        solution(i+1,n,used,asf);
    }
    else{
        used[i]=true;
        //akela  //node pre
        solution(i+1,n,used,asf+"("+i+") ");  
        for(int j=i+1;j<=n;j++){
            // edge pre
           if(used[j]==true)
             continue;
           used[j]=true;
           //dukela
           solution(i+1,n,used,asf + "(" + i + "," + j + ") ");
           //edge post
           used[j]=false;
        }
        //node post
        used[i]=false;
    }
  }

  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    boolean[] used = new boolean[n + 1];
    solution(1, n, used, "");
  }
}
 