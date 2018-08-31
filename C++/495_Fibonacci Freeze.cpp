#include<cstdio>
#include<vector>
using namespace std;
struct number{
    vector<int>digit;
};
number Fib[5001];
int main(){
    int i,j,tmpInt;
    Fib[0].digit.push_back(0);
    Fib[1].digit.push_back(1);
    for(i=2;i<=44;i++){
        Fib[i].digit.push_back(Fib[i-1].digit[0]+Fib[i-2].digit[0]);
    }
    for(i=45;i<=5000;i++){
        tmpInt=0;
        for(j=0;j<Fib[i-2].digit.size();j++){
            tmpInt=Fib[i-1].digit[j]+Fib[i-2].digit[j]+tmpInt;
            if(tmpInt/1000000000>0){
                tmpInt-=1000000000;
                Fib[i].digit.push_back(tmpInt);
                tmpInt=1;
            }
            else{
                Fib[i].digit.push_back(tmpInt);
                tmpInt=0;
            }
        }
        if(Fib[i-1].digit.size()>Fib[i-2].digit.size()){
            Fib[i].digit.push_back(Fib[i-1].digit[j]);
        }
        if(tmpInt==1){
            if(Fib[i].digit.size()<j+1){
                Fib[i].digit.push_back(tmpInt);
            }
            else{
                Fib[i].digit[j]++;
            }
        }
    }
    while(~scanf("%d",&i)){
        printf("The Fibonacci number for %d is ",i);
        for(j=Fib[i].digit.size()-1;j>=0;j--){
            if(j<Fib[i].digit.size()-1){
                printf("%09d",Fib[i].digit[j]);
            }
            else{
                printf("%d",Fib[i].digit[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
