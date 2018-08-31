#include<cstdio>
#include<vector>
#include<map>
#include<queue>
using namespace std;
inline int min(int aa,int bb){
    if(aa>bb){
        return bb;
    }
    return aa;
}
struct edge{
    int to,weight;
};
struct node{
    int tag;
    vector<edge>adj;
    int dist;
};
map<int,int>exist;
priority_queue<node>process;
bool operator<(const node a,const node b){
    return a.dist>b.dist;
}
vector<node>graph;
int main(){
    int caseN,n,m,s,t,i,j,tmpN1,tmpN2,tmpN3;
    bool flag;
    node tmpNode;
    edge tmpEdge;
    scanf("%d",&caseN);
    for(i=1;i<=caseN;i++){
        scanf("%d%d%d%d",&n,&m,&s,&t);
        flag=true;
        tmpNode.adj.clear();
        tmpNode.dist=0x4FFFFFFF;
        for(j=0;j<n;j++){
            tmpNode.tag=j;
            graph.push_back(tmpNode);
        }
        for(j=0;j<m;j++){
            scanf("%d%d%d",&tmpN1,&tmpN2,&tmpEdge.weight);
            tmpEdge.to=tmpN2;
            graph[tmpN1].adj.push_back(tmpEdge);
            tmpEdge.to=tmpN1;
            graph[tmpN2].adj.push_back(tmpEdge);
        }
        graph[s].dist=0;
        process.push(graph[s]);
        while(process.size()>0){
            tmpNode=process.top();
            process.pop();
            if(exist.count(tmpNode.tag)>0){
                continue;
            }
            exist[tmpNode.tag]=1;
            if(tmpNode.tag==t){
                flag=false;
                break;
            }
            for(j=0;j<tmpNode.adj.size();j++){
                tmpN1=tmpNode.adj[j].to;
                tmpN2=tmpNode.adj[j].weight;
                if(exist.count(tmpN1)>0){
                    continue;
                }
                graph[tmpN1].dist=min(graph[tmpN1].dist,tmpNode.dist+tmpN2);
                process.push(graph[tmpN1]);
            }
        }
        printf("Case #%d:",i);
        if(flag){
            puts(" unreachable");
        }
        else{
            printf(" %d\n",graph[t].dist);
        }
        graph.clear();
        exist.clear();
        while(process.size()>0){
            process.pop();
        }
    }
    return 0;
}
