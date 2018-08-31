#include<cstdio>
#include<map>
using namespace std;
map<int,int>cycleLength;
int tempInt;
int calLength(int num){
    if(cycleLength.count(num)>0){
        return cycleLength[num];
    }
    else{
        if(num%2==1){
            tempInt=calLength(3*num+1)+1;
            cycleLength[num]=tempInt;
            return tempInt;
        }
        else{
            tempInt=calLength(num/2)+1;
            cycleLength[num]=tempInt;
            return tempInt;
        }
    }
}
int main(){
    int low,upp,maxx,i;
    cycleLength[1]=1;
    while(~scanf("%d%d",&low,&upp)){
       maxx=-1;
       if(low>upp){
            for(i=upp;i<=low;i++){
               tempInt=calLength(i);
               if(maxx<tempInt){
                    maxx=tempInt;
               }
            }
       }
       else{
            for(i=low;i<=upp;i++){
               tempInt=calLength(i);
               if(maxx<tempInt){
                    maxx=tempInt;
               }
            }
       }
       printf("%d %d %d\n",low,upp,maxx);
    }
    return 0;
}
