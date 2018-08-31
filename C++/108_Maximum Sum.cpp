#include<cstdio>
#include<climits>
using namespace std;
int main(){
    int n,i,j,k;
    scanf("%d",&n);
    int store[n][n];
    int cumu[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&store[i][j]);
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
    long long int max=LLONG_MIN,min=0,answer=LLONG_MIN,before,tempInt;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){//i
            if(i==0){
                for(k=0;k<n;k++){
                    tempInt=cumu[j][k];
                    if(tempInt>max){
                        max=tempInt;
                        if(max-min>answer){
                            answer=max-min;
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
                for(k=0;k<n;k++){
                    tempInt=cumu[j][k]-cumu[i-1][k];
                    if(tempInt>max){
                        max=tempInt;
                        if(max-min>answer){
                            answer=max-min;
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
    printf("%d\n",(int)answer);
    return 0;
}
