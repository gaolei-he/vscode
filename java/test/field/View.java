package test.field;

import javax.swing.JPanel;
import test.Bit;
import test.field.Field;
import java.awt.Graphics;
import java.awt.Dimension;
public class View extends JPanel {
    private static final long serialVersionUID = -5258995676212660595L;
    private static final int GRID_SIZE = 16;
    private Field theField;
    @Override
    public Dimension getPreferredSize() {
        return new Dimension(theField.getWidth()*GRID_SIZE+1, theField.getHeight()*GRID_SIZE+1);
    }
    @Override
    public void paint(Graphics g) {
        super.paint(g);
        for (int row = 0; row < theField.getHeight(); row++) {
            for (int col = 0; col < theField.getWidth(); col++) {
                Bit bit = theField.get(row, col);
                if ( bit != null ) {
                    bit.draw(g, col*GRID_SIZE, row*GRID_SIZE, GRID_SIZE);
                }
            }
        }
    }
    public View(Field field) {
        theField = field;
    }
}
