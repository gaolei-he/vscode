package bufferread;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Read {
    public static void main(String[] args) {
        String s = "";
        try {
            BufferedReader in = new BufferedReader(
                new InputStreamReader(System.in));
            
            s = in.readLine();
        } catch (IOException e) {}
        int n = Integer.parseInt(s);
        System.out.println(n);
    }
}