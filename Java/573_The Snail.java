import java.util.Scanner;

public class Main {
    public static boolean cp20(double a){
        if(a>-0.0000000001&&a<0.0000000001){
            return true;
        }
        return false;
    }
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        double h=1.0,u=1.0,d=1.0,f=1.0;
        h=input.nextDouble();
        u=input.nextDouble();
        d=input.nextDouble();
        f=input.nextDouble();
        while(!cp20(h)&&!cp20(u)&&!cp20(d)&&!cp20(f)){
            double fatigue=u*f/100.0;
            double height=0.0;
            double up=u;
            int day=1;
            boolean isSuccess=false;
            while(!cp20(h)){
                height+=up;
                if(height>h+0.00000000001){
                    //success
                    isSuccess=true;
                    break;
                }
                height-=d;
                if(height<0){
                    break;
                }
                up-=fatigue;
                up=Math.max(0.0,up);
                day++;
            }
            if(isSuccess){
                System.out.printf("success on day %d\n",day);
            }
            else{
                System.out.printf("failure on day %d\n",day);
            }
            h=input.nextDouble();
            u=input.nextDouble();
            d=input.nextDouble();
            f=input.nextDouble();
        }
    }
}
