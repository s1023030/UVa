#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
map<string,int>StI;
map<int,string>ItS;
vector<int>indegree;
vector<vector<int> >graph;
vector<int>tmpG;
vector<int>process;
bool compare(int aa,int bb){
    return aa>bb;
}
int main(){
    int nodeN,linkN,i,j,kase=1;
    string tmpStr1,tmpStr2,answer;
    while(cin>>nodeN){
        answer="";
        for(i=0;i<nodeN;i++){
            cin>>tmpStr1;
            StI[tmpStr1]=i;
            ItS[i]=tmpStr1;
            indegree.push_back(0);
            graph.push_back(tmpG);
        }
        cin>>linkN;
        for(i=0;i<linkN;i++){
            cin>>tmpStr1>>tmpStr2;
            indegree[StI[tmpStr2]]++;
            graph[StI[tmpStr1]].push_back(StI[tmpStr2]);
        }
        for(i=0;i<nodeN;i++){
            if(indegree[i]==0){
                process.push_back(i);
            }
        }
        while(process.size()>0){
            if(process.size()>1){
                sort(&process[0],&process[0]+process.size(),compare);
            }
            j=process.back();
            process.pop_back();
            answer+=" "+ItS[j];
            for(i=0;i<graph[j].size();i++){
                indegree[graph[j][i]]--;
                if(indegree[graph[j][i]]==0){
                    process.push_back(graph[j][i]);
                }
            }
        }
        cout<<"Case #"<<kase<<": Dilbert should drink beverages in this order:"<<answer<<"."<<endl<<endl;
        StI.clear();
        ItS.clear();
        indegree.clear();
        graph.clear();
        kase++;
    }
    return 0;
}
