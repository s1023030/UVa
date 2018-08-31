#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>house;
int main(){
    int caseN,houseN,tempInt,answer,i,j,k,l;
    scanf("%d",&caseN);
    for(i=1;i<=caseN;i++){
        scanf("%d",&houseN);
        for(j=1;j<=houseN;j++){
            scanf("%d",&tempInt);
            house.push_back(tempInt);
        }
        answer=0;
        sort(house.begin(),house.begin()+houseN);
        for(j=0;j<houseN/2;j++){
            answer+=house[houseN-1-j]-house[0+j];
        }
        printf("%d\n",answer);
        house.clear();
    }
    return 0;
}
