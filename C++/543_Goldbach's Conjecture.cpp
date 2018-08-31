#include<cstdio>
#include<map>
using namespace std;
map<int,int>prime;
bool pl[1000001];
int main(){
    int i,j,k;
    map<int,int>::iterator it;
    for(i=1;i<=1000000;i++){
        pl[i]=true;
    }
    prime[i]=i;
    for(i=2;i<=1000000;i++){
        if(pl[i]){
            prime[i]=i;
            for(k=2,j=i*k;j<=1000000;k++,j=i*k){
                pl[j]=false;
            }
        }
    }
    while(~scanf("%d",&k)&&k!=0){
        for(it=prime.begin();it!=prime.end();it++){
            i=k-(it->first);
            if(prime.count(i)>0){
                printf("%d = %d + %d\n",k,it->first,i);
                break;
            }
        }
    }
    return 0;
}
