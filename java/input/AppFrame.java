package input;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;

import java.awt.event.ActionEvent;


import javax.swing.JButton;
import javax.swing.JFrame;


public class AppFrame extends JFrame
{
    JTextField in = new JTextField(10);
    JButton btn = new JButton("求平方");
    JLabel out = new JLabel("用于显示结果的标签");
    public AppFrame() {
        setLayout(new FlowLayout());
        getContentPane().add(in);
        getContentPane().add(btn);
        getContentPane().add(out);
        btn.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
               String s = in.getText();
               double d = Double.parseDouble(s);
               double sq = d * d;
               out.setText(d + "的平方是：" + sq);
            }
            
        });
        setSize(400, 100);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setVisible(true);
    }



}