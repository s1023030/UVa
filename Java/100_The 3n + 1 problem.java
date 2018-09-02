import java.util.Map;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static Map<Integer, Integer> cycleLength = new HashMap<>();
    private static int calLength(int num){
        if(cycleLength.containsKey(num)){
            return cycleLength.get(num);
        }
        else{
            int tmpInt;
            if(num%2==1){
                tmpInt=calLength(3*num+1)+1;
                cycleLength.put(num,tmpInt);
                return tmpInt;
            }
            else{
                tmpInt=calLength(num/2)+1;
                cycleLength.put(num,tmpInt);
                return tmpInt;
            }
        }
    }
    public static void main(String[] args){
        cycleLength.put(1,1);
        Scanner input=new Scanner(System.in);
        while(input.hasNext()){
            int max=-1;
            int low=input.nextInt();
            int upp=input.nextInt();
            if(low>upp){
                for(int i=upp;i<=low;i++){
                    int tmpInt=calLength(i);
                    if(max<tmpInt){
                        max=tmpInt;
                    }
                }
            }
            else{
                for(int i=low;i<=upp;i++){
                    int tmpInt=calLength(i);
                    if(max<tmpInt){
                        max=tmpInt;
                    }
                }
            }

            System.out.format("%d %d %d%n",low,upp,max);
        }
    }
}
