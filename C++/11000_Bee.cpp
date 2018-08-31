#include<cstdio>
#include<map>
#include<fstream>
using namespace std;

map<int,long long>store;
long long  x,y;
long long funct(int n,bool flag){
    if(store.count(n)>0){
        if(flag){
            y=funct(n-1,0);
            printf("%lld %lld\n",store[n],store[n]+y+1);
        }
        return store[n];
    }
    else{
        x=funct(n-2,0);
        y=funct(n-1,0);
        store[n]=y+x+1;
        if(flag){
            printf("%lld %lld\n",store[n],store[n]+y+1);
        }
        return store[n];
    }
}
int main(){
    int n;
    store[-2]=-1;
    store[-1]=0;
    store[0]=0;
    store[1]=1;
    store[2]=2;
    store[3]=4;
    store[10]=143;
    store[20]=17710;
    store[30]=2178308;
    store[40]=267914295;
    store[50]=32951280098;
    for(n=4;n<=50;n++){
         funct(n,0);
    }
    while(scanf("%d",&n)&&n>=0){
        funct(n,1);
    }
    return 0;
}
