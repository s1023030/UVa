#include<cstdio>
#include<vector>
using namespace std;
vector<vector<int> >number;
vector<int>tmpNumber;
int main(){
    int n,i,j,l,div,six0=1000000;
    int k;//
    tmpNumber.push_back(1);
    number.push_back(tmpNumber);
    number.push_back(tmpNumber);
    for(k=2;k<=1000;k++){
        number.push_back(tmpNumber);
        for(j=number[k].size()-1;j>=0;j--){
            number[k][j]*=k;
            div=number[k][j]/six0;
            if(div>0){//6
                number[k][j]=number[k][j]%six0;
                if(j==number[k].size()-1){
                    number[k].push_back(div);
                }
                else{
                    l=j+1;
                    number[k][l]+=div;
                    div=number[k][l]/six0;
                    while(div>0){
                        number[k][l]=number[k][l]%six0;
                        l++;
                        if(l==number[k].size()){
                            number[k].push_back(div);
                        }
                        else{
                            number[k][l]+=div;
                        }
                        div=number[k][l]/six0;
                    }
                }
            }
        }
        tmpNumber=number[k];
    }
    while(~scanf("%d",&n)){
        printf("%d!\n%d",n,number[n][number[n].size()-1]);
        for(j=number[n].size()-2;j>=0;j--){
            printf("%06d",number[n][j]);
        }
        printf("\n");
    }
    return 0;
}
