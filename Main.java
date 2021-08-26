import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        String str = s.nextLine();
        int len = str.length();
        StringBuilder ans = new StringBuilder(str.substring(len-1));
        for(int i = len - 2; i >= 0; i--){
            if(str.charAt(i) >= ans.toString().charAt(0))
                ans.insert(0,str.substring(i,i+1));
        }
        System.out.println(ans.toString());
    }
}
