import java.util.Scanner;
class Proposal{
    public String name;
    public double price;
    public int checks;
}
public class Main {
    public static void main(String[] args){
        int numR,numP;
        int caseNum=1;
        Scanner input=new Scanner(System.in);
        numR=input.nextInt();
        numP=input.nextInt();
        while(numR!=0&&numP!=0){
            String tmp=input.nextLine();
            String[] requests=new String[numR];
            Proposal[] proposals=new Proposal[numP];
            for(int i=0;i<numR;i++){
                requests[i]=input.nextLine();
            }
            Proposal best=new Proposal();
            best.price=Double.MAX_VALUE;
            best.checks=-1;
            for(int i=0;i<numP;i++){
                proposals[i]=new Proposal();
                proposals[i].name=input.nextLine();
                proposals[i].price=input.nextDouble();
                proposals[i].checks=input.nextInt();
                tmp=input.nextLine();
                for(int j=0;j<proposals[i].checks;j++){
                    tmp=input.nextLine();
                }
                if(proposals[i].checks>best.checks){
                    best=proposals[i];
                }
                else if(proposals[i].checks==best.checks&&proposals[i].price<best.price){
                    best=proposals[i];
                }
            }
            System.out.printf("RFP #%d\n",caseNum++);
            System.out.println(best.name);
            numR=input.nextInt();
            numP=input.nextInt();
            if(numR!=0&&numP!=0){
                System.out.println();
            }
        }
    }
}
