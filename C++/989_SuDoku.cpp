#include<cstdio>
#include<stack>
#include<vector>
#include<cstdlib>

using namespace std;
struct state{
    int grid[9][9];
    bool row[9][10];
    bool col[9][10];
    bool block[9][10];
    int att;
};
struct position{
    int r,c;
};
state tmpState,tmpState1;
int n,i,j,k,l,tn,nat,nrow,ncol;
vector<position>zero;
stack<state>process;
bool operator<(const state&a,const state&b){
    return (a.att<b.att);
}
void answer(){
    for(j=0;j<tn;j++){
        for(k=0;k<tn;k++){
            printf("%d",tmpState.grid[j][k]);
            if(k<tn-1){
                printf(" ");
            }
            else{
                printf("\n");
            }
        }
    }
    return ;
}
int main(){
    int kase=0,tmpInt;
    position tmpPos;
    while(scanf("%d",&n)!=EOF&&n!=0){
        if(kase>0){
            printf("\n");
        }
        tn=n*n;
        for(i=0;i<tn;i++){
            for(j=0;j<=tn;j++){
                tmpState.col[i][j]=true;
                tmpState.row[i][j]=true;
                tmpState.block[i][j]=true;
            }
        }
        for(j=0;j<tn;j++){
            for(k=0;k<tn;k++){
                scanf("%d",&tmpState.grid[j][k]);
                if(tmpState.grid[j][k]==0){
                    tmpPos.r=j;
                    tmpPos.c=k;
                    zero.push_back(tmpPos);
                }
                else{
                    tmpState.col[k][tmpState.grid[j][k]]=false;
                    tmpState.row[j][tmpState.grid[j][k]]=false;
                    tmpState.block[j/n*n+k/n][tmpState.grid[j][k]]=false;
                }
            }
        }
        tmpState.att=0;
        process.push(tmpState);
        while(process.size()>0){
            tmpState=process.top();
            process.pop();
            nat=tmpState.att;
            if(zero.size()==0){
                answer();
                goto jump;
            }
            nrow=zero[nat].r;
            ncol=zero[nat].c;
            //printf("%d %d %d\n",process.size(),nrow,ncol);
          //  system("pause");
            for(i=tn;i>=1;i--){
                if(tmpState.block[nrow/n*n+ncol/n][i]&&tmpState.col[ncol][i]&&tmpState.row[nrow][i]){
                    if(tmpState.att==zero.size()-1){
                        tmpState.grid[nrow][ncol]=i;
                        answer();
                        goto jump;
                    }
                    tmpState1=tmpState;
                    tmpState1.grid[nrow][ncol]=i;
                    tmpState1.block[nrow/n*n+ncol/n][i]=false;
                    tmpState1.col[ncol][i]=false;
                    tmpState1.row[nrow][i]=false;
                    tmpState1.att++;
                    process.push(tmpState1);
                }
            }
        }
        printf("NO SOLUTION\n");
        jump:;
        zero.clear();
        while(process.size()>0){
            process.pop();
        }
        kase++;
    }
    return 0;
}
