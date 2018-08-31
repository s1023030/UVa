#include<cstdio>

using namespace std;

inline int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
int ac[21],test[21],LIS[21];
int main(){
    int N,i,j,k,tmp;
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%d",&ac[i]);
    }
    while(~scanf("%d",&tmp)){
        k=1;
        test[tmp]=k;
        LIS[1]=1;
        k++;
        for(i=2;i<=N;i++){
            scanf("%d",&tmp);
            test[tmp]=k;
            LIS[i]=1;
            k++;
        }
        for(i=1;i<=N;i++){
            for(j=i+1;j<=N;j++){
                if(ac[test[i]]<ac[test[j]]){
                    LIS[j]=max(LIS[j],LIS[i]+1);
                }
            }
        }
        tmp=0;
        for(i=1;i<=N;i++){
            tmp=max(LIS[i],tmp);
        }
        printf("%d\n",tmp);
    }
    return 0;
}

