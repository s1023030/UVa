#include<cstdio>
#include<climits>
using namespace std;
int main(){
    int bets,i;
    bool BT0;
    long long int max=LLONG_MIN,min=0,answer=LLONG_MIN,before,tempInt;
    while(scanf("%d",&bets)&&bets!=0){
        BT0=false;
        for(i=0;i<bets;i++){
            scanf("%lld",&tempInt);
            if(i!=0){
                tempInt+=before;
            }
            if(tempInt>max){
                max=tempInt;
                if(max-min>answer){
                    answer=max-min;
                }
                if(!BT0&&tempInt>0){
                    BT0=true;
                }
            }
            if(tempInt<min){
                min=tempInt;
                max=min;
            }
            //printf("cum:%d max:%d min:%d answer:%d\n",tempInt,max,min,answer);
            before=tempInt;
        }
        if(!BT0){
            printf("%s\n","Losing streak.");
        }
        else{
            printf("%s %d%s","The maximum winning streak is",(int)answer,".\n");
        }
        max=LLONG_MIN;
        min=0;
        answer=LLONG_MIN;
    }
    return 0;
}