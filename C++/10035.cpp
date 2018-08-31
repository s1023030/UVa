#include<cstdio>
//#include<fstream>
using namespace std;
int main(){
    long long aa,bb,answer,add,carry;
    //ofstream fout("out.txt");
    while(~scanf("%lld%lld",&aa,&bb)&&(aa!=0||bb!=0)){
        answer=0;
        carry=0;
        while(1){
            add=(aa%10)+(bb%10)+carry;
            if(add>=10){
                carry=1;
                answer++;
            }
            else{
                carry=0;
            }
            aa=aa/10;
            bb=bb/10;
            if(aa==0&&bb==0){
                break;
            }
        }
        if(answer==0){
            printf("No carry operation.\n");
            //fout<<"No carry operation.\n";
        }
        else if(answer==1){
            printf("%lld carry operation.\n",answer);
           // fout<<answer<<" carry operation.\n";
        }
        else{
              printf("%lld carry operations.\n",answer);
              //fout<<answer<<" carry operations.\n";
        }
    }
   // fout.close();
    return 0;
}
