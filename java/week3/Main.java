package week3;

import java.util.HashMap;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String tmp = in.nextLine();
        tmp = tmp.replaceAll(" *###", "");
        String[] ans = tmp.split("  *");
        System.out.println("Good");
        HashMap<String, Integer> res = new HashMap<String, Integer>();
        for (int i = 0; i < ans.length; i++) {
            for (int j = 0; j < ans.length; j++) {
                int k = in.nextInt();
                res.put(ans[i]+ans[j], k);
            }
        }
        System.out.println(ans.length);
        tmp = in.nextLine();
        tmp = in.nextLine();
        
        //System.out.println(tmp);
        System.out.println(tmp);
        tmp = tmp.replaceAll("  *", "");
        
        System.out.println(res.get(tmp));
        in.close();
    }
}