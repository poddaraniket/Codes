import java.io.*;
import java.util.*;

public class Main {
    
    public static int getScore(String w,int[] score,int[] farr){
        int sc=0;
        boolean flag=true;
        for(int i=0;i<w.length();i++){
            char ch=w.charAt(i);
            farr[ch-'a']--;
            if(farr[ch-'a']>=0){
                sc+=score[ch-'a'];
            }else{
                flag=false;
            }
        }
        if(!flag){
            return -1;
        }
        return sc;
    }
    
    public static void removeW(int[] farr,String w){
        for(int i=0;i<w.length();i++){
            char ch=w.charAt(i);
            farr[ch-'a']++;
        }
    }
    
	public static int solution(String[] words, int[] farr, int[] score, int idx) {
		//write your code here
		if(idx==words.length){
	        return 0;
    	}
    	int exclude=solution(words,farr,score,idx+1);
    	int sc=0;
    	String w=words[idx];
    	sc=getScore(words[idx],score,farr);
    	int include=0;
    	if(sc>=0)
    	  include=sc + solution(words,farr,score,idx+1);
    	removeW(farr,words[idx]);
    	return Math.max(include,exclude);
	}

	public static void main(String[] args) {

		Scanner scn = new Scanner(System.in);
		int nofWords = scn.nextInt();
		String[] words = new String[nofWords];
		for(int i = 0 ; i < words.length; i++) {
			words[i] = scn.next();
		}
		int nofLetters = scn.nextInt();
		char[] letters = new char[nofLetters];
		for (int i = 0; i < letters.length; i++) {
			letters[i] = scn.next().charAt(0);
		}
		int[] score = new int[26];
		for (int i = 0; i < score.length; i++) {
			score[i] = scn.nextInt();
		}
		if (words == null || words.length == 0 || letters == null || letters.length == 0 || score == null
				|| score.length == 0) {
			System.out.println(0);
			return;
		}
		int[] farr = new int[score.length];
		for (char ch : letters) {
			farr[ch - 'a']++;
		}
		System.out.println(solution(words, farr, score, 0));

	}
}