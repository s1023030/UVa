#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
bool check[31623];
int prime[3401];
int main(){
    int i,j,k,L,U,tmpInt,caseN,maxNum,maxDivi,Count=0,tmpCount;
    for(i=2;i<=31622;i++){
        if(!check[i]){
            prime[Count]=i;
            for(j=i*i;j<=31622;j+=i){
                check[j]=true;
            }
            Count++;
        }
    }
    scanf("%d",&caseN);
    for(i=1;i<=caseN;i++){
        scanf("%d%d",&L,&U);
        maxDivi=0;
        for(j=U;j>=L;j--){
            tmpInt=j;
            Count=1;
            for(k=0;k<=3400&&prime[k]<=(int)sqrt((double)tmpInt);k++){
                if(tmpInt%prime[k]==0){
                    tmpCount=1;
                    do{
                        tmpCount++;
                        tmpInt=tmpInt/prime[k];
                    }while(tmpInt%prime[k]==0);
                    Count*=tmpCount;
                }
            }
            if(tmpInt>1){
                Count*=2;
            }
            if(Count>=maxDivi){
                maxDivi=Count;
                maxNum=j;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",L,U,maxNum,maxDivi);
    }
    return 0;
}
