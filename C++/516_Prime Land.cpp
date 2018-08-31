#include<vector>
#include<map>
#include<cstdio>
#include<cstring>
using namespace std;
vector<map<int,int> >primeList;
vector<int>prime;
vector<int>input;
bool Pl[32768];
map<int,int>tmpPl;
int main(){
    int i,j,tmpInt,up,ten;
    char in[100];
    map<int,int>::iterator tmpMapIt;
    for(i=0;i<=32767;i++){
        primeList.push_back(tmpPl);
        Pl[i]=true;
    }
    primeList[1].insert(pair<int,int>(1,1));
    for(i=2;i<=32767;i++){
        if(Pl[i]){
            prime.push_back(i);
            primeList[i].insert(pair<int,int>(i,1));
        }
        for(j=0;j<prime.size();j++){
                tmpInt=i*prime[j];
                if(tmpInt<=32767){
                    Pl[tmpInt]=false;
                    if(primeList[i].count(prime[j])>0){
                        primeList[tmpInt]=primeList[i];
                        primeList[tmpInt][prime[j]]++;
                    }
                    else{
                        primeList[tmpInt]=primeList[i];
                        primeList[tmpInt].insert(pair<int,int>(prime[j],1));
                    }
                }
                else{
                    break;
                }
            }
    }
    while(gets(in)){
        if(in[0]=='0'){
            break;
        }
        up=0;
        if(input.size()>0){
            input.clear();
        }
        for(i=0;i<=strlen(in);i++){
            if(in[i]<'0'||in[i]>'9'){
                tmpInt=0;
                ten=1;
                for(j=i-1;j>=up;j--,ten=ten*10){
                    tmpInt+=(in[j]-'0')*ten;
                }
                up=i+1;
                input.push_back(tmpInt);
            }
        }
        tmpInt=1;
        for(i=0;i<input.size();i+=2){
            for(j=1;j<=input[i+1];j++){
                tmpInt*=input[i];
            }
        }
        tmpInt--;
        tmpMapIt=primeList[tmpInt].end();
        do{
            tmpMapIt--;
            printf("%d %d",tmpMapIt->first,tmpMapIt->second);
            if(tmpMapIt!=primeList[tmpInt].begin()){
                printf(" ");
            }
        }while(tmpMapIt!=primeList[tmpInt].begin());
        printf("\n");
    }
    return 0;
}
