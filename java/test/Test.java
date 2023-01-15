package test;
import test.field.Field;
import test.field.View;
import javax.swing.JFrame;


public class Test {
    private Field field;
    private JFrame frame;
    public void start() {
        frame = new JFrame();
        field = new Field(21, 21);
        for (int row = 0; row < field.getHeight(); row++) {
            for (int col = 0; col < field.getWidth(); col++) {
                field.place(row, col, new Bit());
            }
        }

        int cnt = 0;

        for (int row = 0; row < field.getHeight(); row++) {
            for (int col = 0; col < field.getWidth(); col++) {
                Bit bit = field.get(row, col);
                if(Math.random() < 0.5) {
                    bit.reborn();
                    cnt ++;
                }
            }
        }
        System.out.println(cnt);
        System.out.println(21*21);


        View view = new View(field);

        frame.add(view);

        frame.setTitle("QR Code");

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // frame.setResizable(false);

        frame.pack();
        frame.setVisible(true);
    }
    public static void main(String[] args) {
        Test st = new Test();
        st.start();
    }
}
