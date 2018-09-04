import java.util.Scanner;
public class Main {
    public static class Matrix{
        public static int[] mul(int[][] mat,int[] vec) {
            int m = mat.length;
            int n = mat[0].length;
            int[] y = new int[m];
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    y[i] += mat[i][j] * vec[j];
            return y;
        }
    }
    public static void main(String[] args){
        int[][] yPlus={{0,-1,0},{1,0,0},{0,0,1}};
        int[][] yMinus={{0,1,0},{-1,0,0},{0,0,1}};
        int[][] zPlus={{0,0,-1},{0,1,0},{1,0,0}};
        int[][] zMinus={{0,0,1},{0,1,0},{-1,0,0}};
        Scanner input=new Scanner(System.in);
        int length=input.nextInt();
        while(length!=0){
            int[] vec= {1,0,0};
            for(int i=0;i<length-1;i++){
                String op=input.next();
                if(op.equals("+y")){
                    vec=Matrix.mul(yPlus,vec);
                }
                else if(op.equals("-y")){
                    vec=Matrix.mul(yMinus,vec);
                }
                else if(op.equals("+z")){
                    vec=Matrix.mul(zPlus,vec);
                }
                else if(op.equals("-z")){
                    vec=Matrix.mul(zMinus,vec);
                }
            }
            if(vec[0]>0){
                System.out.println("+x");
            }
            else if(vec[0]<0){
                System.out.println("-x");
            }
            else if(vec[1]>0){
                System.out.println("+y");
            }
            else if(vec[1]<0){
                System.out.println("-y");
            }
            else if(vec[2]>0){
                System.out.println("+z");
            }
            else if(vec[2]<0){
                System.out.println("-z");
            }
            length=input.nextInt();
        }
    }
}
