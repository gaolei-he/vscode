package selection;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

/**
 * Lesson
 */
public class Lessons {

    private final String name;
    private double score;
    private String type;
    private String teacher;
    private String address;

    private int total;
    private int remain;
    private int selected;
    private static HashSet<Lessons> lessons = new HashSet<Lessons>();

    public Lessons(String name, double score, String type, String teacher, String address, int total) {
        this.name = name;
        this.score = score;
        this.type = type;
        this.teacher = teacher;
        this.address = address;
        this.total = total;
        this.remain = total;
        this.selected = 0;
        lessons.add(this);
    }
    public static void addLessons(Lessons e) {
        lessons.add(e);
    }
    public static Lessons getLessons(String name) {
        for (Lessons lessons2 : lessons) {
            if(lessons2.getName().equals(name) && lessons2.remain > 0) return lessons2;
        }
        return null;
    }
    public static void init() {
        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("/home/mechrevo/Documents/vscode/java/selection/lessons.txt")));
            String line;
            while((line = in.readLine()) != null) {
                String [] lines = line.split(" ");
                lessons.add(new Lessons(lines[0], Double.parseDouble(lines[1]), lines[2], lines[3], lines[4], Integer.parseInt(lines[5])));
            }
            in.close();
        } catch (NumberFormatException | IOException e) {
            System.out.println(e);
        }
        
    }
    public static void showLessons() {
        System.out.println("学分\t类别\t任课教师\t上课地点\t限选人数\t可选人数\t课程");
        for (Lessons lesson : lessons) {
            
            System.out.print(lesson.getScore()+"\t");
            System.out.print(lesson.getType()+"\t");
            System.out.print(lesson.getTeacher()+"\t\t");
            System.out.print(lesson.getAddress()+"\t");
            System.out.print(lesson.getTotal()+"\t\t");
            System.out.print(lesson.getRemain()+"\t\t");
            System.out.print(lesson.getName());
            System.out.println("");
        }
    }
    public boolean selected() {
        if(remain < 1) return false;
        remain --;
        selected ++;
        return true;
    }

    public String getName() {
        return name;
    }

    public double getScore() {
        return score;
    }

    public String getType() {
        return type;
    }

    public String getTeacher() {
        return teacher;
    }

    public String getAddress() {
        return address;
    }

    public int getTotal() {
        return total;
    }

    public int getRemain() {
        return remain;
    }

    public int getSelected() {
        return selected;
    }

    public void setTeacher(String teacher) {
        this.teacher = teacher;
    }

    public void setAddress(String address) {
        this.address = address;
    }
    

}