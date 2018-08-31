#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
vector<int>store;
vector<int>tmpV;
vector<vector<int> >V;
map<int,vector<vector<int> > >table;
int main(){
    //freopen("out.txt","w",stdout);
    int numN,i,j,k,tmpInt;
    while(scanf("%d",&numN)){
        if(numN==0){
            break;
        }
        for(i=1;i<=numN;i++){
            scanf("%d",&tmpInt);
            store.push_back(tmpInt);
        }
        sort(&store[0],&store[0]+numN);
        for(i=0;i<numN-1;i++){
            for(j=i+1;j<numN;j++){
                tmpInt=store[i]+store[j];
                tmpV.push_back(i);
                tmpV.push_back(j);
                table[tmpInt]=V;
                table[tmpInt].push_back(tmpV);
                tmpV.clear();
            }
        }
        for(i=numN-1;i>0;i--){
            for(j=0;j<numN;j++){
                tmpInt=store[i]-store[j];
                if(i!=j&&table.count(tmpInt)>0){
                    for(k=0;k<table[tmpInt].size();k++){
                        if(table[tmpInt][k][0]!=i&&table[tmpInt][k][1]!=i&&table[tmpInt][k][0]!=j&&table[tmpInt][k][1]!=j){
                            printf("%d\n",store[i]);
                            goto jump;
                        }
                    }
                }
            }
        }
        puts("no solution");
        jump:;
        table.clear();
        store.clear();
    }
    return 0;
}
