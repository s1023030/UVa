#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
struct shape{
    char type;
    double lux,luy,rdx,rdy;
    double ox,oy,rad;
    double ax,ay,bx,by,cx,cy;
};
struct point{
    double px,py;
};
shape tmpShape;
point tmpP;
vector<shape>store;
double distance(double p1x,double p1y,double p2x,double p2y){
    return sqrt(pow(p1x-p2x,2.0)+pow(p1y-p2y,2.0));
}
bool testRect(point p,int t){
    if(p.px>store[t].lux&&p.px<store[t].rdx&&p.py>store[t].rdy&&p.py<store[t].luy){
        return true;
    }
    return false;
}
bool testCirc(point p,int t){
    if(distance(p.px,p.py,store[t].ox,store[t].oy)<store[t].rad){
        return true;
    }
    return false;
}
double triArea(double aa,double bb,double cc){
    double s=(aa+bb+cc)/2.0;
    return sqrt(s*(s-aa)*(s-bb)*(s-cc));
}
bool testTria(point p,int t){
    double ab,ac,bc,ap,bp,cp;
    double abp,acp,bcp,abc;
    ab=distance(store[t].ax,store[t].ay,store[t].bx,store[t].by);
    ac=distance(store[t].ax,store[t].ay,store[t].cx,store[t].cy);
    bc=distance(store[t].cx,store[t].cy,store[t].bx,store[t].by);
    ap=distance(store[t].ax,store[t].ay,p.px,p.py);
    bp=distance(store[t].bx,store[t].by,p.px,p.py);
    cp=distance(store[t].cx,store[t].cy,p.px,p.py);
    abp=triArea(ab,bp,ap);
    acp=triArea(ac,cp,ap);
    bcp=triArea(bc,cp,bp);
    abc=triArea(ab,bc,ac);
    if(abp>-0.9999&&abp<0.0001){
        return false;
    }
    if(acp>-0.9999&&acp<0.0001){
        return false;
    }
    if(bcp>-0.9999&&bcp<0.0001){
        return false;
    }
    if(abp+acp+bcp>abc-0.00001&&abp+acp+bcp<abc+0.00001){
        return true;
    }
    return false;
}
int main(){
    int i,pNumber=1;
    bool flag;
    char tmpChar[2];
    while(scanf("%s",&tmpChar)&&tmpChar[0]!='*'){
        tmpShape.type=tmpChar[0];
        if(tmpShape.type=='r'){
            scanf("%lf%lf%lf%lf",&tmpShape.lux,&tmpShape.luy,&tmpShape.rdx,&tmpShape.rdy);
        }
        else if(tmpShape.type=='c'){
            scanf("%lf%lf%lf",&tmpShape.ox,&tmpShape.oy,&tmpShape.rad);
        }
        else if(tmpShape.type=='t'){
             scanf("%lf %lf %lf %lf %lf %lf",&tmpShape.ax,&tmpShape.ay,&tmpShape.bx,&tmpShape.by,&tmpShape.cx,&tmpShape.cy);
        }
        store.push_back(tmpShape);
    }
    while(scanf("%lf%lf",&tmpP.px,&tmpP.py)&&((tmpP.px<9999.899||tmpP.px>9999.901)&&(tmpP.py<9999.899||tmpP.py>9999.901))){
        flag=true;
        for(i=0;i<store.size();i++){
            if(store[i].type=='r'){
                if(testRect(tmpP,i)){
                    printf("Point %d is contained in figure %d\n",pNumber,i+1);
                    flag=false;
                }
            }
            else if(store[i].type=='c'){
                if(testCirc(tmpP,i)){
                    printf("Point %d is contained in figure %d\n",pNumber,i+1);
                    flag=false;
                }
            }
            else{
                if(testTria(tmpP,i)){
                    printf("Point %d is contained in figure %d\n",pNumber,i+1);
                    flag=false;
                }
            }
        }
        if(flag){
            printf("Point %d is not contained in any figure\n",pNumber);
        }
        pNumber++;
    }
    return 0;
}
