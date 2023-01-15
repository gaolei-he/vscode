package kcb;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JScrollBar;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.border.Border;
import javax.swing.plaf.DimensionUIResource;

public class KCB {
    public static void main(String[] args) {
        ArrayList<Data> data = new ArrayList<Data>();

        JFrame frame = new JFrame();
        frame.setLayout(null);
        frame.setPreferredSize(new Dimension(1920, 1080));
        JTable table = new JTable(new KCBData());
        table.setRowHeight(100);
        JScrollPane pane = new JScrollPane(table);
        pane.setBounds(0, 0, 1000, 900);;
        frame.add(pane);

        JButton button = new JButton("add");
        button.setBounds(1000, 500, 80, 80);
        //button.setPreferredSize(new Dimension(10, 10));
        //button.setPreferredSize(new Dimension(1000, 1000, 40, 40));
        frame.add(button);
        button.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                // String tmp = (String) table.getValueAt(0, 0);
                // table.setValueAt(tmp, 6, 6);
                // // JScrollPane p = new JScrollPane(table);
                // // frame.remove(pane);
                // // frame.add(p, BorderLayout.CENTER);
                // frame.repaint();
                data.add(new Data((String) table.getValueAt(0, 0), (String) table.getValueAt(1, 0), (String) table.getValueAt(2, 0), (String) table.getValueAt(3, 0)));
                String tmp = "成功";
                table.setValueAt(tmp, 0, 4);
                frame.repaint();
            }
            
        });

        JButton button2 = new JButton("del");
        button2.setBounds(1000, 580, 80, 80);
        frame.add(button2);
        button2.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                Data tmp = new Data((String) table.getValueAt(0, 1), (String) table.getValueAt(1, 1), (String) table.getValueAt(2, 1), (String) table.getValueAt(3, 1));
                if (data.remove(tmp)) table.setValueAt("成功", 0, 4);
                else table.setValueAt("失败", 0, 4);
                frame.repaint();
            }

        });

        JButton button3 = new JButton("modify");
        button3.setBounds(1000, 660, 80, 80);
        frame.add(button3);
        button3.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                table.setValueAt("失败", 0, 4);
                Data tmp = new Data((String) table.getValueAt(0, 2), (String) table.getValueAt(1, 2), (String) table.getValueAt(2, 2), (String) table.getValueAt(3, 2));
                for (int i = 0; i < data.size(); i++) {
                    if(data.get(i).st().equals(tmp.st()))
                    {
                        data.set(i, tmp);
                        table.setValueAt("成功", 0, 4);
                        break;
                    }
                }
                frame.repaint();
            }

        });

        JButton button4 = new JButton("query");
        button4.setBounds(1000, 740, 80, 80);
        frame.add(button4);
        button4.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                table.setValueAt("没找到", 0, 4);
                String tmp = (String) table.getValueAt(0, 3);
                for (int i = 0; i < data.size(); i++) {
                    if(data.get(i).st().equals(tmp))
                    {
                        table.setValueAt("找到了", 0, 4);
                        break;
                    }
                }
                frame.repaint();
            }

        });


        frame.pack();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
