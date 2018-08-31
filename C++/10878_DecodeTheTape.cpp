#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;
string tape;
int main(){
   //ifstream fin("input.txt");
    int tempInt=0;
    getline(cin,tape);
    getline(cin,tape);
    do{
        tempInt=0;
        if(tape[2]=='o'){
            tempInt+=64;
        }
        if(tape[3]=='o'){
            tempInt+=32;
        }
        if(tape[4]=='o'){
            tempInt+=16;
        }
        if(tape[5]=='o'){
            tempInt+=8;
        }
        if(tape[7]=='o'){
            tempInt+=4;
        }
        if(tape[8]=='o'){
            tempInt+=2;
        }
        if(tape[9]=='o'){
            tempInt+=1;
        }
        getline(cin,tape);

        cout << static_cast<char>(tempInt);
    }while(tape[0]!='_');
    //fin.close();
    return 0;
}
/*
32+64+1
00**.**0------a
00  . 0 ------b
00  . 00------c
00  .0  ------d
 0  .   ------
 0 0.00 ------.
   0. 0 ------\n
8+1=9
32+8+4+2
*/
