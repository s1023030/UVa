#include<cstdio>
#include<vector>
#include<cstring>
#include<stack>

using namespace std;
vector<vector<int> >graph;
vector<int>tmpG;
char visit[101];
stack<int>DFSP;
void dfs(int node){
    int z;
    visit[node]=0;
    DFSP.push(node);
    while(DFSP.size()>0){
        node=DFSP.top();
        DFSP.pop();
        for(z=0;z<graph[node].size();z++){
            if(visit[graph[node][z]]){
                visit[graph[node][z]]=0;
                DFSP.push(graph[node][z]);
            }
        }
    }
}
void dfs(int node,int forbi){
    int z;
    visit[node]=0;
    DFSP.push(node);
    while(DFSP.size()>0){
        node=DFSP.top();
        DFSP.pop();
        for(z=0;z<graph[node].size();z++){
            if(visit[graph[node][z]]&&graph[node][z]!=forbi){
                visit[graph[node][z]]=0;
                DFSP.push(graph[node][z]);
            }
        }
    }
}

int main(){
    int placeN,place,tmpInt,i,j,k,l,ori,comp,answer;
    char tmpChar;
    for(i=0;i<=100;i++){
        graph.push_back(tmpG);
    }
    while(scanf("%d",&placeN)&&placeN!=0){

        while(scanf("%d",&place)&&place!=0){
            while(scanf("%d",&tmpInt)){
                graph[place].push_back(tmpInt);
                graph[tmpInt].push_back(place);
                tmpChar=getchar();
                if(tmpChar=='\n'){
                    break;
                }
            }
        }
        memset(&visit[1],1,placeN);
        ori=0;
        answer=0;
        for(i=1;i<=placeN;i++){
            if(visit[i]){
                ori++;
                dfs(i);
            }
        }
        for(i=1;i<=placeN;i++){
            memset(&visit[1],1,placeN);
            comp=0;
            for(j=1;j<=placeN;j++){
                if(visit[j]&&j!=i){
                    comp++;
                    dfs(j,i);
                }
            }
            if(comp>ori){
                answer++;
            }
        }
        printf("%d\n",answer);
        for(i=1;i<=placeN;i++){
            if(graph[i].size()>0){
                graph[i].clear();
            }
        }
    }
    return 0;
}
