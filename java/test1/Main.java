package test1;
import javax.swing.*;
import java.awt.*;
public class Main {
    JFrame frame;
    public Main() {
        frame = new JFrame("Title");
        JTextArea text = new JTextArea();
        text.setBounds(0, 0, 500, 230);
        text.setEditable(false);
        
        frame.add(text, "Center");
        frame.setLayout(new BorderLayout());
        JButton btn1 = new JButton("start");
        JButton btn2 = new JButton("interrupt");
        JButton btn3 = new JButton("terminate");
        JPanel panel = new JPanel();
        JTextField text1 = new JTextField("Thread status");
        JTextField text2 = new JTextField("STOPPED");
        text2.setEditable(false);
        text1.setEditable(false);
        panel.setLayout(new FlowLayout());
        panel.add(btn1);
        panel.add(btn2);
        panel.add(btn3);
        panel.add(text1);
        panel.add(text2);
        frame.add(panel, "South");
        Thread thread = new Thread(()->{
            while(true)
            {
                try {
                    System.out.println("f");
                    Thread.sleep(1000);
                } catch (Exception e) {
                    break;
                }
            }
        });
        btn1.addActionListener(e->{
           thread.start();
        });
        btn2.addActionListener(e->{
            try {
        
            } catch (Exception e1) {
                e1.printStackTrace();
            }
        });
        btn3.addActionListener(e->{
            thread.notify();
        });
        new Thread(()->{for(;;);}).start();
        frame.setBounds(100, 100, 500, 300);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
    }
    public static void main(String[] args) {
        new Main();
    }
}