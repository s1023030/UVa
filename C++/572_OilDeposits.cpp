#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct oil{
    int c,r;
};
int main(){
    int row,col,i,j,group=0;
    char charTemp;
    int graph[102][102];
    vector<oil>oilSlot;
    queue<oil>bfs;
    oil tempOil,atOil;
    while(cin>>row>>col&&row!=0&&col!=0){
        cin.get(charTemp);
        group=0;
        for(i=0;i<=row+1;i++){
            for(j=0;j<=col+1;j++){
                if(i!=0&&j!=0&&i!=row+1&&j!=col+1){
                    cin.get(charTemp);
                    if(charTemp=='*'){
                        graph[i][j]=-1;
                    }
                    else{
                        graph[i][j]=0;
                        tempOil.c=j;
                        tempOil.r=i;
                        oilSlot.push_back(tempOil);
                    }
                }
                else{
                    graph[i][j]=-1;
                }
            }
            if(i!=0&&i!=row+1){
                cin.get(charTemp);
            }
        }
        for(i=0;i<oilSlot.size();i++){
            if(graph[oilSlot[i].r][oilSlot[i].c]==0){
                group++;
                graph[oilSlot[i].r][oilSlot[i].c]=group;
                bfs.push(oilSlot[i]);
                while(bfs.size()>0){
                    atOil=bfs.front();
                    bfs.pop();
                    if(graph[atOil.r-1][atOil.c-1]==0){
                        graph[atOil.r-1][atOil.c-1]=group;
                        tempOil.c=atOil.c-1;
                        tempOil.r=atOil.r-1;
                        bfs.push(tempOil);
                    }
                    if(graph[atOil.r-1][atOil.c]==0){
                        graph[atOil.r-1][atOil.c]=group;
                        tempOil.c=atOil.c;
                        tempOil.r=atOil.r-1;
                        bfs.push(tempOil);
                    }
                     if(graph[atOil.r-1][atOil.c+1]==0){
                        graph[atOil.r-1][atOil.c+1]=group;
                        tempOil.c=atOil.c+1;
                        tempOil.r=atOil.r-1;
                        bfs.push(tempOil);
                    }
                    if(graph[atOil.r][atOil.c-1]==0){
                        graph[atOil.r][atOil.c-1]=group;
                        tempOil.c=atOil.c-1;
                        tempOil.r=atOil.r;
                        bfs.push(tempOil);
                    }
                    if(graph[atOil.r][atOil.c+1]==0){
                        graph[atOil.r][atOil.c+1]=group;
                        tempOil.c=atOil.c+1;
                        tempOil.r=atOil.r;
                        bfs.push(tempOil);
                    }
                    if(graph[atOil.r+1][atOil.c-1]==0){
                        graph[atOil.r+1][atOil.c-1]=group;
                        tempOil.c=atOil.c-1;
                        tempOil.r=atOil.r+1;
                        bfs.push(tempOil);
                    }
                    if(graph[atOil.r+1][atOil.c]==0){
                        graph[atOil.r+1][atOil.c]=group;
                        tempOil.c=atOil.c;
                        tempOil.r=atOil.r+1;
                        bfs.push(tempOil);
                    }
                    if(graph[atOil.r+1][atOil.c+1]==0){
                        graph[atOil.r+1][atOil.c+1]=group;
                        tempOil.c=atOil.c+1;
                        tempOil.r=atOil.r+1;
                        bfs.push(tempOil);
                    }

                }
            }
        }
        printf("%d\n",group);
        oilSlot.clear();
    }
    return 0;
}
