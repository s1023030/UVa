#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<cstring>
#include<vector>
#include<cctype>
#include<sstream>
using namespace std;
struct problem{
    vector<string>str;
   //map<string,int>str;
   int dist;
   vector<int>answer;
};
vector<problem>problemSet;
char  line[100];
map<string,vector<int> >stp;
int main(){
    vector<int>v1,v2;
    problem tmpPr;
    char one[100],*two;
    char del='*',nul='\0';
    int test=1,i,j,k,l,m,n,number=0,tmpInt;
    string mode,tmpStr1,tmpStr2;
    vector<int>tmpVector;
    while(cin>>mode){
        if(mode[0]=='T'){
            break;
        }
        gets(line);
        stringstream sin(line);
        sin>>tmpPr.dist;
        while(sin>>mode){
            //tmpPr.str[mode];
            tmpPr.str.push_back(mode);
        }
        problemSet.push_back(tmpPr);
        tmpPr.str.clear();
    }
    while(gets(line)){
        if(line[0]=='T'){
            for(j=0;j<problemSet.size();j++){
                for(k=0;k<problemSet[j].str.size()-1;k++){
                    if(stp.count(problemSet[j].str[k])>0){
                        for(l=k+1;l<problemSet[j].str.size();l++){
                            if(stp.count(problemSet[j].str[l])>0){
                                v1=stp[problemSet[j].str[k]];
                                v2=stp[problemSet[j].str[l]];
                                for(m=0;m<v1.size();m++){
                                    for(n=0;n<v2.size();n++){
                                        tmpInt=v1[m]-v2[n];
                                        if(tmpInt<0){tmpInt*=(-1);}
                                        tmpInt--;
                                        if(tmpInt>=0&&tmpInt<=problemSet[j].dist){
                                            problemSet[j].answer.push_back(test);
                                            goto YES;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                YES:;
            }
            test++;
            stp.clear();
            number=0;
        }
        else if(line[0]=='#'){
            for(j=0;j<problemSet.size();j++){
                for(k=0;k<problemSet[j].str.size()-1;k++){
                    if(stp.count(problemSet[j].str[k])>0){
                        for(l=k+1;l<problemSet[j].str.size();l++){
                            if(stp.count(problemSet[j].str[l])>0){
                                v1=stp[problemSet[j].str[k]];
                                v2=stp[problemSet[j].str[l]];
                                for(m=0;m<v1.size();m++){
                                    for(n=0;n<v2.size();n++){
                                        tmpInt=v1[m]-v2[n];
                                        if(tmpInt<0){tmpInt*=(-1);}
                                        tmpInt--;
                                        if(tmpInt>=0&&tmpInt<=problemSet[j].dist){
                                            problemSet[j].answer.push_back(test);
                                            goto YES2;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                YES2:;
            }
            break;
        }
        line[0]=' ';
        for(i=1;i<strlen(line);i++){
            if(isupper(line[i])){
                line[i]+=32;
            }
            else if(!islower(line[i])&&line[i]!=' '){
                del=line[i];
                if(i==strlen(line)-1){
                    line[i]=' ';
                }
                else{
                    strcpy(one,"");
                    strncat(one,line,i);
                    strcat(one,&line[i+1]);
                    strcat(one,&nul);
                    strcpy(line, one);
                    i--;
                }
            }
        }
        stringstream sin1(line);
        while(sin1>>tmpStr1){
           if(stp.count(tmpStr1)>0){
               stp[tmpStr1].push_back(number);
           }
           else{
               stp[tmpStr1]=tmpVector;
               stp[tmpStr1].push_back(number);
           }
           number++;
        }
    }
    for(i=0;i<problemSet.size();i++){
        cout<<i+1<<": ";
        if(problemSet[i].answer.size()>0){
            cout<<problemSet[i].answer[0];
            for(j=1;j<problemSet[i].answer.size();j++){
                cout<<","<<problemSet[i].answer[j];
            }
        }
        cout<<endl;
    }
    return 0;
}
