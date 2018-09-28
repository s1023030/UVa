import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;
class Node{
    int num;
    ArrayList<Integer>next;
    Node(int num){
        this.num=num;
        this.next=new ArrayList<Integer>();
    }
    void setEdge(int num){
        this.next.add(num);
    }
}
public class Main {
    static int numNode,numEdge;
    static Node[] graph;
    static int[] visit,low,stack,contract,indegree;
    static boolean[] instack;
    static int t,top;

    private static void DFS(int i){
        visit[i]=low[i]=++t;
        stack[top++]=i;
        instack[i]=true;

        for(int j=0;j<graph[i].next.size();j++){
            int next=graph[i].next.get(j);
            if(visit[next]==0){
                DFS(next);
            }
            if(instack[next]){
                low[i]=Math.min(low[i],low[next]);
            }
        }
        if(visit[i]==low[i]){
            int j;
            do{
                j=stack[--top];
                instack[j]=false;
                contract[j]=i;
            }while(j!=i);
        }
    }

    public static void main(String[] args){
        Scanner input=new Scanner(System.in);
        int numTset=input.nextInt();
        for(int i=0;i<numTset;i++){
            numNode=input.nextInt();
            numEdge=input.nextInt();
            graph=new Node[numNode];
            visit=new int[numNode];
            low=new int[numNode];
            stack=new int[numNode];
            contract=new int[numNode];
            indegree=new int[numNode];
            instack=new boolean[numNode];
            t=0;top=0;
            for(int j=0;j<numNode;j++){
                graph[j]=new Node(j);
            }
            for(int j=0;j<numEdge;j++){
                int a=input.nextInt()-1;
                int b=input.nextInt()-1;
                graph[a].setEdge(b);
                //graph[b].setEdge(a);
            }
            Arrays.fill(visit,0);
            for(int j=0;j<numNode;j++){
                if(visit[j]==0){
                    DFS(j);
                }
            }
            for (int j=0;j<numNode;j++){
                for (int k=0;k<graph[j].next.size();k++){
                    int v=graph[j].next.get(k);
                    if(contract[j]!=contract[v]){
                        indegree[contract[v]]++;
                    }
                    if(contract[j]!=v){
                        indegree[v]++;
                    }
                }
            }
            int ans=0;
            for(int j=0;j<numNode;j++){
                if(indegree[j]==0){
                    ans++;
                }
            }
            System.out.println(ans);
        }
    }
}
