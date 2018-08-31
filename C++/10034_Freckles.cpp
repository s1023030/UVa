#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;
struct line{
    double len;
    int pa,pb;
};
double point[100][2];
int pS[100];
priority_queue<line>LP;
bool operator<(const line AA,const line BB){
    return (AA.len>BB.len);
}
bool sameSet(int a,int b){
    int ga=pS[a],gb=pS[b];
    while(ga!=a){
        pS[a]=pS[ga];
        a=ga;
        ga=pS[a];
    }
    while(gb!=b){
        pS[b]=pS[gb];
        b=gb;
        gb=pS[b];
    }
    if(ga==gb){
        return true;
    }
    pS[ga]=pS[gb];
    return false;
}
int main(){
    int caseN,pointN,i,j,k,edge;
    double answer;
    line tmpLine;
    scanf("%d",&caseN);
    for(i=1;i<=caseN;i++){
        scanf("%d",&pointN);
        for(j=0;j<pointN;j++){
            scanf("%lf%lf",&point[j][0],&point[j][1]);
            pS[j]=j;
            tmpLine.pa=j;
            for(k=0;k<j;k++){
                tmpLine.pb=k;
                tmpLine.len=sqrt(pow(point[j][0]-point[k][0],2.0)+pow(point[j][1]-point[k][1],2.0));
                LP.push(tmpLine);
            }
        }
        answer=0.0;
        edge=0;
        while(edge<pointN-1&&LP.size()>0){
            tmpLine=LP.top();
            LP.pop();
            if(!sameSet(tmpLine.pa,tmpLine.pb)){
                answer+=tmpLine.len;
                edge++;
            }
        }
        printf("%.2lf\n",answer);
        if(i<caseN){
            printf("\n");
        }
        while(LP.size()>0){
            LP.pop();
        }
    }
    return 0;
}
