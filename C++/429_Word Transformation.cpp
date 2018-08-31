#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<map>
using namespace std;

map<string,int>ind;

vector<vector<int> >dict;
vector<int>tmpDict;

vector<vector<string> >L;
vector<string>tmpL;
queue<int>process;
int visit[200];
bool compare(string a,string b){
    int same=0;
    for(int i=0;i<a.length();i++){
        if(a[i]!=b[i]){
            same++;
            if(same==2){
                return false;
            }
        }
    }
    if(same==0){
        return false;
    }
    return true;
}
int main(){
    int caseN,i,j,tmp,tmp1,tmp2,num;
    char input[30];
    char now[11],dest[11];
    string tmpS,tmpS1;
    for(i=0;i<=10;i++){
        L.push_back(tmpL);
    }
    scanf("%d",&caseN);
    for(i=1;i<=caseN;i++){
        num=0;
        while(scanf("%s",input)){
            tmp=strlen(input);
            if(tmp==1&&input[0]=='*'){
                break;
            }
            else{
                tmpS.assign(input);
                ind[tmpS]=num;
                dict.push_back(tmpDict);
                for(j=0;j<L[tmp].size();j++){
                    tmpS1=L[tmp][j];
                    if(compare(tmpS,tmpS1)){
                        dict[ind[tmpS1]].push_back(num);
                        dict[num].push_back(ind[tmpS1]);
                    }
                }
                L[tmp].push_back(tmpS);
                num++;
            }
        }gets(input);
        while(gets(input)){

            if(strlen(input)==0){
                break;
            }
            memset(visit,0,sizeof(visit));
            sscanf(input,"%s%s",now,dest);
            tmp=ind[now];
            tmp1=ind[dest];
            visit[tmp]++;
            process.push(tmp);
            while(process.size()>0){
                tmp=process.front();
                process.pop();
                if(tmp==tmp1){
                    printf("%s %s %d\n",now,dest,(int)(visit[tmp]-1));
                    break;
                }
                for(j=0;j<dict[tmp].size();j++){
                    if(visit[dict[tmp][j]]==0){
                        visit[dict[tmp][j]]=visit[tmp]+1;
                        process.push(dict[tmp][j]);
                    }
                }
            }
            while(process.size()>0){
                process.pop();
            }
        }
        if(i<caseN){
            puts("");
        }
        for(j=0;j<=10;j++){
            L[j].clear();
        }
        for(j=0;j<dict.size();j++){
            dict[j].clear();
        }
        dict.clear();
        ind.clear();
    }
    return 0;
}
