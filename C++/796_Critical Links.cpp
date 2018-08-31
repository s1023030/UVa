#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
inline int min(int a,int b){
    if(a>b){
        return b;
    }
    return a;
}
struct server{
    int num,low;
};
struct edge{
    int a,b;
};
int dfsNum;
vector<server>node;
vector<edge>answer;
vector<vector<int> >graph;
vector<int>tmpG;
bool comp(edge aa,edge bb){
    if(aa.a==bb.a){
        return aa.b<bb.b;
    }
    return aa.a<bb.a;
}
edge tmpE;
bool isBiDirection(int x,int y){
    for(int i=0;i<graph[y].size();i++){
        if(graph[y][i]==x){
            return true;
        }
    }
    return false;
}
void findBridge(int parent,int now){
    int tmp;
    dfsNum++;
    node[now].num=node[now].low=dfsNum;
    for(int i=0;i<graph[now].size();i++){
        tmp=graph[now][i];
        if(node[tmp].num==-1){
            findBridge(now,tmp);
        }
        if(parent!=tmp){
            node[now].low=min(node[tmp].low,node[now].low);
        }
        if(node[tmp].low>node[now].num&&isBiDirection(now,tmp)){
            if(tmp>now){
                tmpE.a=now;
                tmpE.b=tmp;
            }
            else{
                tmpE.b=now;
                tmpE.a=tmp;
            }
            answer.push_back(tmpE);
        }
    }
}
int main(){
    server tmpSer;
    int serverN,connectN,tmp1,tmp2,i,j;
    tmpSer.low=-1;
    tmpSer.num=-1;
    while(~scanf("%d",&serverN)){
        dfsNum=0;
        for(i=0;i<serverN;i++){
            graph.push_back(tmpG);
            node.push_back(tmpSer);
        }
        for(i=0;i<serverN;i++){
            scanf("%d",&tmp1);
            scanf("%*2c%d%*1c",&connectN);
            for(j=1;j<=connectN;j++){
                scanf("%d",&tmp2);
                graph[tmp1].push_back(tmp2);
            }
        }
        for(i=0;i<serverN;i++){
            if(node[i].num==-1){
                findBridge(-1,i);
            }
        }
        sort(&answer[0],&answer[0]+answer.size(),comp);
        printf("%d critical links\n",answer.size());
        for(i=0;i<answer.size();i++){
            printf("%d - %d\n",answer[i].a,answer[i].b);
        }
        for(i=0;i<serverN;i++){
            if(graph[i].size()>0){
                graph[i].clear();
            }
        }
        graph.clear();
        if(node.size()>0){
            node.clear();
        }
        if(answer.size()>0){
            answer.clear();
        }
        puts("");
    }
    return 0;
}
