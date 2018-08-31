#include<iostream>
#include<string>
using namespace std;
struct phoneNumber{
    phoneNumber *next[10];
    int cnt;
    bool endd;
    phoneNumber(){
        endd=false;
        cnt=0;
        for(int i=0;i<10;i++){
            next[i]=NULL;
        }
    }
};
phoneNumber *store[1000000];
int main(){
    int caseN,phoneN,i,j,k,c,total;
    bool Yes;
    phoneNumber *now;
    string tempString;
    cin>>caseN;cin.get();
    for(i=1;i<=caseN;i++){
        cin>>phoneN;
        total=-1;
        Yes=false;
        for(j=1;j<=phoneN;j++){
            cin>>tempString;cin.get();
            if(!Yes){
                if(store[0]==NULL){
                    store[0]=new phoneNumber();
                    now=store[0];
                    total++;
                }
                else{
                    now=store[0];
                }
                for(k=0;k<tempString.length();k++){
                    c=(int)tempString[k]-'0';
                    if(now->next[c]==NULL){
                        store[++total]=new phoneNumber();
                        now->next[c]=store[total];
                        now->cnt++;
                        now=now->next[c];
                    }
                    else{
                        now->cnt++;
                        now=now->next[c];
                    }
                    if(now->endd){
                        Yes=true;
                        break;
                    }
                    if(k==tempString.length()-1){
                        if(now->cnt>0){
                            Yes=true;
                        }
                        now->endd=true;
                    }
                }
            }
        }
        if(Yes){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
        for(j=total;j>=0;j--){
            delete store[j];
        }
        store[0]=NULL;
        now=NULL;
    }
    return 0;
}
