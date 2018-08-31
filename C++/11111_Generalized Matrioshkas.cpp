#include<stack>
#include<cstdio>
using namespace std;
struct Matrio{
    int number;
    int ac;
};
stack<Matrio> store;
int main(){
    int tmpInt,tmpTop;
    Matrio tmpM;
    char tmpChar;
    bool ansFal=true;
    while(~scanf("%d%c",&tmpInt,&tmpChar)){
        if(!ansFal){
            goto ansFALSE;
        }
        if(store.size()==0){
            if(tmpInt<0){
                tmpM.number=tmpInt;
                tmpM.ac=-tmpInt;
                store.push(tmpM);
            }
            else{
                ansFal=false;
            }
        }
        else{
            tmpM=store.top();
            if(tmpInt<0){
                tmpM.ac+=tmpInt;
                if(tmpM.ac<=0){//false
                    ansFal=false;
                }
                else{
                    store.pop();
                    store.push(tmpM);
                    tmpM.number=tmpInt;
                    tmpM.ac=-tmpInt;
                    store.push(tmpM);
                }
            }
            else{
                if(tmpInt==-tmpM.number){
                    store.pop();
                }
                else{//false
                    ansFal=false;
                }
            }
        }
        ansFALSE:;
        if(tmpChar=='\n'){
            if(!ansFal){
                printf(":-( Try again.\n");
                ansFal=true;
            }
            else if(store.size()>0){
                printf(":-( Try again.\n");
                ansFal=true;
            }
            else{
                printf(":-) Matrioshka!\n");
            }
            while(store.size()>0){
                store.pop();
            }
        }
    }
    return 0;
}
