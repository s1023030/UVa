#include<cstdio>
#include<queue>
#include<vector>
#include<map>
using namespace std;
struct edge{
    int A,B,value;
};
bool operator<(const edge& a,const edge& b){
    return (a.value>b.value);
}
map<int,int>group;
vector<edge>answerSet;
priority_queue<edge>myQueue;
bool Find(int A,int B){
    int GA=group[A],GB=group[B];
    while(GA!=A){
        group[A]=group[GA];
        A=GA;
        GA=group[A];
    }
    while(GB!=B){
        group[B]=group[GB];
        B=GB;
        GB=group[B];
    }
    if(GA==GB){
        return true;
    }
    group[GB]=GA;
    return false;
}
int main(){
    int compSitesN,answer,K,i,M,ccc=0;
    edge tempEdge;
    while(~scanf("%d",&compSitesN)&&compSitesN!=0){
        if(ccc>0){
            printf("\n");
        }
        answer=0;
        for(i=1;i<compSitesN;i++){
            scanf("%d%d%d",&tempEdge.A,&tempEdge.B,&tempEdge.value);
            group[i]=i;
            answer+=tempEdge.value;
        }
        group[compSitesN]=compSitesN;
        printf("%d\n",answer);
        scanf("%d",&K);
        for(i=1;i<=K;i++){
            scanf("%d%d%d",&tempEdge.A,&tempEdge.B,&tempEdge.value);
            myQueue.push(tempEdge);
        }
        scanf("%d",&M);
        for(i=1;i<=M;i++){
            scanf("%d%d%d",&tempEdge.A,&tempEdge.B,&tempEdge.value);
            myQueue.push(tempEdge);
        }
        answer=0;
        while(answerSet.size()<compSitesN-1){
            tempEdge=myQueue.top();
            myQueue.pop();
            if(!Find(tempEdge.A,tempEdge.B)){
                answerSet.push_back(tempEdge);
                answer+=tempEdge.value;
            }
        }
        printf("%d\n",answer);
        while(myQueue.size()>0){
            myQueue.pop();
        }
        ccc++;
        answerSet.clear();
        group.clear();
    }
    return 0;
}