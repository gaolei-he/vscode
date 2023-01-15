import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class A4644 {
    public static void solve() throws Exception {
        int n;
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(in.readLine());
        String[] tmp = in.readLine().split(" ");
        in.close();
        
        long[] a = new long[n+10];
        long[] s = new long[n+10];
        for(int i=1;i<=n;i++) {
            a[i] = Integer.parseInt(tmp[i-1]);
            s[i] = a[i] + s[i-1];
        }
        long ans = 0;
        for(int i=1;i<n;i++) {
            ans += a[i] * (s[n] - s[i]);
        }
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        out.write(String.valueOf(ans));
        out.close();
        out.flush();
    }
    public static void main(String[] args) {
        try {
            solve();
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }

    }
}