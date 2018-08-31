#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<map>
using namespace std;
typedef struct{
    int hour,minute;
}myTime;
map<string,int>nti;
myTime table[32];
void ini(){
    nti["UTC"]=0;
    table[0].hour=0;table[0].minute=0;
    nti["GMT"]=1;
    table[1].hour=0;table[1].minute=0;
    nti["BST"]=2;
    table[2].hour=1;table[2].minute=0;
    nti["IST"]=3;
    table[3].hour=1;table[3].minute=0;
    nti["WET"]=4;
    table[4].hour=0;table[4].minute=0;
    nti["WEST"]=5;
    table[5].hour=1;table[5].minute=0;
    nti["CET"]=6;
    table[6].hour=1;table[6].minute=0;
    nti["CEST"]=7;
    table[7].hour=2;table[7].minute=0;
    nti["EET"]=8;
    table[8].hour=2;table[8].minute=0;
    nti["EEST"]=9;
    table[9].hour=3;table[9].minute=0;
    nti["MSK"]=10;
    table[10].hour=3;table[10].minute=0;
    nti["MSD"]=11;
    table[11].hour=4;table[11].minute=0;
    nti["AST"]=12;
    table[12].hour=-4;table[12].minute=0;
    nti["ADT"]=13;
    table[13].hour=-3;table[13].minute=0;
    nti["NST"]=14;
    table[14].hour=-3;table[14].minute=-30;
    nti["NDT"]=15;
    table[15].hour=-2;table[15].minute=-30;
    nti["EST"]=16;
    table[16].hour=-5;table[16].minute=0;
    nti["EDT"]=17;
    table[17].hour=-4;table[17].minute=0;
    nti["CST"]=18;
    table[18].hour=-6;table[18].minute=0;
    nti["CDT"]=19;
    table[19].hour=-5;table[19].minute=0;
    nti["MST"]=20;
    table[20].hour=-7;table[20].minute=0;
    nti["MDT"]=21;
    table[21].hour=-6;table[21].minute=0;
    nti["PST"]=22;
    table[22].hour=-8;table[22].minute=0;
    nti["PDT"]=23;
    table[23].hour=-7;table[23].minute=0;
    nti["HST"]=24;
    table[24].hour=-10;table[24].minute=0;
    nti["AKST"]=25;
    table[25].hour=-9;table[25].minute=0;
    nti["AKDT"]=26;
    table[26].hour=-8;table[26].minute=0;
    nti["AEST"]=27;
    table[27].hour=10;table[27].minute=0;
    nti["AEDT"]=28;
    table[28].hour=11;table[28].minute=0;
    nti["ACST"]=29;
    table[29].hour=9;table[29].minute=30;
    nti["ACDT"]=30;
    table[30].hour=10;table[30].minute=30;
    nti["AWST"]=31;
    table[31].hour=8;table[31].minute=0;
}
myTime StringToTime(string in){
    myTime tmp;
    tmp.hour=0;
    tmp.minute=0;
    int i;
    for(i=0;;i++){
        if(in[i]==':'){
            break;
        }
        tmp.hour=tmp.hour*10+(in[i]-'0');
    }
    for(i=i+1;i<in.length();i++){
        tmp.minute=tmp.minute*10+(in[i]-'0');
    }
    return tmp;
}
myTime solve(myTime now,string n,string t){
    myTime nn=table[nti[n]],tt=table[nti[t]];
    now.hour=now.hour-nn.hour+tt.hour;
    now.minute=now.minute-nn.minute+tt.minute;
    return now;
}
int main(){
    //freopen("output.txt","w",stdout);
    ini();
    myTime now;
    string tmpStr1,tmpStr2;
    int kase,i;
    cin>>kase;
    for(i=1;i<=kase;i++){
        cin>>tmpStr1;
        if(tmpStr1[0]=='n'){
            now.hour=12;
            now.minute=0;
        }
        else if(tmpStr1[0]=='m'){
            now.hour=0;
            now.minute=0;
        }
        else{
            now=StringToTime(tmpStr1);
            cin>>tmpStr2;
            if(now.hour==12){
                now.hour-=12;
            }
            if(tmpStr2[0]=='p'){

                now.hour+=12;
            }
        }
        cin>>tmpStr1>>tmpStr2;
        now=solve(now,tmpStr1,tmpStr2);
        if(now.minute>=60){
            now.hour+=now.minute/60;
            now.minute=now.minute%60;
        }
        if(now.minute<0){
            now.hour-=1;
            now.minute+=60;
        }
        if(now.hour>=0){
            if(now.hour%12==0){
                if((now.hour/12)%2==1){
                    if(now.minute==0){
                        puts("noon");
                    }
                    else{
                       printf("12:%02d p.m.\n",now.minute);
                    }
                }
                else{
                    if(now.minute==0){
                        puts("midnight");
                    }
                    else{
                        printf("12:%02d a.m.\n",now.minute);
                    }
                }
            }
            else{
                 if((now.hour/12)%2==1){
                    printf("%d:%02d p.m.\n",now.hour%12,now.minute);

                }
                else{
                    printf("%d:%02d a.m.\n",now.hour%12,now.minute);
                }
            }
        }
        else{
            int j=12,k=1;
            while(1){
                if(j+now.hour>0){
                     if(k%2==1){
                        printf("%d:%02d p.m.\n",j+now.hour,now.minute);

                    }
                    else{
                        printf("%d:%02d a.m.\n",j+now.hour,now.minute);
                    }
                    break;
                }
                else if(j+now.hour==0){
                     if(k%2==1){
                        if(now.minute==0){
                            puts("noon");
                        }
                        else{
                           printf("12:%02d p.m.\n",now.minute);
                        }
                    }
                    else{
                        if(now.minute==0){
                            puts("midnight");
                        }
                        else{
                            printf("12:%02d a.m.\n",now.minute);
                        }
                    }
                    break;
                }
                j+=12;
                k++;
            }
        }
    }
    return 0;
}
