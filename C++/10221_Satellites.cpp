#include<cstdio>
#include<cmath>
using namespace std;
#define pi 3.14159265358979323846264338995
int main(){
    double rad,angle,arc,chord;
    char type[4];
    while(~scanf("%lf",&rad)){
        scanf("%lf%s",&angle,type);
        rad+=6440;
        if(type[0]=='d'){
            if(360-angle<angle){
                angle=360-angle;
            }
            arc=2*rad*pi*angle/360.0;
            chord=2*rad*sin(angle*pi/360.0);
        }
        else if(type[0]=='m'){
            arc=2*rad*pi*angle/21600.0;
            chord=2*rad*sin(angle*pi/21600.0);
        }
        printf("%lf %lf\n",arc,chord);
    }
    return 0;
}
