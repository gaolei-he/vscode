package test;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.ArrayList;
import java.util.Scanner;

// class Node {
//     public Node() {
//         a = 0;
//         b = 1;
//     }
//     public int a;
//     public int b;
//     public void f() {System.out.println(a+b);}
// }
// private class Base {
//     Base()
//     {
//         int i = 100;
//         System.out.println(i);
//     }
// }

public class PriBase {

    static int i = 200;
    public static void main(String[] args) {
        PriBase p = new PriBase();
        System.out.println(i);
        // BufferedReader in;
        // try {
        //     in = new BufferedReader(new InputStreamReader(new FileInputStream("text.txt")));
        //     try {
        //         String s;
        //         while((s = in.readLine()) != null)
        //         {
        //             System.out.println(s);
        //         }
        //     } catch (IOException e) {
        //         // TODO Auto-generated catch block
        //         e.printStackTrace();
        //     }
        // } catch (FileNotFoundException e1) {
        //     // TODO Auto-generated catch block
        //     e1.printStackTrace();
        // }

        // try {
        //     Scanner in = new Scanner(new FileInputStream("text.txt"));
        //     String s;
        //     while((s = in.nextLine())!=null){System.out.println(s);}
        // } catch (FileNotFoundException e) {
        //     // TODO Auto-generated catch block
        //     e.printStackTrace();
        // }

            
        
        // PrintWriter out;
        // try {
        //     out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(new FileOutputStream("text.txt"))));
        //     for(int i=1;i<=10000000;i++)
        //     {
        //         out.print(i);
        //         out.print(" ");
        //     }
        //     out.close();
        // } catch (FileNotFoundException e) {
        //     // TODO Auto-generated catch block
        //     e.printStackTrace();
        // }

        // Socket socket;
        // try {
        //     socket = new Socket(InetAddress.getByName("localhost"), 12345);
        //     PrintWriter out = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));
        //     out.println("hello");
        //     out.flush();
        //     BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        //     String line;
        //     line = in.readLine();
        //     System.out.println(line);
        //     out.close();
        //     socket.close();
        // } catch (UnknownHostException e) {
        //     // TODO Auto-generated catch block
        //     e.printStackTrace();
        // } catch (IOException e) {
        //     // TODO Auto-generated catch block
        //     e.printStackTrace();
        // }
        
        // ArrayList<String> a = new ArrayList<String>();
        // a.add("Good");
        // String tmp = "Good";
        // a.remove(tmp);
        // for (String t : a) {
        //     System.out.println(t);
        // }


    }
}