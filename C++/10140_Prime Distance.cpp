#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
bool check[46352];
int prime[4792];
unsigned int i,j;
//map<int,int>::iterator it;
inline bool isPrime(unsigned int t){
    if(t<=46351){
        if(!check[t]){
            return true;
        }
        else{
            return false;
        }
    }
    for(int it=0;it<=4791&&prime[it]<=(int)(sqrt(t)+0.01);it++){
        if(t%prime[it]==0){
            return false;
        }
    }
    return true;
}
int main(){
    int coun=0;
    unsigned int L,U,past,Max,Min,max1,max2,min1,min2;
    check[1]=true;
    for(i=2;i<=46352;i++){
        if(!check[i]){
            prime[coun++]=i;
            for(j=i*i;j<=46342;j+=i){
                check[j]=true;
            }
        }
    }
    freopen("out.txt","w",stdout);
    while(cin>>L>>U){
        Min=2147483647;
        Max=0;\
        for(j=L;!isPrime(j);j++);
        L=j;
        if(L==2){
            past=2;
            L++;
            i=L;
        }
        else{
            past=L;
            L+=2;
            i=L;
        }
        for(;i<=U;i+=2){
            if(isPrime(i)){
                if(i-past>Max){
                    max1=past;
                    max2=i;
                    Max=i-past;
                }
                if(i-past<Min){
                    min1=past;
                    min2=i;
                    Min=i-past;
                }
                past=i;
            }
        }
        if(Max==0){
            cout<<"There are no adjacent primes.\n";
        }
        else{
            cout<<min1<<","<<min2<<" are closest, "<<max1<<","<<max2<<" are most distant.\n";
        }
    }


    return 0;
}
