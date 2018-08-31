#include<cstdio>
#include<queue>
using namespace std;
struct edge{
    int pa,pb,weight;
};
int setPoint[200000];
priority_queue<edge>PL;
bool operator<(const edge aa,const edge bb){
    return (aa.weight>bb.weight);
}
bool sameSet(int a,int b){
    int ga=setPoint[a],gb=setPoint[b];
    while(ga!=a){
        setPoint[a]=setPoint[ga];
        a=ga;
        ga=setPoint[a];
    }
    while(gb!=b){
        setPoint[b]=setPoint[gb];
        b=gb;
        gb=setPoint[b];
    }
    if(ga==gb){
        return true;
    }
    setPoint[ga]=setPoint[gb];
    return false;

}
int main(){
    int nodeN,edgeN,i,j,TN,answer;
    edge tmpEdge;
    while(~scanf("%d%d",&nodeN,&edgeN)&&nodeN!=0&&edgeN!=0){
        for(i=0;i<nodeN;i++){
            setPoint[i]=i;
        }
        for(i=0;i<edgeN;i++){
            scanf("%d%d%d",&tmpEdge.pa,&tmpEdge.pb,&tmpEdge.weight);
            PL.push(tmpEdge);
        }
        TN=0;
        answer=0;
        while(PL.size()>0){
            tmpEdge=PL.top();
            PL.pop();
            if(TN>=nodeN-1){
                answer+=tmpEdge.weight;
            }
            else if(sameSet(tmpEdge.pa,tmpEdge.pb)){
                answer+=tmpEdge.weight;
            }
            else{
                TN++;
            }
        }
        printf("%d\n",answer);
    }
    return 0;
}
