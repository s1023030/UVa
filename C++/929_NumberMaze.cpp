#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
struct point{
    int value,d,row,col;
    bool visit,left,right,up,down;
};
bool operator<(const point& a,const point& b){
    return (a.d>b.d);
}
point maze[999][999];
int main(){
    priority_queue<point>myQueue;
    point temp_point;
    int testN,row,col,i,j,k,tempInt,atr,atc,atd;
    scanf("%d",&testN);
    for(i=1;i<=testN;i++){
        scanf("%d",&row);
        scanf("%d",&col);
        for(j=0;j<row;j++){
            for(k=0;k<col;k++){
                scanf("%d",&maze[j][k].value);
                maze[j][k].visit=false;
                maze[j][k].d=0x3FFFFFFF;
                maze[j][k].row=j;
                maze[j][k].col=k;
                if(j==0){
                    maze[j][k].up=false;
                    maze[j][k].down=true;
                }
                else if(j==row-1){
                    maze[j][k].down=false;
                    maze[j][k].up=true;
                }
                else{
                    maze[j][k].down=true;
                    maze[j][k].up=true;
                }
                if(k==0){
                    maze[j][k].left=false;
                    maze[j][k].right=true;
                }
                else if(k==col-1){
                    maze[j][k].right=false;
                    maze[j][k].left=true;
                }
                else{
                    maze[j][k].right=true;
                    maze[j][k].left=true;
                }
            }
        }
        maze[0][0].d=maze[0][0].value;
        maze[0][0].visit=true;
        myQueue.push(maze[0][0]);
        while(myQueue.size()>0){
            temp_point=myQueue.top();
            myQueue.pop();
            atr=temp_point.row;
            atc=temp_point.col;
            atd=temp_point.d;
            maze[atr][atc].visit=true;
            if(atr==row-1&&atc==col-1){
                break;
            }
            if(temp_point.up){
                if(!maze[atr-1][atc].visit&&atd+maze[atr-1][atc].value<maze[atr-1][atc].d){
                    maze[atr-1][atc].d=atd+maze[atr-1][atc].value;
                    myQueue.push(maze[atr-1][atc]);
                }
            }
            if(temp_point.down){
                if(!maze[atr+1][atc].visit&&atd+maze[atr+1][atc].value<maze[atr+1][atc].d){
                    maze[atr+1][atc].d=atd+maze[atr+1][atc].value;
                    myQueue.push(maze[atr+1][atc]);
                }
            }
            if(temp_point.left){
                if(!maze[atr][atc-1].visit&&atd+maze[atr][atc-1].value<maze[atr][atc-1].d){
                    maze[atr][atc-1].d=atd+maze[atr][atc-1].value;
                    myQueue.push(maze[atr][atc-1]);
                }
            }
            if(temp_point.right){
                if(!maze[atr][atc+1].visit&&+maze[atr][atc+1].value<maze[atr][atc+1].d){
                    maze[atr][atc+1].d=atd+maze[atr][atc+1].value;
                    myQueue.push(maze[atr][atc+1]);
                }
            }
        }
        printf("%d\n",maze[row-1][col-1].d);
        if(myQueue.size()!=0){
            myQueue.pop();
        }
    }
    return 0;
}
