import java.util.Scanner;
public class Main {
    public static void main(String[] args){
        Scanner input=new Scanner(System.in);
        int numCase=input.nextInt();
        int dx,dy;
        int tx,ty;
        while(numCase!=0){
            dx=input.nextInt();
            dy=input.nextInt();
            for(int i=0;i<numCase;i++){
                tx=input.nextInt();
                ty=input.nextInt();
                if(tx==dx||ty==dy){
                    System.out.println("divisa");
                }
                else{
                    if(ty>dy){
                        System.out.print('N');
                    }
                    else{
                        System.out.print('S');
                    }
                    if(tx>dx){
                        System.out.print('E');
                    }
                    else{
                        System.out.print('O');
                    }
                    System.out.print('\n');
                }
            }
            numCase=input.nextInt();
        }
    }
}
