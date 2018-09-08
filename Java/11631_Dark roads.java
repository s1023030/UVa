import java.util.Scanner;
import java.util.Objects;
import java.util.Arrays;
import java.util.PriorityQueue;
class Edge implements Comparable<Edge>{
    int nodeA,nodeB,length;
    Edge(int nodeA,int nodeB,int length){
        this.nodeA=nodeA;
        this.nodeB=nodeB;
        this.length=length;
    }
    @Override
    public int compareTo(Edge edge){
        return this.length-edge.length;
    }
}
public class Main {
    static int nodes[];
    static  int find(int a){
        if(nodes[a]!=-1){
            return nodes[a]=find(nodes[a]);
        }
        else{
            return a;
        }
    }
    public static void main(String[] args){
        Scanner input=new Scanner(System.in);
        int numNode,numEdge;
        Edge tmpEdge;
        numNode=input.nextInt();
        numEdge=input.nextInt();
        while(numNode!=0&&numEdge!=0){
            int before=0;
            nodes=new int[numNode];
            Arrays.fill(nodes,-1);
            PriorityQueue<Edge>pq=new PriorityQueue<Edge>();
            for(int i=0;i<numEdge;i++){
                tmpEdge=new Edge(input.nextInt(),input.nextInt(),input.nextInt());
                before+=tmpEdge.length;
                pq.offer(tmpEdge);
            }
            int after=0;
            int num=0;
            while(num<numNode-1&&pq.size()!=0){
                tmpEdge=pq.poll();
                int aa=find(tmpEdge.nodeA);
                int bb=find(tmpEdge.nodeB);
                if(aa!=bb){
                    after+=tmpEdge.length;
                    nodes[bb]=aa;
                    num+=1;
                }
            }
            System.out.println(before-after);
            numNode=input.nextInt();
            numEdge=input.nextInt();
        }
    }
}
