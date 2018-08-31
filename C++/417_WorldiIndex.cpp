#include<map>
#include<string>
#include<iostream>
using namespace std;
map<string,int>index;
int main(){
    char key[6];
    int number[5],Count=1,PL=0;
    int i,j,k,tempInt;
    for(i=0;i<6;i++){
        number[i]=0;
    }
    key[PL+1]='\0';
    number[0]=97;
    while(1){
        key[PL]=(char)number[PL];
        index[key]=Count;
        if(Count==83681){
            break;
        }
        Count++;
        number[PL]++;
        if(number[PL]==123){
            for(j=PL;j>=0;j--){
                if(j==0){
                    PL++;
                    key[PL+1]='\0';
                    for(k=0;k<=PL;k++){
                        number[k]=97+k;
                        key[k]=(char)number[k];
                    }
                }
                else{
                    number[j-1]++;
                    key[j-1]=(char)number[j-1];
                    if(number[j-1]!=number[j]-1){
                        for(k=j;k<=PL;k++){
                            number[k]=number[j-1]+k-j+1;
                            key[k]=(char)number[k];
                        }
                        break;
                    }
                }
            }
        }
    }
    while(cin.getline(key,6)){
        if(index.count(key)>0){
            cout<<index[key]<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}
