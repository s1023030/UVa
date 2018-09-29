import java.util.Scanner;
import java.util.Arrays;
public class uva357 {
    public static void main(String[] args){
        int[] coin={5,10,25,50};
        long[] dp =new long[30005];
        Arrays.fill(dp,1);
        for (int i=0;i<coin.length;i++){
            for(int j=coin[i];j<30005;j++){
                dp[j]+=dp[j-coin[i]];
            }
        }
        Scanner input=new Scanner(System.in);
        while(input.hasNext()){
            int num=input.nextInt();
            if( dp[num]==1){
                System.out.printf("There is only 1 way to produce %d cents change.\n", num);
            }
            else{
                System.out.printf("There are %d ways to produce %d cents change.\n", dp[num], num);
            }
        }
    }
}
