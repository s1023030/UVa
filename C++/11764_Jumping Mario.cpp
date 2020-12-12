#include<iostream>
using namespace std;
int main(){
    int testCase=0;
    int numWall =0;
    int tmpNum1=0,tmpNum2=0;
    cin>>testCase;cin.get();
    for(int i=0;i<testCase;i++){
        int highJump=0,lowJump=0;
        cin>>numWall;cin.get();
        for(int j=0;j<numWall;j++){
            cin>>tmpNum1;
            if(j>0){
                if(tmpNum1>tmpNum2){
                    highJump ++;
                }
                else if(tmpNum1<tmpNum2){
                    lowJump ++;
                }
            }
            tmpNum2 = tmpNum1;
        }
        cout<<"Case "<<(i+1)<<": "<<highJump<<" "<<lowJump<<endl;
    }
    return 0;
}
