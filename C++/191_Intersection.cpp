#include<cstdio>
#include<algorithm>
using namespace std;
struct point{
    int x,y;
};
struct line{
    point A,B;
};
line rect[4];
bool intersect1D(int a1,int a2,int b1,int b2){
    if(a1>a2){
        swap(a1,a2);
    }
    if(b1>b2){
        swap(b1,b2);
    }
    return max(a1,b1)>min(a2,b2);
}
int cross(point aa,point bb,point cc){
    int v1x,v1y,v2x,v2y;
    v1x=bb.x-aa.x;
    v1y=bb.y-aa.y;
    v2x=cc.x-aa.x;
    v2y=cc.y-aa.y;
    return v1x*v2y-v1y*v2x;
}
int main(){
    //freopen("output.txt","w",stdout);
    int caseN,i,j,tmpInt;
    point lineA,lineB,rectA,rectB;
    scanf("%d",&caseN);
    for(i=1;i<=caseN;i++){
        scanf("%d%d%d%d",&lineA.x,&lineA.y,&lineB.x,&lineB.y);
        scanf("%d%d%d%d",&rectA.x,&rectA.y,&rectB.x,&rectB.y);
        if(rectA.x>rectB.x){
            swap(rectA.x,rectB.x);
        }
        if(rectA.y>rectB.y){
            swap(rectA.y,rectB.y);
        }
        if(rectA.x<lineA.x&&rectA.x<lineB.x&&rectB.x>lineA.x&&rectB.x>lineB.x){
            if(rectA.y<lineA.y&&rectA.y<lineB.y&&rectB.y>lineA.y&&rectB.y>lineB.y){
                puts("T");
                goto END;
            }
        }
        /*
              1 B
            0   2
            A 3
        */
        rect[3].A=rect[0].A=rectA;
        rect[2].A=rect[1].A=rectB;
        rect[1].B.x=rect[0].B.x=rectA.x;
        rect[1].B.y=rect[0].B.y=rectB.y;
        rect[2].B.x=rect[3].B.x=rectB.x;
        rect[2].B.y=rect[3].B.y=rectA.y;
        for(j=0;j<4;j++){
            if(intersect1D(lineA.x,lineB.x,rect[j].A.x,rect[j].B.x)){
               continue;
            }
            if(intersect1D(lineA.y,lineB.y,rect[j].A.y,rect[j].B.y)){
               continue;
            }
            if(cross(lineA,lineB,rect[j].A)*cross(lineA,lineB,rect[j].B)<=0){
                if(cross(rect[j].A,rect[j].B,lineA)*cross(rect[j].A,rect[j].B,lineB)<=0){
                    puts("T");
                    goto END;
                }
            }
        }
        puts("F");
        END:;
    }
    return 0;
}
