#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
//#include<cstdio>
using namespace std;
int len;
struct str{
    string s;
    int uo;
};
vector<str>store;
map<char,int>table;
bool compare(const str a,const str b){
  return a.uo<b.uo;
}
int main(){
    //freopen("out.txt","w",stdout);
    int caseN,i,j,k,l,num;
    str tmpStr;
    tmpStr.uo=0;
    table['A']=1;
    table['C']=2;
    table['G']=3;
    table['T']=4;
    cin>>caseN;
    for(i=1;i<=caseN;i++){
        if(i>1){
            cout<<endl;
        }
        cin>>len>>num;
        for(j=1;j<=num;j++){
            cin>>tmpStr.s;
            store.push_back(tmpStr);
        }
        for(j=0;j<num;j++){
             for(k=0;k<len-1;k++){
                for(l=k+1;l<len;l++){
                    if(table[store[j].s[k]]>table[store[j].s[l]]){
                        store[j].uo++;
                    }
                }
            }
        }
         stable_sort(&store[0],&store[0]+num,compare);
        for(j=0;j<num;j++){
            cout<<store[j].s<<endl;
        }
        store.clear();
    }
    return 0;
}
