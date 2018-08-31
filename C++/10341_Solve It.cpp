#include<cstdio>
#include<cmath>
using namespace std;
int p,q,r,s,t,u;
inline double calculate(double x){
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*(x*x)+u;
}
int main(){
    double l,b,tl,tu;
    while(~scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)){
        l=0.0;b=1.0;
        tl=calculate(l);
        tu=calculate(l+b);
        if(tl*tu>0){
            puts("No solution");
        }
        else if(p==0&&q==0&&r==0&&s==0&&t==0&&u==0){
            puts("0.0000");
        }
        else{
            while(b>1e-9){
                tl=calculate(l);
                tu=calculate(l+(b/2.0));
                if(tu*tl<=0){
                    b/=2.0;
                }
                else{
                    l=l+b/2.0;
                    b/2.0;
                }
            }
            printf("%1.4lf\n",l);
        }
    }
    return 0;
}
