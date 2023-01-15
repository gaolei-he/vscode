package selection;

import java.util.HashSet;

public class Students {
    private String id;
    private String passwd;
    private HashSet<Lessons> lessons;
    public Students(String id, String passwd) {
        this.id = id;
        this.passwd = passwd;
        this.lessons = new HashSet<Lessons>();
        Data.add(id, passwd);
    }

    public boolean select(Lessons lessons) {
        
        if(!lessons.selected()) return false;
        this.lessons.add(lessons);
        return true;
        
    }

    public int totalLessons() {
        return lessons.size();
    }

    public HashSet<Lessons> getLessons() {
        return lessons;
    }
    public boolean selectLessons(String name) {
        Lessons lesson1 = Lessons.getLessons(name);
        if(lesson1 == null) return false;
        this.select(lesson1);
        return true;
    }
    public void modifyPasswd(String passwd) {
        this.passwd = passwd;
        Data.del(this.id);
        Data.add(this.id, this.passwd);
    }
 
    public void showLessons() {
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
    
}
