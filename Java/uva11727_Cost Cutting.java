import java.util.Scanner;
public class Main {
    public static void main(String[] args){
        Scanner input =new Scanner(System.in);
        int numCase=input.nextInt();
        int[] salary=new int[3];
        for(int i=0;i<numCase;i++){
            salary[0]=input.nextInt();
            salary[1]=input.nextInt();
            salary[2]=input.nextInt();
            int max=-1;
            int second=-1;
            for(int j=0;j<3;j++){
                int n=salary[j];
                if(n>max){
                    second=max;
                    max=n;
                }
                else if(n>second){
                    second=n;
                }
            }
            System.out.printf("Case %d: %d\n",(i+1),second);
        }
    }
}
