#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;
struct dest
{
    char name[31];
    vector<int>reach;
};
map<string,int>trans;
vector<int>answer;
stack<int>DFSP;
dest store[101];
char visit[101];
void DFS(int n,int forb)
{
    DFSP.push(n);
    visit[n]=1;
    int i,tmp;
    while(DFSP.size()>0)
    {
        n=DFSP.top();
        DFSP.pop();
        for(i=0; i<store[n].reach.size(); i++)
        {
            tmp=store[n].reach[i];
            if(!visit[tmp]&&tmp!=forb)
            {
                DFSP.push(tmp);
                visit[tmp]=1;
            }
        }
    }
}
bool compare(int a,int b){
    for(int i=0;i<30;i++){
        if(store[a].name[i]<store[b].name[i]){
            return true;
        }
        else if(store[a].name[i]>store[b].name[i]){
            return false;
        }
    }
}
int main()
{
    int desN,conectN,i,j,ori,comp,kase=1;
    char tmpS1[31],tmpS2[31];
    string middle1,middle2;
    while(scanf("%d",&desN)&&desN!=0)
    {
        if(kase>1)
        {
            puts("");
        }
        for(i=0; i<desN; i++)
        {
            if(store[i].reach.size()>0){
                store[i].reach.clear();
            }
            scanf("%s",&store[i].name);
            middle1.assign(store[i].name);
            trans[middle1]=i;
            visit[i]=0;
        }
        scanf("%d",&conectN);
        for(i=0; i<conectN; i++)
        {
            scanf("%s%s",&tmpS1,&tmpS2);
            middle1.assign(tmpS1);
            middle2.assign(tmpS2);
            store[trans[middle1]].reach.push_back(trans[middle2]);
            store[trans[middle2]].reach.push_back(trans[middle1]);
        }
        ori=0;
        comp=0;
        for(i=0; i<desN; i++)
        {
            if(!visit[i])
            {
                DFS(i,-1);
                ori++;
            }
        }
        for(j=0; j<desN; j++)
        {
            memset(visit,0,desN);
            comp=0;
            for(i=0; i<desN; i++)
            {
                if(!visit[i]&&i!=j)
                {
                    DFS(i,j);
                    comp++;
                }
            }
            if(comp>ori)
            {
                answer.push_back(j);
            }
        }
        sort(&answer[0],&answer[0]+answer.size(),compare);
        printf("City map #%d: %d camera(s) found\n",kase,answer.size());
        for(i=0; i<answer.size(); i++)
        {
            printf("%s\n",store[answer[i]].name);
        }
        kase++;
        answer.clear();
        trans.clear();
    }
    return 0;
}
/*
6
sugarloaf
maracana
copacabana
ipanema
corcovado
lapa
7
ipanema copacabana
copacabana sugarloaf
ipanema sugarloaf
maracana lapa
sugarloaf maracana
corcovado sugarloaf
lapa corcovado
5
guanabarabay
downtown
botanicgarden
colombo
sambodromo
4
guanabarabay sambodromo
downtown sambodromo
sambodromo botanicgarden
colombo sambodromo
*/
/*
#include<iostream>
using namespace std;
int main(){
    string test_string="test_string";
    char test_char[]="test_char", result_char[20];

    string result_string1(test_char);
    string result_string2;
    result_string2.assign(test_char);
    strcpy(result_char, test_string.c_str());

    cout<<"test_string: "<<test_string<<endl;
    cout<<"test_char: "<<test_char<<endl;
    cout<<"result_string1: "<<result_string1<<endl;
    cout<<"result_string2: "<<result_string2<<endl;
    cout<<"result_char: "<<result_char<<endl;

    system("pause");
    return EXIT_SUCCESS;
}
*/
