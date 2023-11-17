package JavaPractice;
import java.util.*;
class TestClass{

    public static void main(String args[] ) throws Exception{
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int[]arr = new int[10];
        int num;
        int digit = Integer.MIN_VALUE;
        for(int i=0;i<size;i++){
            boolean[]hash = new boolean[10];
            num = sc.nextInt();
            while(num>0){
                if(hash[num%10]==false){
                    arr[num%10]++;
                }
                hash[num%10] = true;
                num = num / 10;
            }
        }
        for(int i=0;i<10;i++){
            if(digit<arr[i]){
                digit = arr[i];
            }
        }
        System.out.println(digit);
    }
}
