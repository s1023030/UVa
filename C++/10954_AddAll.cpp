#include<cstdio>
#include<queue>
using namespace std;
struct num{
    int v;
};

bool operator<(const num& a,const num&b){
    return (a.v>b.v);
}
priority_queue<num>store;
int main(){
    int caseN,i,tempInt,answer;
    num tempNum;
    while(scanf("%d",&caseN)&&caseN!=0){
        answer=0;
        for(i=1;i<=caseN;i++){
            scanf("%d",&tempNum.v);
            store.push(tempNum);
        }
        while(store.size()>0){
            tempNum=store.top();
            store.pop();
            tempInt=tempNum.v;
            tempNum=store.top();
            store.pop();
            tempInt+=tempNum.v;
            answer+=tempInt;
            if(store.empty()){
                printf("%d\n",answer);
                break;
            }
            tempNum.v=tempInt;
            store.push(tempNum);
        }
    }
    return 0;
}
