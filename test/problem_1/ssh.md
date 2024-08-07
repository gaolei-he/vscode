题目背景：安全外壳协议（Secure Shell Protocol，简称SSH）是一种加密的网络传输协议，可在不安全的网络中为网络服务提供安全的传输环境。SSH通过在网络中建立安全隧道来实现SSH客户端与服务器之间的连接。SSH最常见的用途是远程登录系统，人们通常利用SSH来传输命令行界面和远程执行命令。

现在，你需要实现一个简化版的 SSH 服务，以验证用户的身份。

具体来说，给你 m 个密钥对，每个密钥对包含一个公钥和一个私钥
另有 n 台主机，每台主机都有一个唯一的 IPv4 地址和一定数量的用户，用户以用户名区分，同一台主机上的用户不能重名。每个用户有仅属于自己的一些公钥
然后是 q 次查询，每次查询给出一个用户名，一个 IPv4 地址以及此次登录使用的私钥，要求你判断该 IPv4 地址对应的主机上的用户，是否拥有这个私钥对应的公钥

输入格式
第一行包含三个整数 m, n, q (1 ≤ m, q ≤ 100, 1 ≤ n ≤ 10)
接下来 m 行，每行包含两个字符串 pub, pri，表示一个密钥对，pub 是公钥，pri 是私钥，长度均不超过 10，且只包含小写字母
接下来是 n 组数据，每组数据的格式如下：
第一行包含一个字符串 ip 和 一个整数 k (1 ≤ k ≤ 10)，表示一台主机的 IPv4 地址和用户数量
然后是 k 行，每行包含一个字符串 user ，一个整数 t (1 ≤ t ≤ 10) 和 t 个字符串，表示一个用户的用户名，公钥数量，以及公钥
接下来是 q 行，每行包含一个字符串 user, 一个字符串 ip 和一个字符串 pri，表示一次查询，即一个用户名，一个 IPv4 地址和一个私钥
输出格式
对于每次查询，输出一行，如果该用户名对应的用户在该 IPv4 地址对应的主机上，并且拥有这个私钥对应的公钥，输出 Yes，否则输出 No