package selection;

import java.util.Scanner;

public class Main {
    public static void showPrompt() {
        System.out.println("请输入命令：");
        System.out.println("选课：select");
        System.out.println("退出：exit");
        System.out.println("修改密码：modify");
        System.out.println("查看可选课程：lesson");
        System.out.println("查看已选课程：mylesson");
    }
    
    public static void main(String[] args) {
        

        Lessons.init();
        String id, passwd;
        Scanner in = new Scanner(System.in);
        Data.init();
        while(true)
        {
            while(true)
            {
                System.out.print("login: ");
                id = in.next();
                System.out.print("Password: ");
                passwd = in.next();
                if(Data.confirm(id, passwd)) break;
                System.out.println("\nlogin incorrect");
            }
            Students student = new Students(id, passwd);
            
            String cmd;
            while(true)
            {
                showPrompt();
                cmd = in.next();

                if(cmd.equals("select"))
                {
                    Lessons.showLessons();
                    System.out.println("选课请输入对应课程名称");
                    while(true)
                    {
                        cmd = in.next();
                        if(cmd.equals("exit")) break;
                        if(student.selectLessons(cmd)) System.out.println("成功！");
                        else System.out.println("课程不存在！或超过人数上限");
                    }
                }
                else if(cmd.equals("modify"))
                {
                    System.out.print("请输入密码：");
                    String passwd1 = in.next();
                    System.out.println("请确认密码：");
                    String passwd2 = in.next();
                    if(passwd1.equals(passwd2)) student.modifyPasswd(passwd1);
                    else System.out.println("密码不匹配，修改失败");
                }
                else if(cmd.equals("lesson")) Lessons.showLessons();
                else if(cmd.equals("mylesson")) student.showLessons();
                else if(cmd.equals("exit")) break;

            }
        }


        


    }
}
