#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
vector<bool>tmgh(5);
struct state{
    vector<int>node;
    vector<vector<bool> >graph;
    state(){
        for(int i=0;i<5;i++){
            graph.push_back(tmgh);
        }
    }
};

state tmpState,tmpState1,tmpState2;
int z;
void PRINT(){
    for(z=0;z<9;z++){
        printf("%d",tmpState1.node[z]+1);
    }
    printf("\n");
    return ;
}
stack<state>process;
int main(){
    int i,j,N,att,a,b;
    tmpState .graph[0][0]=0;tmpState .graph[0][1]=1;tmpState .graph[0][2]=1;tmpState .graph[0][3]=0;tmpState .graph[0][4]=1;
    tmpState .graph[1][0]=1;tmpState .graph[1][1]=0;tmpState .graph[1][2]=1;tmpState .graph[1][3]=0;tmpState .graph[1][4]=1;
    tmpState .graph[2][0]=1;tmpState .graph[2][1]=1;tmpState .graph[2][2]=0;tmpState .graph[2][3]=1;tmpState .graph[2][4]=1;
    tmpState .graph[3][0]=0;tmpState .graph[3][1]=0;tmpState .graph[3][2]=1;tmpState .graph[3][3]=0;tmpState .graph[3][4]=1;
    tmpState .graph[4][0]=1;tmpState .graph[4][1]=1;tmpState .graph[4][2]=1;tmpState .graph[4][3]=1;tmpState .graph[4][4]=0;
    for(i=0;i<1;i++){
        tmpState.node.push_back(i);
        process.push(tmpState);
        while(process.size()>0){
            tmpState1=process.top();
            process.pop();
            att=tmpState1.node.size()-1;
            if(att==8){
                PRINT();
                continue;
            }
            N=tmpState1.node[att];
            for(j=4;j>=0;j--){
                if(tmpState1.graph[N][j]){
                    tmpState2=tmpState1;
                    tmpState2.graph[N][j]=false;
                    tmpState2.graph[j][N]=false;
                    tmpState2.node.push_back(j);
                    process.push(tmpState2);

                }
            }
        }
        tmpState.node.clear();
    }
    return 0;
}
