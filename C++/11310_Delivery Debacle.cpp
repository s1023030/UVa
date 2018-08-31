#include<cstdio>
using namespace std;
long long store[42];
int main(){
    int i,caseN,tmpInt;
    store[1]=1;
    store[2]=5;
    store[3]=11;
    for(i=4;i<=41;i++){
        store[i]=store[i-1]+4*store[i-2]+2*store[i-3];
    }
    scanf("%d",&caseN);
    for(i=1;i<=caseN;i++){
        scanf("%d",&tmpInt);
        printf("%lld\n",store[tmpInt]);
    }
    return 0;
}

