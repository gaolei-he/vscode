package test.field;
import java.util.ArrayList;

import test.Bit;

public class Field {
    private int width;
    private int height;
    private Bit[][] field;
    
    public Field(int width, int height) {
        this.width = width;
        this.height = height;
        field = new Bit[height][width];
    }

    public int getWidth() { return width; }
    public int getHeight() { return height; }

    public Bit place(int row, int col, Bit o) {
        Bit ret = field[row][col];
        field[row][col] = o;
        return ret;
    }

    public Bit get(int row, int col) { 
        return field[row][col];
    }

    public void clear() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                field[i][j] = null;
            }
        }
    }
}