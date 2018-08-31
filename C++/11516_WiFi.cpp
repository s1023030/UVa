#include<cstdio>
#include<algorithm>
using namespace std;
int house[100001];
int main(){
    int caseN,i,j,k,l,apN,houseN,tmpInt,bAt,bStep,range,access,tapN;
    bool isCan;
    scanf("%d",&caseN);
    for(i=1;i<=caseN;i++){
        scanf("%d%d",&apN,&houseN);
        for(j=0;j<houseN;j++){
            scanf("%d",&tmpInt);
            house[j]=tmpInt*10;
        }
        sort(house,house+houseN);
        bStep=(house[houseN-1]-house[0])/2;
        bAt=0;
        while(1){
            isCan=true;
            range=bAt+bStep;
            tapN=apN;
            j=0;
            while(j<houseN){
                access=house[j]+range*2;
                tapN--;
                while(j<houseN&&access>=house[j]){
                    j++;
                }
                if(j==houseN){//Yes;
                    isCan=true;
                    break;
                }
                else if(tapN==0){//No;
                    isCan=false;
                    break;
                }
            }
            if(!isCan){
                bAt=range+5;
            }
             if(bStep==0){
                printf("%.1lf\n",(double)(bAt)/10.0);
                break;
            }
            bStep=bStep/2;
            if(bStep%5>0){
                bStep-=2;
            }
        }

    }
    return 0;
}
