#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cctype>
#include<map>
#include<cmath>
#include<sstream>
using namespace std;
char line[1000];
char word[20];
map<string,int>exist;
int main(){
    map<string,int>::iterator it;
    int i,total=0;
    double Et,Emax,Erel,pi;
    string tmpStr;
    while(gets(line)){
        if(strcmp(line,"****END_OF_INPUT****")==0){
            break;
        }
        else if(strcmp(line,"****END_OF_TEXT****")==0){
            Et=0;
            Emax=log10(total);
            for(it=exist.begin();it!=exist.end();it++){
                Et+=it->second*(Emax-log10(it->second));
            }
            Et=Et/total;
            Erel=Et/Emax;
            printf("%d %.1lf %.0lf\n",total,Et,Erel*100);
            total=0;
            exist.clear();
            continue;
        }
        for(i=0;i<strlen(line);i++){
            if(isupper(line[i])){
                line[i]+=32;
            }
            else if(line[i]==','||line[i]=='.'||line[i]==':'||line[i]==';'||line[i]=='!'||line[i]=='?'||line[i]=='"'||line[i]=='('||line[i]==')'){
                line[i]=' ';
            }
        }
        stringstream in(line);
        while(in>>tmpStr){
            total++;
            if(exist.count(tmpStr)==0){
                exist[tmpStr]=1;
            }
            else{
                exist[tmpStr]++;
            }
        }
    }
    return 0;
}
