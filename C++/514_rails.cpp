#include<vector>
#include<cstdio>
#include<map>
#include<stack>
using namespace std;
int main(){
    int input[1001],endd[1001];
    stack<int>store;
    map<int,bool>stackExist;
    int i,total,at;
    bool jump;
    for(i=1;i<=1000;i++){
        input[i]=i;
    }
    while(scanf("%d",&total)&&total!=0){
        while(1){
            jump=false;
            for(i=1;i<=total;i++){
                scanf("%d",&endd[i]);
                if(i==1&&endd[i]==0){
                    jump=true;
                    break;
                }
            }
            if(jump){
                break;
            }
            at=1;
            jump=true;
            for(i=1;i<=total;i++){
                if(store.size()>0&&store.top()==endd[i]){//find
                    store.pop();
                    continue;
                }
                else if(stackExist.count(endd[i])==1){//No
                    printf("NO\n");
                    jump=false;
                    break;
                }
                while(at<=total){
                    if(endd[i]==input[at]){//find
                        at++;
                        break;
                    }
                    else{
                        store.push(input[at]);
                        stackExist[input[at]]=1;
                        at++;
                    }
                }
            }
            if(jump){
                printf("YES\n");
            }
            while(!store.empty()){
                store.pop();
            }
            stackExist.clear();

        }
    }
    return 0;
}
