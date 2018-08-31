#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
struct them{
    int num;
    int times;
};
struct state{
    int att,tol;
    vector<int>answer;
};
stack<state>process;
them store[12];
int main(){
    state tmpState;
    int total,tn,n,i,j,tmpInt,tat;
    bool have;
    while(scanf("%d%d",&total,&n)&&n!=0){
        for(i=0;i<n;i++){
            store[i].num=-1;
            store[i].times=0;
        }
        scanf("%d",&store[0].num);
        store[0].times++;
        j=0;
        for(i=1;i<n;i++){
            scanf("%d",&tmpInt);
            if(store[j].num!=tmpInt){
                j++;
                store[j].num=tmpInt;
            }
            store[j].times++;
        }
        tn=j;
        tmpState.att=0;tmpState.answer.clear();tmpState.tol=0;
        process.push(tmpState);
        printf("Sums of %d:\n",total);
        have=false;
        while(process.size()>0){
            tmpState=process.top();
            process.pop();
            tat=tmpState.att;
            if(tat>tn){
                continue;
            }
            tmpState.att++;
            process.push(tmpState);
            for(i=1;i<=store[tat].times;i++){
                tmpState.tol+=store[tat].num;
                tmpState.answer.push_back(store[tat].num);
                if(tmpState.tol==total){//answer
                    have=true;
                    printf("%d",tmpState.answer[0]);
                    for(j=1;j<tmpState.answer.size();j++){
                        printf("+%d",tmpState.answer[j]);
                    }
                    printf("\n");
                    break;
                }
                else if(tmpState.tol>total){
                    break;
                }
                process.push(tmpState);
            }
        }
        if(!have){
            printf("NONE\n");
        }
    }
    return 0;
}
