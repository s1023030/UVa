import java.util.Scanner;
import java.util.ArrayList;
class Passage{
    public int from,to,cost;
}
class Cell{
    public ArrayList<Passage>next=new ArrayList<Passage>();
    public boolean isExit=false;
}
class Dijkstra{
    int[] d;
    boolean[] visit;
    int source;
    Dijkstra(int numCell,int s){
        source=s;
        d=new int[numCell];
        visit=new boolean[numCell];
        for(int i=0;i<numCell;i++){
            visit[i]=false;
        }
        for(int i=0;i<numCell;i++){
            d[i]=Integer.MAX_VALUE;
        }
        d[source]=0;
    }
}
public class Main {
    public static void main(String[] args){
        Scanner input=new Scanner(System.in);
        Cell tmpCell;
        Passage tmpPass;
        Dijkstra dijkstra;
        ArrayList<Cell> graph;
        int numCase=input.nextInt();
        for(int i=0;i<numCase;i++){
            int numCell=input.nextInt();
            int answer=0;
            graph=new ArrayList<Cell>();
            for(int j=0;j<numCell;j++){
                tmpCell=new Cell();
                graph.add(tmpCell);
            }
            int exit=input.nextInt()-1;
            tmpCell=graph.get(exit);
            tmpCell.isExit=false;
            int timer=input.nextInt();
            int numPath=input.nextInt();
            for(int j=0;j<numPath;j++){
                tmpPass=new Passage();
                tmpPass.from=input.nextInt()-1;
                tmpPass.to=input.nextInt()-1;
                tmpPass.cost=input.nextInt();
                tmpCell=graph.get(tmpPass.from);
                tmpCell.next.add(tmpPass);
            }
            for(int j=0;j<numCell;j++){
                dijkstra=new Dijkstra(numCell,j);
                for (int k=0;k<numCell;k++){
                    int a=-1,min=Integer.MAX_VALUE;
                    for(int m=0;m<numCell;m++){
                        if(!dijkstra.visit[m]&&dijkstra.d[m]<min){
                            a=m;
                            min=dijkstra.d[m];
                        }
                    }
                    if(a==-1){break;}
                    if(a==exit){
                        break;
                    }
                    if(min==Integer.MAX_VALUE){break;}
                    dijkstra.visit[a]=true;
                    for(int b=0;b<graph.get(a).next.size();b++){
                        tmpPass=graph.get(a).next.get(b);
                        if(!dijkstra.visit[tmpPass.to]&&dijkstra.d[a]+tmpPass.cost<dijkstra.d[tmpPass.to]){
                            dijkstra.d[tmpPass.to]=dijkstra.d[a]+tmpPass.cost;
                        }
                    }
                }
                if(timer>=dijkstra.d[exit]){
                    answer++;
                }
            }
            System.out.println(answer);
            if(i<numCase-1){
                System.out.println();
            }
        }
    }
}
