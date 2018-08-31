#include<cstdio>
#include<cstdlib>
using namespace std;
int prime[5761455];
int loca[50000001];
bool pl[100000001];
int main(){
    int i,j,k,in,coun=-1,lo;
    bool flag;
    for(i=2;i<=100000000;i++){
        pl[i]=true;
    }
    for(i=2;i<=100000000;i++){
        if(i%2==0){
            lo=i/2;
            loca[lo]=coun;
        }
        if(pl[i]){
            coun++;
            prime[coun]=i;
            if(i%2==0){
                loca[lo]=coun;
            }
        }
        for(j=0;j<=coun;j++){
            k=prime[j]*i;
            if(k>100000000){
                break;
            }
            pl[k]=false;
            if (i%prime[j] == 0){
                break;
            }
        }
    }

    while(scanf("%d",&in)!=EOF){
        if(in<=4){
            printf("%d is not the sum of two primes!\n",in);
        }
        else if(in%2==1){
            j=in-2;
            if(pl[j]){
                 printf("%d is the sum of 2 and %d.\n",in,j);
            }
            else{
                printf("%d is not the sum of two primes!\n",in);
            }
        }
        else{
            flag=true;
            for(i=loca[in/4];i>=0;i--){
                j=in-(prime[i]);
                if(pl[j]){
                    if(j==prime[i]){
                        continue;
                    }
                    flag=false;
                    printf("%d is the sum of %d and %d.\n",in,prime[i],j);
                    break;
                }
            }
            if(flag){
                printf("%d is not the sum of two primes!\n",in);
            }
        }
    }
    return 0;
}
