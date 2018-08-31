#include<cstdio>
#include<cstring>
using namespace std;
char input[10000];
int main(){
    int i;
    while(gets(input)){
        for(i=0;i<strlen(input);i++){
            printf("%c",input[i]-7);
        }
        puts("");
    }
    return 0;
}
