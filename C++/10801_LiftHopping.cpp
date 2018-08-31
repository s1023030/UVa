#include<cstdio>
#include<map>
#include<vector>
#include<queue>
using namespace std;
struct floor{
    int L,F,time;
};
vector< map<int,floor> >lift;
priority_queue<floor>myQueue;
int liftSpeed[5];
bool operator<(const floor&a,const floor&b){
    return a.time>b.time;
}
int main(){
    map<int,floor>tempLift;
    map<int,floor>::iterator it;
    floor tempFloor;
    bool have;
    int liftN,destFloor,dist,floorNXT,nowL,nowF,i,j,k,tempInt,totalFloor;
    char tempChar;
    while(~scanf("%d%d",&liftN,&destFloor)&&liftN!=0){
        for(i=0;i<liftN;i++){
            scanf("%d",&liftSpeed[i]);
        }
        tempFloor.time=0x3FFFFFFF;
        totalFloor=0;
        for(i=0;i<liftN;i++){
            tempFloor.L=i;
            while(scanf("%d%c",&tempInt,&tempChar)){
                totalFloor++;
                tempFloor.F=tempInt;
                if(tempInt==0){
                    tempFloor.time=0;
                    tempLift[tempInt]=tempFloor;
                    myQueue.push(tempFloor);
                    tempFloor.time=0x3FFFFFFF;
                }
                else{
                    tempLift[tempInt]=tempFloor;
                }
                if(tempChar=='\n'){
                    break;
                }
            }
            lift.push_back(tempLift);
            tempLift.clear();
        }
        for(i=0;i<liftN;i++){
            for(it=lift[i].begin();it!=lift[i].end();it++){
                have=false;
                if(it->first!=0&&it->first!=destFloor){
                    for(j=0;j<liftN;j++){
                        if(i!=j&&lift[j].count(it->first)>0){
                            have=true;
                            break;
                        }
                    }
                    if(!have){
                        totalFloor--;
                        lift[i].erase(it->first);
                    }
                }
            }
        }
        tempInt=0x3FFFFFFF;
        while(myQueue.size()>0){
            tempFloor=myQueue.top();
            myQueue.pop();
            nowL=tempFloor.L;
            nowF=tempFloor.F;
            if(nowF==destFloor){
                if(tempInt>lift[nowL][nowF].time){
                    tempInt=lift[nowL][nowF].time;
                }
            }
            for(it=lift[nowL].begin();it!=lift[nowL].end();it++){
                floorNXT=it->first;
                if(floorNXT-nowF>0){
                    dist=(floorNXT-nowF)*liftSpeed[nowL];
                }
                else{
                    dist=(nowF-floorNXT)*liftSpeed[nowL];
                }
                if(lift[nowL][nowF].time+dist<it->second.time){
                    tempFloor.F=floorNXT;
                    tempFloor.L=nowL;
                    tempFloor.time=lift[nowL][nowF].time+dist;
                    lift[nowL][floorNXT]=tempFloor;
                    myQueue.push(tempFloor);
                }
            }
            for(i=0;i<liftN;i++){
                if(lift[i].count(nowF)>0){
                    if(lift[nowL][nowF].time+60<lift[i][nowF].time){
                        tempFloor.F=nowF;
                        tempFloor.L=i;
                        tempFloor.time=lift[nowL][nowF].time+60;
                        lift[i][nowF]=tempFloor;
                        myQueue.push(tempFloor);

                    }
                }
            }
        }
        if(tempInt==0x3FFFFFFF){
            printf("IMPOSSIBLE\n");
        }
        else{
            printf("%d\n",tempInt);
        }
        while(myQueue.size()>0){
            myQueue.pop();
        }
        lift.clear();
    }
    return 0;
}
