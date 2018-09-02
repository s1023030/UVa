import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
public class Main{
    public static void main(String[] args){
        Scanner input=new Scanner(System.in);
        while(input.hasNext()) {
            int num;
            num=input.nextInt();
            if(num==0){
                break;
            }
            input.nextLine();
            int[] oriLine=new int[num];
            for(int i=1;i<=num;i++){
                oriLine[i-1]=i;
            }
            while(true){
                String tmpStr=new String(input.nextLine());
                Queue queue=new LinkedList();
                if(tmpStr.length()==1&&tmpStr.charAt(0)=='0'){
                    System.out.println();
                    break;
                }
                Scanner eleInput=new Scanner(tmpStr);
                for(int i=0;i<num;i++){
                    queue.offer(eleInput.nextInt());
                }
                int point=0;
                Stack stack=new Stack();
                while(point<num){
                    if(oriLine[point]==(int)queue.peek()){
                        point++;
                        queue.poll();
                    }
                    else if(!stack.isEmpty()&&(int)stack.peek()==(int)queue.peek()){
                        stack.pop();
                        queue.poll();
                    }
                    else{
                        stack.push(oriLine[point++]);
                    }
                    if(queue.isEmpty()){
                        break;
                    }
                }
                while(!stack.isEmpty()){
                    if(queue.peek()==stack.peek()){
                        queue.poll();
                        stack.pop();
                    }
                    else{
                        break;
                    }
                }
                if(queue.isEmpty()){
                    System.out.println("Yes");
                }
                else{
                    System.out.println("No");
                }
            }
        }
    }
}
