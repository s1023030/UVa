#include<cstdio>
#include<cctype>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
struct cha{
    char c;
    int time;
};
char input[150];
cha store[26];
map<int,int>Csize;
bool compare(cha a,cha b){
    return a.time>b.time;
}
int main(){
   // freopen("out.txt","w",stdout);
    int i,j,lineN;
    for(i=0;i<26;i++){
        store[i].c='A'+i;
        store[i].time=0;
    }
    char tmp;
    scanf("%d%c",&lineN,&tmp);
    for(i=1;i<=lineN;i++){
        gets(input);
        for(j=0;j<strlen(input);j++){
            if(isupper(input[j])){
                store[input[j]-'A'].time++;
                Csize[input[j]-'A']=1;
            }
            else if(islower(input[j])){//-32
                store[input[j]-'a'].time++;
                Csize[input[j]-'a']=1;
            }
        }
    }
    stable_sort(store,store+26,compare);
    for(i=0;i<Csize.size();i++){
        printf("%c %d\n",store[i].c,store[i].time);
    }
    return 0;
}
