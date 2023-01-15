package kcb;

import javax.swing.event.TableModelListener;
import javax.swing.table.TableModel;

public class KCBData implements TableModel {
    private String[] title = {
        "添加", "删除", "修改", "查询", "结果"
    };
    private String[][] data = new String[4][5];
    public KCBData() {
        for(int i=0;i<data.length;i++) {
            for(int j=0;j<data[i].length;j++) {
                data[i][j] = "";
            }
        }
    }
    @Override
    public void addTableModelListener(TableModelListener l) {
        // TODO Auto-generated method stub
        
    }

    @Override
    public Class<?> getColumnClass(int columnIndex) {
        return String.class;
    }

    @Override
    public int getColumnCount() {
        return 5;
    }

    @Override
    public String getColumnName(int columnIndex) {
        // TODO Auto-generated method stub
        return title[columnIndex];
    }

    @Override
    public int getRowCount() {
        return 4;
    }

    @Override
    public Object getValueAt(int arg0, int arg1) {
        // TODO Auto-generated method stub
        return data[arg0][arg1];
    }

    @Override
    public boolean isCellEditable(int arg0, int arg1) {
        // TODO Auto-generated method stub
        return true;
    }

    @Override
    public void removeTableModelListener(TableModelListener l) {
        // TODO Auto-generated method stub
        
    }

    @Override
    public void setValueAt(Object arg0, int arg1, int arg2) {
        // TODO Auto-generated method stub
        data[arg1][arg2] = (String) arg0;
    }
       
}
