package week1;

import java.util.Scanner;


public class Main {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        Fraction a = new Fraction(in.nextInt(), in.nextInt());

        Fraction b = new Fraction(in.nextInt(),in.nextInt());

        a.print();

        b.print();

        a.plus(b).print();

        a.multiply(b).plus(new Fraction(5,6)).print();

        a.print();

        b.print();

        in.close();

    }

}
class Fraction {
    private int fenzi;
    private int fenmu;

    Fraction(int a, int b)
    {
        int d = gcd(a, b);
        a /= d;
        b /= d;
        fenzi = a;
        fenmu = b;
    }

    int gcd(int a, int b)
    {
        if(b == 0) return a;
        else return gcd(b, a%b);
    }
    
    Fraction plus(Fraction r)
    {
        int t2 = fenmu * r.fenmu;
        int t1 = fenzi * r.fenmu + r.fenzi * fenmu;
        int d = gcd(t2, t1);
        t2 /= d;
        t1 /= d;
        return new Fraction(t1, t2);
    }

    Fraction multiply(Fraction r)
    {
        int t1 = fenzi * r.fenzi;
        int t2 = fenmu * r.fenmu;
        int d = gcd(fenzi, fenmu);
        t1 /= d;
        t2 /= d;
        return new Fraction(t1, t2);
    }

    void print()
    {
        int d = gcd(fenzi, fenmu);
        fenzi /= d;
        fenmu /= d;
        if(fenzi == 0) System.out.println(0);
        else if(fenmu == 1) System.out.println(fenzi);
        else System.out.println(fenzi+"/"+fenmu);
    }
}