#include<cstdio>
#include<cmath>
#include<climits>
using namespace std;
struct point{
    char Name;
    double x,y;
};
point store[15];
double edge[15][15];
int answerSet[3];
int main(){
    int pointN,i,j,k,l;
    double tij,tik,tjk,pi,pj,pk,dijx,dijy,dikx,diky,djkx,djky,s,area,area1,area2,area3,answer;
    while(~scanf("%d",&pointN)&&pointN!=0){
        answer=-99.0;
        for(i=0;i<pointN;i++){
            scanf("%s%lf%lf",&store[i].Name,&store[i].x,&store[i].y);
            for(j=0;j<pointN;j++){
                edge[i][j]=-1;
                edge[j][i]=-1;
            }
        }

        for(i=0;i<pointN-2;i++){
            for(j=i+1;j<pointN-1;j++){
                for(k=j+1;k<pointN;k++){
                   //area=calArea(i,j,k);
                    if(edge[i][j]<0){
                        dijx=store[i].x-store[j].x;
                        dijy=store[i].y-store[j].y;
                        tij=sqrt(dijx*dijx+dijy*dijy);
                        edge[i][j]=tij;
                        edge[j][i]=tij;
                    }
                    else{
                        tij=edge[i][j];
                    }
                    if(edge[i][k]<0){
                        dikx=store[i].x-store[k].x;
                        diky=store[i].y-store[k].y;
                        tik=sqrt(dikx*dikx+diky*diky);
                        edge[i][k]=tik;
                        edge[k][i]=tik;
                    }
                    else{
                        tik=edge[i][k];
                    }
                    if(edge[j][k]<0){
                        djkx=store[j].x-store[k].x;
                        djky=store[j].y-store[k].y;
                        tjk=sqrt(djkx*djkx+djky*djky);
                        edge[j][k]=tjk;
                        edge[k][j]=tjk;
                    }
                    else{
                         tjk=edge[j][k];
                    }
                    s=(tij+tik+tjk)/2;
                    area=sqrt(s*(s-tij)*(s-tik)*(s-tjk));
                    if(area<=0.00001){
                        continue;
                    }
                    for(l=0;l<pointN;l++){
                        if(l==i||l==j||l==k){
                                continue;
                        }
                        if(edge[i][l]<0){
                            dijx=store[i].x-store[l].x;
                            dijy=store[i].y-store[l].y;
                            pi=sqrt(dijx*dijx+dijy*dijy);
                            edge[i][l]=pi;
                            edge[l][i]=pi;
                        }
                        else{
                            pi=edge[i][l];
                        }
                        if(edge[k][l]<0){
                            dikx=store[k].x-store[l].x;
                            diky=store[k].y-store[l].y;
                            pk=sqrt(dikx*dikx+diky*diky);
                            edge[l][k]=pk;
                            edge[k][l]=pk;
                        }
                        else{
                            pk=edge[k][l];
                        }
                        if(edge[j][l]<0){
                            djkx=store[j].x-store[l].x;
                            djky=store[j].y-store[l].y;
                            pj=sqrt(djkx*djkx+djky*djky);
                            edge[j][l]=pj;
                            edge[l][j]=pj;
                        }
                        else{
                             pj=edge[j][l];
                        }
                        s=(tij+pi+pj)/2;
                        area1=sqrt(s*(s-tij)*(s-pi)*(s-pj));
                        s=(pi+tik+pk)/2;
                        area2=sqrt(s*(s-pi)*(s-tik)*(s-pk));
                        s=(pj+pk+tjk)/2;
                        area3=sqrt(s*(s-pj)*(s-pk)*(s-tjk));
                        if(area>area1+area2+area3-0.002&&area<area1+area2+area3+0.002){
                            goto No;
                        }
                    }
                    if(area>answer){
                        answerSet[0]=i;
                        answerSet[1]=j;
                        answerSet[2]=k;
                        answer=area;
                    }
                    No:;
                }
            }
        }
        printf("%c%c%c\n",store[answerSet[0]].Name,store[answerSet[1]].Name,store[answerSet[2]].Name);
    }
    return 0;
}
