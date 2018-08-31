#include<cstdio>
#include<queue>
#include<cmath>
#include<map>
using namespace std;
struct number{
    int code[4];
};
struct edge{
    int cost,a,b;
};
bool operator<(const edge&a,const edge&b){
    return (a.cost>b.cost);
}
vector<number>state;
priority_queue<edge>myQueue;
map<int,int>group;
int tempInt,a;
number tempNumber;
edge tempEdge;
void NtoD(){
    for(a=0;a<4;a++){
        tempNumber.code[a]=tempInt%10;
        tempInt=tempInt/10;
    }
    state.push_back(tempNumber);
}
bool sameGroup(int A,int B){
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
    group[GA]=GB;
    return false;
}
int main(){
    int caseN,stateN,i,j,k,answer=0,acount,f0tx=0x3FFFFFFF;
    scanf("%d",&caseN);
    for(i=1;i<=caseN;i++){
        scanf("%d",&stateN);
        tempNumber.code[0]=0;tempNumber.code[1]=0;tempNumber.code[2]=0;tempNumber.code[3]=0;
        group[0]=0;
        state.push_back(tempNumber);
        for(j=1;j<=stateN;j++){
            scanf("%d",&tempInt);
            group[j]=j;
            NtoD();
        }
        f0tx=0x3FFFFFFF;
        for(i=0;i<state.size()-1;i++){
            for(j=i+1;j<state.size();j++){
                tempEdge.cost=0;
                tempEdge.a=i;
                tempEdge.b=j;
                for(k=0;k<4;k++){
                    if(state[i].code[k]>state[j].code[k]){
                        if(state[i].code[k]-state[j].code[k]<9-state[i].code[k]+state[j].code[k]+1){
                            tempEdge.cost+=state[i].code[k]-state[j].code[k];
                        }
                        else{
                            tempEdge.cost+=9-state[i].code[k]+state[j].code[k]+1;
                        }
                    }
                    else{
                        if(state[j].code[k]-state[i].code[k]<9-state[j].code[k]+state[i].code[k]+1){
                            tempEdge.cost+=state[j].code[k]-state[i].code[k];
                        }
                        else{
                            tempEdge.cost+=9-state[j].code[k]+state[i].code[k]+1;
                        }
                    }
                }
                if(i==0){
                    if(tempEdge.cost<f0tx){
                        f0tx=tempEdge.cost;
                    }
                }
                else{
                    myQueue.push(tempEdge);
                }
            }
        }
        answer=0;
        acount=0;
        while(acount<stateN-1){
            tempEdge=myQueue.top();
            myQueue.pop();
            if(!sameGroup(tempEdge.a,tempEdge.b)){
                acount++;
                answer+=tempEdge.cost;
            }
        }
        printf("%d\n",answer+f0tx);
        group.clear();
        state.clear();
        while(myQueue.size()>0){
            myQueue.pop();
        }
    }
    return 0;
}
/*
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 4 3 2 1
*//*
0000 1111=4
1111 1155=8
1111 5511=8
2 2 4 4
    0000 1234 5678 9090
0000   0   10   26   18
1234  10    0   16
5678  26    8    0   12
9090  18    8   12    0*/
