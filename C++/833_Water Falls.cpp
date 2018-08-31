#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct point{
    int x,y;
};
struct line{
    point hiP,loP;
    point leP,riP;
    int tox;
};
vector<line>land;
bool compare(line aa,line bb){
    return aa.loP.y>bb.loP.y;
}
bool inRange(point o,int t){
    point left,right;
    double crossP;
    left.x=land[t].leP.x-o.x;
    left.y=land[t].leP.y-o.y;
    right.x=land[t].riP.x-o.x;
    right.y=land[t].riP.y-o.y;
    crossP=left.x*right.y-left.y*right.x;
    if(crossP>0){
        return true;
    }
    return false;
}
int main(){
    point tmpPoint1,tmpPoint2;
    line tmpLine;
    int caseN,lineN,pointN,answer,i,j,k;
    scanf("%d",&caseN);
    for(i=1;i<=caseN;i++){
        scanf("%d",&lineN);
        for(j=0;j<lineN;j++){
            scanf("%d%d",&tmpPoint1.x,&tmpPoint1.y);
            scanf("%d%d",&tmpPoint2.x,&tmpPoint2.y);
            if(tmpPoint1.y>tmpPoint2.y){
                tmpLine.hiP=tmpPoint1;
                tmpLine.loP=tmpPoint2;
            }
            else{
                tmpLine.hiP=tmpPoint2;
                tmpLine.loP=tmpPoint1;
            }
            if(tmpPoint1.x>tmpPoint2.x){
                tmpLine.riP=tmpPoint1;
                tmpLine.leP=tmpPoint2;
            }
            else{
                tmpLine.riP=tmpPoint2;
                tmpLine.leP=tmpPoint1;
            }
            land.push_back(tmpLine);
        }
        if(lineN>0){
            sort(&land[0],&land[0]+lineN,compare);
            land[lineN-1].tox=land[lineN-1].loP.x;
            for(j=lineN-2;j>=0;j--){
                for(k=j+1;k<lineN;k++){
                    if(land[j].loP.y>land[k].loP.y&&land[j].loP.x>land[k].leP.x&&land[j].loP.x<land[k].riP.x){
                        if(inRange(land[j].loP,k)){
                            land[j].tox=land[k].tox;
                            goto YES;
                        }
                    }
                }
                land[j].tox=land[j].loP.x;
                YES:;
            }
        }
        scanf("%d",&pointN);
        for(j=0;j<pointN;j++){
            scanf("%d%d",&tmpPoint1.x,&tmpPoint1.y);
            for(k=0;k<lineN;k++){
                if(tmpPoint1.y>land[k].loP.y&&tmpPoint1.x>land[k].leP.x&&tmpPoint1.x<land[k].riP.x){
                    if(inRange(tmpPoint1,k)){
                        answer=land[k].tox;
                        goto END;
                    }
                }
            }
            answer=tmpPoint1.x;
            END:;

            printf("%d\n",answer);
        }
        if(i<caseN){
            puts("");
            land.clear();
        }
    }
    return 0;
}
