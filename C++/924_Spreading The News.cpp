#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
struct employee{
    bool rec;
    int day;
    vector<int>frie;
};
employee relation[2500];
unsigned int value[2500];
queue<int>process;
int main(){
    int menN,frienN,queN,nxt,now,tmpInt,i,j,answer;
    scanf("%d",&menN);
    for(i=0;i<menN;i++){
        relation[i].rec=false;
        scanf("%d",&frienN);
        value[i]=0;
        for(j=0;j<frienN;j++){
            scanf("%d",&tmpInt);
            relation[i].frie.push_back(tmpInt);
        }
    }
    scanf("%d",&queN);
    for(i=0;i<queN;i++){
        scanf("%d",&tmpInt);
        relation[tmpInt].day=0;
        relation[tmpInt].rec=true;
        process.push(tmpInt);
        answer=0;
        while(process.size()>0){
            tmpInt=process.front();
            process.pop();
            now=relation[tmpInt].day;
            for(j=0;j<relation[tmpInt].frie.size();j++){
                nxt=relation[tmpInt].frie[j];
                if(!relation[nxt].rec){
                    value[now+1]++;
                    relation[nxt].day=now+1;
                    relation[nxt].rec=true;
                    process.push(nxt);
                }
            }
        }
        for(j=1;j<=now;j++){
            if(answer<value[j]){
                tmpInt=j;
                answer=value[j];
            }
            value[j]=0;
        }
        if(answer==0){
            printf("0\n");
        }
        else{
            printf("%d %d\n",answer,tmpInt);
        }
        if(i<queN-1){
            for(j=0;j<menN;j++){
                relation[j].rec=false;
            }
        }
    }
    return 0;
}
