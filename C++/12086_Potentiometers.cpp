#include<cstdio>
using namespace std;
int meter[200001];
void update(int value,int pos,int bound){
    for(pos+=(pos&(-pos));pos<=bound;pos+=(pos&(-pos))){
        meter[pos]+=value;
    }
}
int sum(int n){
    int s=0;
    while(n>0){
        s+=meter[n];
        n-=(n&(-n));
    }
    return s;
}
int query(int a,int b){
    return sum(b)-sum(a-1);
}
int main(){
    int n,i,tempA,tempB,tempInt,casse=1;
    char op[6];
    while(scanf("%d",&n)&&n!=0){
        for(i=1;i<=n;i++){
            scanf("%d",&meter[i]);
        }
        for(i=n;i>=1;i--){
            update(meter[i],i,n);
        }
        if(casse>=2){
            printf("\n");
        }
        printf("Case %d:\n",casse);
        while(scanf("%s",&op)&&op[0]!='E'){
            if(op[0]=='S'){
                scanf("%d%d",&tempA,&tempB);
                if(tempA>1){
                     tempInt=sum(tempA)-sum(tempA-1);
                     update(tempB-tempInt,tempA,n);
                     meter[tempA]+=tempB-tempInt;
                }
                else{
                    update(tempB-meter[tempA],tempA,n);
                    meter[tempA]=tempB;
                }
            }
             else{
                scanf("%d%d",&tempA,&tempB);
                if(tempA>tempB){
                    printf("%d\n",query(tempB,tempA));
                }
                else{
                    printf("%d\n",query(tempA,tempB));
                }
            }
        }
        casse++;
    }
    return 0;
}
/*
      5
  2       6
1   3   5   7

     10
  3       11
1   3   5   7

1 3 7 15 31 63 127 255 511

1 2 3 4 5 6 7
0 1 2 0 5 1 2
0 1 2 3 5 6 2
       3
   1       6
0    2   5    2
1~1=1
1~2=2
1~3=2+3
1~4=4
1~5=4+5
1~6=4+6
1~7=4+6+7
1~8=8
1~9=8+9
1~10=8+10
1~11=8+10+11
*/
