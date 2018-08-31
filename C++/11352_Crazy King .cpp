#include<cstdio>
#include<queue>
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
int main(){
    int caseN,ar,ac,i,j,k,row,col,dr,dc,sr,sc;
    bool flag;
    queue<int>pr;
    queue<int>pc;
    ifstream fin("input");
    char tempChar;
    int graph[104][104];
    fin>>caseN;
    for(i=1;i<=caseN;i++){
        fin>>row>>col;
        fin.get();
        for(j=0;j<=row+3;j++){
            for(k=0;k<=col+3;k++){
                if(j!=0&&j!=1&&k!=0&&k!=1&&j!=row+2&&j!=row+3&&k!=col+2&&k!=col+3){
                    fin.get(tempChar);
                    if(tempChar=='Z'){
                        graph[j][k]=-1;
                        graph[j-1][k-2]=-1;
                        graph[j-1][k+2]=-1;
                        graph[j-2][k-1]=-1;
                        graph[j-2][k+1]=-1;
                        graph[j+1][k+2]=-1;
                        graph[j+1][k-2]=-1;
                        graph[j+2][k+1]=-1;
                        graph[j+2][k-1]=-1;
                    }
                    else if(tempChar=='A'){
                        graph[j][k]=0;
                        sr=j;
                        sc=k;
                        pr.push(j);
                        pc.push(k);
                    }
                    else if(tempChar=='B'){
                        graph[j][k]=0;
                        dr=j;
                        dc=k;
                    }
                    else{
                        if(graph[j][k]!=-1){
                            graph[j][k]=0;
                        }
                    }
                }
                else{
                    graph[j][k]=-1;
                }
            }
            if(j!=0&&j!=1&&j!=row+2&&j!=row+3){
                fin.get(tempChar);
            }
        }

        graph[sr][sc]=0;
        graph[dr][dc]=0;
        flag=true;
        while(pr.size()>0){
            ar=pr.front();
            ac=pc.front();
            pr.pop();
            pc.pop();
            if(graph[ar-1][ac]==0){
                if(ar-1==dr&&ac==dc){
                    printf("Minimal possible length of a trip is %d\n",graph[ar][ac]+1);
                    flag=false;
                    break;
                }
                pr.push(ar-1);
                pc.push(ac);
                graph[ar-1][ac]=graph[ar][ac]+1;
            }
            if(graph[ar-1][ac-1]==0){
                if(ar-1==dr&&ac-1==dc){
                    printf("Minimal possible length of a trip is %d\n",graph[ar][ac]+1);
                    flag=false;
                    break;
                }
                pr.push(ar-1);
                pc.push(ac-1);
                graph[ar-1][ac-1]=graph[ar][ac]+1;
            }
            if(graph[ar-1][ac+1]==0){
                if(ar-1==dr&&ac+1==dc){
                    printf("Minimal possible length of a trip is %d\n",graph[ar][ac]+1);
                    flag=false;
                    break;
                }
                pr.push(ar-1);
                pc.push(ac+1);
                graph[ar-1][ac+1]=graph[ar][ac]+1;
            }
            if(graph[ar][ac+1]==0){
                if(ar==dr&&ac+1==dc){
                    printf("Minimal possible length of a trip is %d\n",graph[ar][ac]+1);
                    flag=false;
                    break;
                }
                pr.push(ar);
                pc.push(ac+1);
                graph[ar][ac+1]=graph[ar][ac]+1;
            }
            if(graph[ar][ac-1]==0){
                if(ar==dr&&ac-1==dc){
                    printf("Minimal possible length of a trip is %d\n",graph[ar][ac]+1);
                    flag=false;
                    break;
                }
                pr.push(ar);
                pc.push(ac-1);
                graph[ar][ac-1]=graph[ar][ac]+1;
            }
            if(graph[ar+1][ac-1]==0){
                if(ar+1==dr&&ac-1==dc){
                    printf("Minimal possible length of a trip is %d\n",graph[ar][ac]+1);
                    flag=false;
                    break;
                }
                pr.push(ar+1);
                pc.push(ac-1);
                graph[ar+1][ac-1]=graph[ar][ac]+1;
            }
            if(graph[ar+1][ac]==0){
                if(ar+1==dr&&ac==dc){
                    printf("Minimal possible length of a trip is %d\n",graph[ar][ac]+1);
                    flag=false;
                    break;
                }
                pr.push(ar+1);
                pc.push(ac);
                graph[ar+1][ac]=graph[ar][ac]+1;
            }
            if(graph[ar+1][ac+1]==0){
                if(ar+1==dr&&ac+1==dc){
                    printf("Minimal possible length of a trip is %d\n",graph[ar][ac]+1);
                    flag=false;
                    break;
                }
                pr.push(ar+1);
                pc.push(ac+1);
                graph[ar+1][ac+1]=graph[ar][ac]+1;
            }
        }
        if(flag){
            printf("King Peter, you can't go now!\n");
        }
         while(!pr.empty()){
            pr.pop();
        }
        while(!pc.empty()){
            pc.pop();
        }
        for(j=0;j<=row+3;j++){
            for(k=0;k<=col+3;k++){
                graph[j][k]=0;
            }
        }
    }
    fin.close();
    return 0;
}