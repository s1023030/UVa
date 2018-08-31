#include<cstdio>
#include<vector>
using namespace std;
int main(){
    int up,down,q,i;
    vector<int>answer;
    while(~scanf("%d%d",&up,&down)&&down!=0){
        while(1){
            q=up/down;
            answer.push_back(q);
            up-=q*down;
            if(down%up==0){
                down/=up;
                up/=up;
            }
            if(up==1){
                answer.push_back(down);
                break;
            }
            q=up;
            up=down;
            down=q;
        }
        printf("[");
        for(i=0;i<answer.size();i++){
            printf("%d",answer[i]);
            if(i==0){
                printf(";");
            }
            else if(i==answer.size()-1){
                printf("]\n");
            }
            else{
                printf(",");
            }
        }
        answer.clear();
    }
    return 0;
}
