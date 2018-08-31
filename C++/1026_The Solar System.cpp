#include<cstdio>
#include<cmath>
using namespace std;
#define pi M_PI
int main(){
    int a1,a2,t1,b1,b2,kase=1;
    double t2,area,tx,c2;
    double left,bound,mid,tmp,x,y;
    while(scanf("%d%d%d%d%d%lf",&a1,&b1,&t1,&a2,&b2,&tx)){
        if(a1==0&&b1==0&&t1==0&&a2==0&&b2==0&&tx==0){
            break;
        }
        t2=pow((double)a2,3.0)*t1*t1/pow((double)a1,3.0);
        t2=sqrt(t2);
        while(tx>t2){
            tx=tx-t2;
        }
        area=pi*a2*b2;
        area=area*tx/t2;
        left=0.0;
        bound=2*pi;
        c2=sqrt(a2*a2-b2*b2);
        while(bound>1e-9){
            mid=left+bound/2.0;
            tmp=(a2*b2*mid-b2*c2*sin(mid))/2.0;
            if(tmp<area){
                left=left+bound/2.0;
                bound/=2.0;
            }
            else{
                bound/=2.0;
            }
        }
        x=a2*cos(left+bound);
        y=b2*sin(left+bound);
        if(x<0&&x>-0.0000000999){
            x*=-1;
        }
        if(y<0&&y>-0.0000000999){
            y*=-1;
        }
        printf("Solar System %d: %.3lf %.3lf\n",kase,x,y);
        kase++;
    }
    return 0;
}
