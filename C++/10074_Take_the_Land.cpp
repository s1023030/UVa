#include<cstdio>
#include<climits>
using namespace std;
int main(){
    int row,col,i,j,k;
    int store[100][100];
    int cumu[100][100];
    long long int max=LLONG_MIN,min=0,answer=LLONG_MIN,tempInt;
    while(scanf("%d%d",&row,&col)&&row!=0&&col!=0){
        max=LLONG_MIN;
        min=0;
        answer=LLONG_MIN;
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                scanf("%d",&k);
                if(k==1){
                    store[i][j]=-10000;
                }
                else{
                    store[i][j]=1;
                }
                if(j>0){
                    if(i==0){
                        cumu[i][j]=store[i][j]+cumu[i][j-1];
                    }
                    else{
                        cumu[i][j]=store[i][j]+cumu[i-1][j]+cumu[i][j-1]-cumu[i-1][j-1];
                    }
                }
                else{
                    if(i==0){
                        cumu[i][j]=store[i][j];
                    }
                    else{
                        cumu[i][j]=store[i][j]+cumu[i-1][j];
                    }

                }
            }
        }
        for(i=0;i<row;i++){
            for(j=i;j<row;j++){//i
                if(i==0){
                    for(k=0;k<col;k++){
                        tempInt=cumu[j][k];
                        if(tempInt>max){
                            max=tempInt;
                            if(max-min>answer){
                                answer=max-min;
                                //printf("answer:%d i:%d j:%d k:%d\n",(int)answer,i,j,k);
                            }
                        }
                        if(tempInt<min){
                            min=tempInt;
                            max=min;
                        }
                    }
                    max=LLONG_MIN;
                    min=0;
                }
                else{
                    for(k=0;k<col;k++){
                        tempInt=cumu[j][k]-cumu[i-1][k];
                        if(tempInt>max){
                            max=tempInt;
                            if(max-min>answer){
                                answer=max-min;
                                //printf("answer:%d i:%d j:%d k:%d\n",(int)answer,i,j,k);
                            }
                        }
                        if(tempInt<min){
                            min=tempInt;
                            max=min;
                        }
                    }
                    max=LLONG_MIN;
                    min=0;
                }
            }
        }
        if(answer<0){
            printf("%d\n",0);
        }
        else{
            printf("%d\n",(int)answer);
        }
    }
    return 0;
}
