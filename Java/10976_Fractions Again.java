import java.util.Scanner;
import java.util.ArrayList;
public class Main {
    private  static  int GCD(int a,int b){
        if(a%b==0){
            return b;
        }
        else{
            return GCD(b,a%b);
        }
    }
    private  static  int LCM(int a,int b){
        return a*b/GCD(a,b);
    }
    public static void main(String[] args){
        Scanner input=new Scanner(System.in);
        while(input.hasNext()){
            int num=input.nextInt();
            int i=Integer.MAX_VALUE;
            ArrayList<Integer>ans1=new ArrayList<Integer>();
            ArrayList<Integer>ans2=new ArrayList<Integer>();
            for(int j=num+1;i>=j;j++){
                int up_num=1,up_j=1,up_i;
                int lcm=LCM(num,j);
                up_num=lcm/num;
                up_j=lcm/j;
                up_i=up_num-up_j;
                int gcd=GCD(up_i,lcm);
                up_i/=gcd;
                lcm/=gcd;
                if(up_i==1){
                    ans1.add(lcm);
                    ans2.add(j);
                }
                i=lcm/up_i;
            }
            System.out.println(ans1.size());
            for(int j=0;j<ans1.size();j++){
                System.out.printf("1/%d = 1/%d + 1/%d\n",num,ans1.get(j),ans2.get(j));
            }
        }
    }
}
