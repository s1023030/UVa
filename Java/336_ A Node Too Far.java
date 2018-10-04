import java.util.Scanner;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;
class Node{
    int isVisited;
    ArrayList<Integer>next;
    Node(){
        isVisited=0;
        next=new ArrayList<Integer>();
    }
}
public class Main {
    static public void main(String[] args){
        Scanner input=new Scanner(System.in);
        HashMap<Integer,Node>map;
        Queue<Integer>queue;
        Node tmpNode1,tmpNode2;
        int numCase=0;
        int numCon=input.nextInt();
        while(numCon!=0){
            map=new HashMap<Integer, Node>();
            int nFrom,nTo;
            for(int i=0;i<numCon;i++){
                nFrom=input.nextInt();
                nTo=input.nextInt();
                if(map.containsKey(nFrom)){
                    tmpNode1=map.get(nFrom);
                    tmpNode1.next.add(nTo);
                }else{
                    tmpNode1=new Node();
                    tmpNode1.next.add(nTo);
                    map.put(nFrom,tmpNode1);
                }
                if(map.containsKey(nTo)){
                    tmpNode1=map.get(nTo);
                    tmpNode1.next.add(nFrom);
                }else{
                    tmpNode1=new Node();
                    tmpNode1.next.add(nFrom);
                    map.put(nTo,tmpNode1);
                }
            }
            int startNode,TTL,tmpInt;
            startNode=input.nextInt();
            TTL=input.nextInt();
            while(startNode!=0||TTL!=0){
                TTL+=1;
                for(Integer key : map.keySet()) {
                    Node value = map.get(key);
                    value.isVisited=0;
                }
                queue=new LinkedList<Integer>();
                queue.offer(startNode);
                tmpNode1=map.get(startNode);
                tmpNode1.isVisited=1;
                while(!queue.isEmpty()){
                    tmpInt=queue.poll();
                    tmpNode1=map.get(tmpInt);
                    if(tmpNode1.isVisited<TTL){
                        for (int i=0;i<tmpNode1.next.size();i++){
                            tmpInt=tmpNode1.next.get(i);
                            tmpNode2=map.get(tmpInt);
                            if(tmpNode2.isVisited==0){
                                tmpNode2.isVisited=tmpNode1.isVisited+1;
                                queue.offer(tmpInt);
                            }
                        }
                    }
                }
                int answer=0;
                for(Integer key : map.keySet()) {
                    Node value = map.get(key);
                    if(value.isVisited==0){
                        answer++;
                    }
                }
                System.out.printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++numCase,answer,startNode,--TTL);
                startNode=input.nextInt();
                TTL=input.nextInt();
            }
            numCon=input.nextInt();
        }
    }
}
