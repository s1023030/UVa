import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        /*Comparator c = new Comparator() {
            public int compare(int a, int b) {
                return a-b;
            }
        };*/
        /*PriorityQueue pq = new PriorityQueue(5000,c);*/
        PriorityQueue<Long> pq=new PriorityQueue<Long>();
        while(input.hasNext()){
            pq.clear();
            int num=input.nextInt();
            long tmpLong;
            long answer=0L;
            if(num==0){
                break;
            }
            for(int i=0;i<num;i++){
                tmpLong=input.nextLong();
                pq.add(tmpLong);
            }
            while(!pq.isEmpty()&&num>1){
                tmpLong=(long)pq.poll()+(long) pq.poll();
                answer+=tmpLong;
                pq.offer(tmpLong);
                num--;
            }
            System.out.println(answer);
        }
    }
}
