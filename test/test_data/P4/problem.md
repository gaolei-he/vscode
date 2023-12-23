# 完蛋，我被美女包围了

## 题目描述

《完蛋！我被美女包围了！》是一款模拟...
咳咳，今天我们的任务是帮助Third找回他的对象，Third目前跟 $n$ 个女孩有交往，由于Third交往的女孩太多，他把自己对象的名字给忘了，现在Third只有每个女孩的名字和她对自己的好感度，其中好感度最高的女孩就是Third的对象，请你输出Third对象的名字，如果对Third好感度最高的女孩有多个，你仅需输出以下字符串：`wake up, Third!`

## 输入格式

第一行一个正整数 $n$，表示有 $n$ 个女孩和Third交往
接下来 $n$ 行，每行一个仅由大小写英文字母组成的字符串 $s$ 和一个整数 $x$，$s$ 是女孩的名字，$x$ 是该女孩对Third的好感度

## 输出格式

一行字符串，表示Third对象的名字，如果对Third好感度最高的女孩有多个，你仅需输出以下字符串：`wake up, Third!`

## 样例 #1

### 样例输入 #1

```plain
6
Jawara 20
Zoe 15
Clara 13
Diaz 10
Dakr 10
Dray 14
```

### 样例输出 #1

```plain
Jawara
```

## 样例 #2

### 样例输入 #2

```plain
3
Alice 32
Christina 32
Lara 4
```

### 样例输出 #2

```plain
wake up, Third!
```

#### 样例解释

```plain
样例 1 Jawara对Third的好感度最高，是Third的对象
样例 2 Alice和Christina对Third的好感度均最高，输出wakeup, Third!
```

### 数据范围与提示

对于 $100\%$ 的数据，$1 \leq x,n \leq 1000, 1\leq s.length \leq 10$
