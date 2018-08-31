#include<cstdio>
using namespace std;
int main(){
    long long A,B,tmp,x1,x2,y1,y2;
    bool t=false;
    while(~scanf("%lld%lld",&A,&B)){
        t=false;
        if(B>A){
            t=true;
            tmp=B;
            B=A;
            A=tmp;
        }
        else if(A==B){
            printf("0 1 %lld\n",A);
            continue;
        }
        x1=1;y1=0;x2=0;y2=1;
        while(1){
            tmp=A/B;
            y1-=(tmp*y2);
            x1-=(tmp*x2);
            A=A%B;
            if(A==0){
                if(t){
                    printf("%lld %lld %lld\n",y2,x2,B);
                }
                else{
                    printf("%lld %lld %lld\n",x2,y2,B);
                }
                break;
            }
            tmp=B/A;
            y2-=(tmp*y1);
            x2-=(tmp*x1);
            B=B%A;
            if(B==0){
                if(t){
                    printf("%lld %lld %lld\n",y1,x1,A);
                }
                else{
                    printf("%lld %lld %lld\n",x1,y1,A);
                }
                break;
            }
        }

    }
    return 0;
}

