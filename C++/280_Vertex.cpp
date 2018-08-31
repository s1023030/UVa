#include<cstdio>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int main(){
    map<int,bool>visisted;
    map<int,vector<int> >graph;
    vector<int>tempGraph;
    queue<int>myQueue;
    int nodeN,i,j,k,startV,tempInt,tempInt1,startN;
    while(~scanf("%d",&nodeN)&&nodeN!=0){
        tempGraph.clear();
        for(i=1;i<=nodeN;i++){
            graph[i]=tempGraph;
            visisted[i]=false;
        }
        while(~scanf("%d",&tempInt)&&tempInt!=0){
            while(~scanf("%d",&tempInt1)&&tempInt1!=0){
                graph[tempInt].push_back(tempInt1);
            }
        }
        scanf("%d",&startN);
        for(i=1;i<=startN;i++){
            scanf("%d",&startV);
            tempInt1=nodeN;
            myQueue.push(startV);
            while(myQueue.size()>0){
                tempInt=myQueue.front();
                myQueue.pop();
                tempGraph=graph[tempInt];
                for(j=0;j<tempGraph.size();j++){
                    if(!visisted[tempGraph[j]]){
                        myQueue.push(tempGraph[j]);
                        visisted[tempGraph[j]]=true;
                        tempInt1--;
                    }
                }
            }
            printf("%d",tempInt1);
            for(map<int,bool>::iterator it=visisted.begin();it!=visisted.end();it++){
                if(!(it->second)){
                    printf(" %d",it->first);
                }
                else{
                    visisted[it->first]=false;
                }
            }
            printf("\n");
        }
        visisted.clear();
        graph.clear();

    }
    return 0;
}
