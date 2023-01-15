#-*-coding: utf-8-*-
from sys import exit
print("""你走进了Kanger的屋子，至于为什么，我也不知道""")

def room1():
    print("这里是会客厅")
    print("客厅的桌子上摆着水果，瓜子一类的食物")
    print("但屋里很混乱，好像有打斗的痕迹")
    print("继续探索“厕所”、”厨房”、或是“上楼”？\n")

    next1 = input("请输入 ")

    if next1 == "厕所":
        print("你来到了老八食堂\n")
        toliet()
    elif next1 == "厨房":
        print("你来到了厨房\n")
        kitchen()
    elif next1 == "上楼":
        print("你走上了楼梯\n")
        upstairs()
    else:
        room1()

def toliet():
    print("在这里，你看到了老八饭盒")
    print("旁边的水龙头在滴水，水池里有一丝泛黄")
    print("不由得让人一番猜测")
    print("要调查这里吗？\n")

    search1 = input("‘是’或’否 ")

    if search1 == "是":
        print("你选择搜索老八饭堂\n")
        shit()
    elif search1 == "否":
        print("你一脸鄙夷地放弃了搜索这里\n")
        room1()
    else:
        dead("你噎死了\n")

def shit():
    print("洗手池中没有东西")
    print("饭盒里的金坨坨夹杂着一个金闪闪")
    print("你将其打捞出来，得到了一张密码纸")
    print("上面写着“Kanger是帅比”")
    print("调查完毕，返回客厅\n")
    room1()

def kitchen():
    print("你进入了厨房")
    print("眼神犀利的你一眼就发现了这是厨房")
    print("上次说这样的话还是上次呢")
    print("眼神犀利的你再次发现了厨房中的勺子有些泛黄")
    print("厨房中还有一个录音机，要播放吗\n")

    video = input("‘是’或‘否’ ")

    if video == "是":
        print("你打开了录音机")
        print("糙泥吗")
        print("砂壁")
        dead("你因不堪凌辱致死\n")
    elif video == "否":
        print("这里为什么会有一个录音机呢")
        print("肯定是坑我的")
        print("聪明如我，肯定不听")
        print("拿一把刀防身上楼好了\n")
        print("菜刀的启动暗示为：菜康")
        upstairs()
    else:
        print("你沉默了")
        print("你离开了")
        print("实际是因为我编不出来了...\n")
        upstairs()

def upstairs():
    print("你上楼了")
    print("有两个门，一左一右，要走哪边呢?\n")

    side = input("‘左’或‘右’ ")

    if side == "左":
        print("男左女右，走左边\n")
        left()

    if side == "右":
        print("男左女右封建理念，果断右边")
        print("右边的门是一个密码门")
        print("提示:密码在一楼\n")

        code = input("请输入密码 ")

        if code == "Kanger是帅比":
            print("密码正确\n")
            right()
        else:
            print("密码错误")
            print("响起的警报声招来了隔壁的狗子")
            print("请输入菜刀的启动暗示\n")

            knife = input("请输入启动暗示 ")

            if knife == "菜康":
                print("你成功吓退了狗子")
                print("没有密码的大傻子，快去找密码吧\n")
                room1()
            else:
                dead("你被狗子咬的稀碎\n")

    else:
        dead("你因不慎脚滑摔了下去，成功完成了一次折颈摔\n")

def left():
    print("你进入了左边的门")
    print("屋里有一头狗子在睡觉")
    print("狗子的身下有一个RTX")
    print("要想办法给它拿过来\n")

    method = input("“潜行”或“无双” ")

    if method == "潜行":
        print("你选择悄悄接近狗子\n")
        rtx1()
    elif method == "无双":
        print("你选择莽过去\n")
        rtx2()
    else:
        left()

def rtx1():
    print("你成功在不把狗子惊醒的情况下拿到了‘RTX3080ti’")
    print("现在还是赶快离开这个房间吧\n")
    upstairs()

def rtx2():
    print("你的无畏冲锋和勇气值得嘉奖")
    print("但狗子不会因此怜悯你")
    dead("你被狗子咬的稀碎\n")

def right():
    print("你进入了右边的门")
    print("屋里的Kanger看着你一言不发")
    print("面色红润的他，旁边还躺着一个男人")
    print("‘唯有交予我RTX才能放你走’")
    print("是否交予Kanger?\n")

    give = input("‘是’或‘否’ ")

    if give == "是":
        print("请输入型号\n")

        model = input("型号为 ")

        if model == "RTX3080ti":
            escape()
        else:
            dead("你因失血过多致死\n")

    if give == "否":
        print("那好吧，这是你自找的")
        dead("不要小看Kanger的野蛮冲撞\n")

    else:
        dead("Kanger等不及了，你因失血过多致死\n")

def escape():
    print("你把RTX给了Kanger")
    print("你得到了Kanger的宽恕")
    print("你逃出了Kanger的屋子")
    print("真难想象Kanger的奇怪癖好\n")
    exit(0)

def dead(reason):
    print(reason)
    exit(0)

room1()
