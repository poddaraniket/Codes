class Solution
{
    //Function to merge K sorted linked list.
    public class Pair implements Comparable<Pair>{
        Node n ;
        
        Pair(Node n ){
            this.n = n ;
        }
        public int compareTo(Pair o ){
            return this.n.data - o.n.data;
        }
    }
    Node mergeKList(Node[]arr,int K)
    {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        Node ans = null;
        Node head=ans;
        for(int i =0 ; i<K ; i++){
            Node n = arr[i];
            //System.out.println(n.data);
            pq.add(new Pair(n ));
        }
        
        while(pq.size()>0 ){
            Pair p = pq.remove();
            Node temp = p.n;
            //System.out.println(temp.data);
            //node mein add mein glti hai baki sab chal ra hai
            if( ans == null ) {
                ans   = temp;
                head=ans;
            }
            else {ans.next = temp ;
            ans=ans.next;
            }
            //System.out.println(ans.data);
            p.n =  p.n.next ;
            if( p.n != null ){
                pq.add(p);
            }
        }
    
        return head;
    }