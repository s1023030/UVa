#include<cstdio>
#include<deque>
using namespace std;
int main(){
    int cardN,i;
    deque<int>deck;
    while(scanf("%d",&cardN)&&cardN!=0){
        for(i=1;i<=cardN;i++){
            deck.push_front(i);
        }
        printf("Discarded cards:");
        while(deck.size()>=2){
            printf(" %d",deck.back());
            deck.pop_back();
            if(deck.size()==1){
                break;
            }
            else{
                printf(",");
            }
            deck.push_front(deck.back());
            deck.pop_back();
        }
        printf("\n");
        printf("Remaining card: %d\n",deck.back());
        deck.clear();
    }
    return 0;
}
