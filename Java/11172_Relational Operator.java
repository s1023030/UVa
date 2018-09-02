import java.math.BigInteger;
import java.util.Scanner;
public class Main {
    public static  void main(String[] args){
        Scanner input = new Scanner(System.in);
        int caseNum=input.nextInt();
        for(int i=0;i<caseNum;i++){
            BigInteger a=input.nextBigInteger();
            BigInteger b=input.nextBigInteger();
            int relation=a.compareTo(b);
            if(relation==-1){
                System.out.println("<");
            }
            else if(relation==0){
                System.out.println("=");
            }
            else if(relation==1){
                System.out.println(">");
            }

        }
    }
}
