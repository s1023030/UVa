#include<cstdio>
#include<vector>
using namespace std;
bool pl[1001];
vector<int>primeList;
int main(){
    int maxx,n,i,j;
    primeList.push_back(0);
    for(i=2;i<=1000;i++){
      pl[i]=true;
    }
    primeList.push_back(1);
    for(i=2;i<=1000;i++){
      if(pl[i]){
        primeList.push_back(i);
        for(n=2,j=n*i;j<=1000;n++,j=n*i){
            pl[j]=false;
        }
      }
    }
    /*freopen("out.txt","w",stdout);
    printf("50\n");
    printf("%d",primeList[0]);
    for(i=1;i<50;i++){
        printf(",%d",primeList[i]);
    }*/

    while(~scanf("%d%d",&maxx,&n)){
        for(i=1;i<primeList.size();i++){
            if(primeList[i]>maxx){
                i--;
                break;
            }
        }
        if(i==primeList.size()){
            i--;
        }
        printf("%d %d:",maxx,n);
        if(i%2==1){
            if((i/2)-n+2>0){
                for(j=(i/2)-n+2;j<=i/2+n;j++){
                    printf(" %d",primeList[j]);
                }
            }
            else{
                for(j=1;j<=i;j++){
                    printf(" %d",primeList[j]);
                }
            }
        }
        else{
            if(i/2-n+1>0){
                for(j=i/2-n+1;j<=i/2+n;j++){
                   printf(" %d",primeList[j]);
                }
            }
            else{
                for(j=1;j<=i;j++){
                    printf(" %d",primeList[j]);
                }
            }
        }
        printf("\n\n");
    }
    return 0;
}
