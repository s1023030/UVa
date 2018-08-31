#include<vector>
#include<map>
#include<cstdio>
#include<cmath>
using namespace std;
vector<map<int,int> >primeList;
vector<int>prime;
vector<int>input;
bool Pl[46341];
int loca[46341];
int main(){
    map<int,int>tmpPl;
    vector<map<int,int> >tmpPL;
    int i,j,tmpInt,in,lo=0;
    map<int,int>::iterator tmpMapIt;
    for(i=0;i<=46340;i++){
        primeList.push_back(tmpPl);
        Pl[i]=true;
    }
    primeList[1].insert(pair<int,int>(1,1));
    prime.push_back(0);
    for(i=2;i<=46340;i++){
        loca[i]=lo;
        if(Pl[i]){
            lo++;
            loca[i]=lo;
            prime.push_back(i);
            primeList[i].insert(pair<int,int>(i,1));
        }
        for(j=1;j<prime.size();j++){
            tmpInt=i*prime[j];
            if(tmpInt<=46340){
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
            if(i%prime[j]==0){
                break;
            }
        }
    }
    while(scanf("%d",&in)&&in!=0){
        printf("%d =",in);
        if(in<0){
            printf(" -1 x");
            in=-in;
        }
        if(in<=46340){
            if(tmpPl.size()>0){
                tmpPl.clear();
            }
            tmpPl=primeList[in];
        }
        else{
            if(tmpPl.size()>0){
                tmpPl.clear();
            }
            if(tmpPL.size()>0){
                for(i=0;i<tmpPL.size();i++){
                    if(tmpPL[i].size()>0){
                        tmpPL[i].clear();
                    }
                }
                tmpPL.clear();
            }
            bigger:;
            tmpInt=sqrt(in);
            for(i=tmpInt;i>=2;i--){
                if(in%i==0){
                    tmpPL.push_back(primeList[i]);
                    if(in/i>46340){
                        in=in/i;
                        goto bigger;
                    }
                    tmpPl=primeList[in/i];
                    goto have;
                }
            }
            tmpPl[in]=1;
            have:;
            for(i=0;i<tmpPL.size();i++){
                for(tmpMapIt=tmpPL[i].begin();tmpMapIt!=tmpPL[i].end();tmpMapIt++){
                    if(tmpPl.count(tmpMapIt->first)){
                        tmpPl[tmpMapIt->first]+=tmpMapIt->second;
                    }
                    else{
                        tmpPl[tmpMapIt->first]=tmpMapIt->second;
                    }
                }
            }
        }
        tmpMapIt=tmpPl.begin();
        printf(" %d",tmpMapIt->first);
        tmpMapIt->second--;
        for(;tmpMapIt!=tmpPl.end();tmpMapIt++){
            for(i=1;i<=tmpMapIt->second;i++){
                printf(" x %d",tmpMapIt->first);
            }
        }
        printf("\n");
    }
    return 0;
}
