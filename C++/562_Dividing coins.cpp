#include<cstdio>
#include<vector>
#include<map>
using namespace std;
vector<int>coins;
vector<int>m;
vector<int>tmpCul;
map<int,int>cul;
int main(){
    int caseN,coinN,tmp,i,j,k,total,answer;
    map<int,int>::iterator it;
    scanf("%d",&caseN);
    for(i=1;i<=caseN;i++){
        scanf("%d",&coinN);
        total=0;
        for(j=0;j<coinN;j++){
            scanf("%d",&tmp);
            total+=tmp;
            coins.push_back(tmp);
        }
        for(j=0;j<=total;j++){
            m.push_back(0);
        }
        m[0]=1;
        cul[coins[0]]=1;
        m[coins[0]]=1;
        for(j=1;j<coinN;j++){
            m[coins[j]]=1;
            tmpCul.clear();
            for(it=cul.begin();it!=cul.end();it++){
                tmp=coins[j]+it->first;
                if(tmp<=total){
                    tmpCul.push_back(tmp);
                    m[tmp]=1;
                }
                else{
                    break;
                }
            }
            for(k=0;k<tmpCul.size();k++){
                cul[tmpCul[k]]=1;
            }
            cul[coins[j]]=1;
        }
        tmp=total/2;
        if(m[tmp]==1){
            if(total%2==0){
                puts("0");
            }
            else{
                puts("1");
            }
        }
        else{
            for(j=1;j<=total/2;j++){
                if(m[tmp+j]==1){
                    printf("%d\n",2*tmp+2*j-total);
                    break;
                }
                if(m[tmp-j]==1){
                    printf("%d\n",total-2*tmp+2*j);
                    break;
                }
            }
        }
        m.clear();
        cul.clear();
        coins.clear();
    }
    return 0;
}
