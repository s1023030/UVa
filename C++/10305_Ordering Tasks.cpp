#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
    int tab;
    vector<int>outLink;
    int inDegree;
};
bool compare(node a,node b){
    if(a.inDegree==b.inDegree){
        return a.tab>b.tab;
    }
    return a.inDegree<b.inDegree;
}
node task[101];
int main(){
    int n,m,j,i,k,from,to;
    while(~scanf("%d%d",&n,&m)&&n!=0||m!=0){
        for(i=1;i<=n;i++){
            task[i].inDegree=0;
            task[i].tab=i;
            if(task[i].outLink.size()>0){
                task[i].outLink.clear();
            }
        }
        for(i=1;i<=m;i++){
            scanf("%d%d",&from,&to);
            task[from].outLink.push_back(to);
            task[to].inDegree++;
        }
        for(i=1;i<=n;i++){
            sort(&task[i],&task[i]+n-i+1,compare);
            for(j=0;j<task[i].outLink.size();j++){
                for(k=i;k<=n;k++){
                    if(task[k].tab==task[i].outLink[j]){
                        task[k].inDegree--;
                        break;
                    }
                }
            }
        }
        printf("%d",task[1].tab);
        for(i=2;i<=n;i++){
            printf(" %d",task[i].tab);
        }
        printf("\n");
    }
    return 0;
}
