#include<vector>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
struct circle{
    int cNum,cMin,cCost;
};
map<int,int>oPos;
map<int,int>cPath;
vector<circle>circus;
bool visisted[1000];
int original[1000],sorted[1000];
int main(){
    //freopen("in.txt","r",stdin);
    int allNum,allMin,i,start,tmp,answer,Case=1;
    circle tmpCircle;
    while(scanf("%d",&allNum)&&allNum!=0){
        answer=0;
        scanf("%d",&original[0]);
        sorted[0]=allMin=original[0];
        oPos[original[0]]=0;
        for(i=1;i<allNum;i++){
            scanf("%d",&original[i]);
            sorted[i]=original[i];
            oPos[original[i]]=i;
            if(allMin>original[i]){
                allMin=original[i];
            }
        }
        sort(sorted,sorted+allNum);
        for(i=0;i<allNum;i++){
            cPath[oPos[sorted[i]]]=i;
            visisted[i]=false;
        }
        for(i=0;i<allNum;i++){
            if(!visisted[i]){
                visisted[i]=true;
                start=i;
                tmpCircle.cMin=original[i];
                tmpCircle.cNum=1;//
                tmpCircle.cCost=original[i];
                tmp=cPath[start];
                while(tmp!=start){
                    visisted[tmp]=true;
                    if(tmpCircle.cMin>original[tmp]){
                        tmpCircle.cMin=original[tmp];
                    }
                    tmpCircle.cNum++;
                    tmpCircle.cCost+=original[tmp];
                    tmp=cPath[tmp];
                }
                tmpCircle.cCost-=tmpCircle.cMin;
                tmpCircle.cNum--;
                if(tmpCircle.cMin*(tmpCircle.cNum)>2*(allMin+tmpCircle.cMin)+allMin*(tmpCircle.cNum)){
                    answer+=2*(allMin+tmpCircle.cMin)+allMin*(tmpCircle.cNum)+tmpCircle.cCost;
                }
                else{
                    answer+=tmpCircle.cMin*(tmpCircle.cNum)+tmpCircle.cCost;
                }
            }
        }
        printf("Case %d: %d\n\n",Case++,answer);
        circus.clear();
        oPos.clear();
        cPath.clear();
    }
    return 0;
}
