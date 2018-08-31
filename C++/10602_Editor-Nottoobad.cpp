#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
struct word{
    char str[101];
    int len;
    int diff;
};
vector<word>store;
int main(){
    int caseN,wordN,i,j,k,l,m,answer=0,sameMax;
    word wordTmp;
    scanf("%d",&caseN);
    for(i=1;i<=caseN;i++){
        scanf("%d",&wordN);
        for(j=1;j<=wordN;j++){
            scanf("%s",wordTmp.str);
            wordTmp.len=strlen(wordTmp.str);
            store.push_back(wordTmp);
        }
        answer+=store[0].len;
        for(j=0;j<wordN-1;j++){
            sameMax=-1;
            for(k=j+1;k<wordN;k++){
                if(store[j].len>store[k].len){
                    for(l=0;l<store[k].len;l++){
                        if(store[k].str[l]!=store[j].str[l]){
                            break;
                        }
                    }
                    store[k].diff=store[k].len-l;
                }
                else{
                    for(l=0;l<store[j].len;l++){
                        if(store[k].str[l]!=store[j].str[l]){
                            break;
                        }
                    }
                    store[k].diff=store[k].len-l;
                }
                if(l>sameMax){
                    sameMax=l;
                    m=k;
                }
            }
            answer+=store[m].diff;
            wordTmp=store[m];
            store[m]=store[j+1];
            store[j+1]=wordTmp;

        }
        printf("%d\n",answer);
        for(j=0;j<wordN;j++){
            puts(store[j].str);
        }
        answer=0;
        store.clear();
    }
    return 0;
}
