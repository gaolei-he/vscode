# 电梯调度

## 题目描述

新的学期开始了，为了更好地服务计算机学院的师生，后勤对学院电梯进行了升级，更换了新的电梯，但是工程师们在安装好电梯后发现，还没有给电梯设置调度算法，于是他们找到了你，希望你能够帮助他们。

考虑到本次是新生赛，出题人特意简化了该算法，我们假设：

1. 电梯内部的按钮不可用，各楼层外只有一个按钮
2. 当某人在某层按下按钮后，电梯只要到达该层，那么该人的需求就会被满足
3. 忽略电梯运行的加速度，忽略电梯停止的时间，忽略电梯上下行切换的时间
4. 电梯的运行速度为 $1$ 楼/秒
5. 每个人按按钮的时间均为该秒初时刻
6. 某秒末电梯在某层，下秒初该层有人按下按钮，那么他的需求直接被满足，因为电梯已经到达该层

具体地，计算机学院有 $6$ 层楼，电梯的初始位置在 $1$ 楼，每层楼电梯处都有一个按钮，现在，你需要模拟电梯的调度过程，电梯的调度算法如下：

初始情况下，在有人按按钮的情况时，电梯将会匀速上行，直到比电梯所在层更高的楼层没有人再按按钮，此时，如果下方有人按按钮，电梯将开始匀速下行，来满足这些人的需求，否则电梯将暂停运行，等待有人在其他任意楼层按下按钮

即电梯在一次上行或下行中，会尽可能的走完一整个上下行状态，例如在某次电梯上行到达 $4$ 楼后，有人同时在 $3,5$ 楼按下按钮，由于此时电梯在上行状态，那么电梯将会继续向 $5$ 楼前进，到达 $5$ 楼后，才会进入下行模式前往 $3$ 楼（假设过程中没有人再按下按钮）

现在，按照时间顺序给出每个人按下按钮的楼层，你需要输出电梯最终停止之前的运行轨迹

## 输入格式

第一行一个正整数 $n$，表示有 $n$ 个人按下了按钮
接下来 $n$ 行，每行两个正整数 $t_i$ 和 $x_i$，表示在第 $t_i$ 秒，有人在第 $x_i$ 层按下了按钮

## 输出格式

输出直到满足所有人的需求后，电梯的运行轨迹，从 `1s` 末开始，每行一个正整数，表示电梯在该秒末所在的楼层

## 样例 #1

### 样例输入 #1

```plain
5
2 4
4 2
5 3
5 5
6 6
```

### 样例输出 #1

```plain
1
2
3
4
5
6
5
4
3
2
```

#### 样例解释 #1

```plain
1 // 1s 电梯在 1 楼
2 // 2s 初，4 楼有人按下按钮，电梯开始上行，2s 末，电梯到达 2 楼
3 // 3s末 电梯上行至 3 楼
4 // 4s初，2 楼有人按下按钮，但是电梯在上行状态，且未达目的地为 4 楼，所以电梯继续上行，4s末，电梯到达 4 楼
5 // 5s初，3, 6 楼有人按下按钮，电梯在上行状态，且 5 楼有人按下按钮，所以电梯继续上行，5s末，电梯到达 5 楼
6 // 6s初，电梯在上行状态，且 6 楼有人按下按钮，所以电梯继续上行，6s末，电梯到达 6 楼
5 // 7s初，更高楼层没有人按下按钮，且之前有人在 3，2 楼按下按钮，所以电梯开始下行，7s末，电梯到达 5 楼
4 // 电梯继续下行，8s末，电梯到达 4 楼
3 // 电梯继续下行，9s末，电梯到达 3 楼
2 // 电梯继续下行，10s末，电梯到达 2 楼
所有人需求被满足，电梯停止运行
```

## 样例 #2

### 样例输入 #2

```plain
3
1 5
9 6
9 3
```

### 样例输出 #2

```plain
2
3
4
5
5
5
5
6
5
4
3
```

#### 样例解释 #2

```plain
2 // 1s 初，5 楼有人按下按钮，电梯开始上行，1s 末，电梯到达 2 楼
3 // 电梯上行，2s 末，电梯到达 3 楼
4 // 电梯上行，3s 末，电梯到达 4 楼
5 // 电梯上行，4s 末，电梯到达 5 楼
5 // 5s 初，所有人需求被满足，电梯暂停运行
5 // 6s 初，电梯仍然暂停运行
5 // 7s 初，电梯仍然暂停运行
5 // 8s 初，电梯仍然暂停运行
6 // 9s 初，6，3 楼有人按下按钮，由于电梯之前是上行状态，电梯开始上行，9s 末，电梯到达 6 楼
5 // 10s 初，电梯下行，10s 末，电梯到达 5 楼
4 // 电梯下行，11s 末，电梯到达 4 楼
3 // 电梯下行，12s 末，电梯到达 3 楼
所有人需求被满足，电梯停止运行
```

### 数据范围与提示

对于 $100\%$ 的数据，$1 \leq n \leq 1000, 1 \leq t_i \leq 1000, 1 \leq x_i \leq 6$
