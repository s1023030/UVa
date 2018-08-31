#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
bool prime[38];
void pri(){
    int i;
    for(i=1;i<=36;i++){
        prime[i]=false;
    }
    prime[2]=true;prime[3]=true;prime[5]=true;prime[7]=true;prime[11]=true;prime[13]=true;
    prime[17]=true;prime[19]=true;prime[23]=true;prime[29]=true;prime[31]=true;prime[37]=true;
}
struct state{
    vector<bool>isUse;
    vector<int>answer;
    int att;
};
state tmpState;
stack<state>process;
int main(){
    int n,kase=1,i,j,k,l;
    state tmpState;
    pri();
    while(~scanf("%d",&n)&&n>=1&&n<=16){
        if(kase>1){
            printf("\n");
        }
        if(tmpState.isUse.size()>0){
            tmpState.isUse.clear();
        }
        for(i=0;i<=n;i++){
            tmpState.isUse.push_back(false);
        }
        if(tmpState.answer.size()>0){
            tmpState.answer.clear();
        }
        tmpState.att=0;
        tmpState.answer.push_back(1);
        tmpState.isUse[1]=true;
        printf("Case %d:\n",kase);
        if(n==1){
            printf("1\n");
            kase++;
            continue;
        }
        process.push(tmpState);
        while(process.size()>0){
            tmpState=process.top();
            process.pop();
            tmpState.att++;
            for(i=n;i>=2;i--){
                if(!tmpState.isUse[i]){
                    if(tmpState.att==n-1){
                        if(prime[tmpState.answer[tmpState.att-1]+i]&&prime[i+1]){
                            //answer
                            tmpState.answer.push_back(i);
                            printf("1");
                            for(j=1;j<=tmpState.att;j++){
                                printf(" %d",tmpState.answer[j]);
                            }
                            printf("\n");
                            break;
                        }
                    }
                    else{
                        if(prime[tmpState.answer[tmpState.att-1]+i]){
                            tmpState.answer.push_back(i);
                            tmpState.isUse[i]=true;
                            process.push(tmpState);
                            tmpState.answer.pop_back();
                            tmpState.isUse[i]=false;
                        }
                    }
                }
            }

        }
        kase++;
    }
    return 0;
}
