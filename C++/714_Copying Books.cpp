#include<cstdio>
#include<vector>
using namespace std;
vector<int>book;
vector<int>ans;

int main(){
    book.push_back(0);
    int caseN,bookN,peopleN,tmpInt,i,j,group;
    long long int left,bound,mid,sum;
    scanf("%d",&caseN);
    for(i=1;i<=caseN;i++){
        scanf("%d%d",&bookN,&peopleN);
        left=0;
        bound=0;
        for(j=1;j<=bookN;j++){
            scanf("%d",&tmpInt);
            if(tmpInt>left){
                left=tmpInt;
            }
            bound+=tmpInt;
            book.push_back(tmpInt);
        }
        bound=bound-left;
        while(bound>0){
            sum=0;
            group=0;
            mid=left+bound/2;
            for(j=bookN;j>=1;j--){
                if(sum+book[j]>mid){
                    group++;
                    sum=0;
                }
                sum+=book[j];
            }
            group++;
            if(group>peopleN){
                left=left+(bound/2)+1;
                bound=bound/2;
            }
            else{
                bound=bound/2;
            }
        }
        sum=0;
        group=peopleN;
        for(j=bookN;j>=1;j--){
            if(sum+book[j]>left||j<group){
                ans.push_back(-100);
                group--;
                sum=0;
            }
            ans.push_back(book[j]);
            sum+=book[j];
        }
        printf("%d",ans[ans.size()-1]);
        for(j=ans.size()-2;j>=0;j--){
            if(ans[j]==-100){
                printf(" /");
            }
            else{
                printf(" %d",ans[j]);
            }
        }
        puts("");
        ans.clear();
        book.resize(1);
    }
    return 0;
}
