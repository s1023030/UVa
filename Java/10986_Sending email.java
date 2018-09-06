import java.util.Scanner;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Objects;
class Connection{
    public int from,to,cost;
}
class Server implements Comparable<Server> {
    int number,d;
    public ArrayList<Connection>next=new ArrayList<Connection>();
    Server(int num){
        number=num;
        d=Integer.MAX_VALUE;
    }
    void setD(int num){
        d=num;
    }
    int getD(){
        return  d;
    }
    @Override
    public int compareTo(Server s) {
        if(this.d > s.getD()) {
            return 1;
        } else if (this.d < s.getD()) {
            return -1;
        } else {
            return 1;
        }
    }
}
class Dijkstra{
    int[] d;
    boolean[] visit;
    int source;
    PriorityQueue<Server> pq=new PriorityQueue<Server>();
    Dijkstra(int num,int s){
        source=s;
        d=new int[num];
        visit=new boolean[num];
        for(int i=0;i<num;i++){
            visit[i]=false;
        }
        for(int i=0;i<num;i++){
            d[i]=Integer.MAX_VALUE;
        }
        d[source]=0;
    }
}
public class Main {
    public static void main(String[] args){
        Scanner input=new Scanner(System.in);
        Server tmpSer1;
        Connection tmpCon1,tmpCon2;
        int numCase=input.nextInt();
        for(int i=1;i<=numCase;i++){
            int n,m,S,T;
            ArrayList<Server>graph=new ArrayList<Server>();
            n=input.nextInt();
            for(int a=0;a<n;a++){
                graph.add(new Server(a));
            }
            m=input.nextInt();
            S=input.nextInt();
            T=input.nextInt();
            for(int a=0;a<m;a++){
                tmpCon1=new Connection();
                tmpCon1.from=input.nextInt();
                tmpCon1.to=input.nextInt();
                tmpCon1.cost=input.nextInt();
                tmpCon2=new Connection();
                tmpCon2.from=tmpCon1.to;
                tmpCon2.to=tmpCon1.from;
                tmpCon2.cost=tmpCon1.cost;
                tmpSer1=graph.get(tmpCon1.from);
                tmpSer1.next.add(tmpCon1);
                tmpSer1=graph.get(tmpCon2.from);
                tmpSer1.next.add(tmpCon2);
            }
            Dijkstra dijkstra=new Dijkstra(n,S);
            tmpSer1=new Server(S);
            tmpSer1.setD(0);
            dijkstra.pq.offer(tmpSer1);
            for(int a=0;a<n;a++){
                int select=-1;
                while(!dijkstra.pq.isEmpty()&&dijkstra.visit[select=dijkstra.pq.peek().number]){
                    dijkstra.pq.poll();
                }

                //System.out.printf("#%d\n",select);
                if(select==-1){break;}
                dijkstra.visit[select]=true;
                if(select==T){
                    break;
                }
                for(int b=0;b<graph.get(select).next.size();b++){
                    tmpCon1=graph.get(select).next.get(b);
                    if(!dijkstra.visit[tmpCon1.to]&&dijkstra.d[select]+tmpCon1.cost<dijkstra.d[tmpCon1.to]){
                        dijkstra.d[tmpCon1.to]=dijkstra.d[select]+tmpCon1.cost;
                        tmpSer1=new Server(tmpCon1.to);
                        tmpSer1.setD(dijkstra.d[select]+tmpCon1.cost);
                        dijkstra.pq.offer(tmpSer1);
                    }
                }
                //System.out.printf("!%d\n",dijkstra.pq.size());
            }
            if(dijkstra.d[T]<Integer.MAX_VALUE){
                System.out.printf("Case #%d: %d\n",i,dijkstra.d[T]);
            }
            else{
                System.out.printf("Case #%d: unreachable\n",i);
            }
        }
    }
}
