#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Td, Ta, Ti;
    std::string H;
    std::cin >> N >> Td >> Ta >> Ti >> H;
    int n;
    std::cin >> n;

    auto set_ttl = [&](int t, int ttl) {
        int res_ttl;
        if (ttl == 0) {
            res_ttl = t + Td;
        } else {
            if (ttl - t < Ti) {
                ttl = Ti;
            } else if (ttl - t > Ta) {
                ttl = Ta;
            } else {
                ttl = ttl - t;
            }
            res_ttl = t + ttl;
        }
        return res_ttl;
    };

    auto send_offer = [&](std::string& sender, int ip, int ttl) {
        std::cout << H << " " << sender << " "
                  << "OFR"
                  << " " << ip << " " << ttl << std::endl;
    };
    auto send_nak = [&](std::string& sender, int ip, int ttl) {
        std::cout << H << " " << sender << " "
                  << "NAK"
                  << " " << ip << " " << ttl << std::endl;
    };
    auto send_ack = [&](std::string& sender, int ip, int ttl) {
        std::cout << H << " " << sender << " "
                  << "ACK"
                  << " " << ip << " " << ttl << std::endl;
    };

    std::set<int> un_alloc_ip;
    std::set<int> exp_ip;
    std::set<int> will_alloc_ip;
    std::set<int> alloc_ip;
    std::map<std::string, int> host_ip;
    std::map<int, std::string> ip_host;
    std::map<int, int> exp_time;
    auto get_ip = [&](std::string& host, int ip) {
        if (host_ip.count(host)) {
            return host_ip[host];
        }
        if (un_alloc_ip.size()) {
            ip = *un_alloc_ip.begin();
            return ip;
        } else if (exp_ip.size()) {
            ip = *exp_ip.begin();
            return ip;
        }
        return -1;
    };
    auto set_ip1 = [&](std::string& host, int ip) {
        if (un_alloc_ip.count(ip)) {
            un_alloc_ip.erase(ip);
        } else if (exp_ip.count(ip)) {
            exp_ip.erase(ip);
        } else if (alloc_ip.count(ip)) {
            alloc_ip.erase(ip);
        }
        will_alloc_ip.insert(ip);
        if (host_ip.count(host) and ip_host.count(host_ip[host])) {
            ip_host.erase(host_ip[host]);
        }
        if (ip_host.count(ip)) {
            std::string tmp = ip_host[ip];
            host_ip.erase(tmp);
        }
        host_ip[host] = ip;
        ip_host[ip] = host;
    };
    auto clear_ip = [&](std::string& host) {
        if (host != H) {
            if (host_ip.count(host) and will_alloc_ip.count(host_ip[host])) {
                will_alloc_ip.erase(host_ip[host]);
                un_alloc_ip.insert(host_ip[host]);
                ip_host.erase(host_ip[host]);
                exp_time[host_ip[host]] = 0;
                host_ip.erase(host);
            }
        }
    };
    auto take_ip = [&](std::string& host, int ip) {
        if (ip < 1 or ip > N) {
            return true;
        } else if (ip_host.count(ip) and ip_host[ip] != host) {
            return true;
        } else if (!ip_host.count(ip)) {
            return true;
        }
        return false;
    };
    auto set_ip2 = [&](std::string& host, int ip) {
        if (un_alloc_ip.count(ip)) {
            un_alloc_ip.erase(ip);
        } else if (exp_ip.count(ip)) {
            exp_ip.erase(ip);
        } else if (will_alloc_ip.count(ip)) {
            will_alloc_ip.erase(ip);
        }
        alloc_ip.insert(ip);
        if (host_ip.count(host) and ip_host.count(host_ip[host])) {
            ip_host.erase(host_ip[host]);
        }
        if (ip_host.count(ip)) {
            std::string tmp = ip_host[ip];
            host_ip.erase(tmp);
        }
        host_ip[host] = ip;
        ip_host[ip] = host;
    };
    std::set<std::pair<int, int>> pool;
    for (int i = 1; i <= N; i++) {
        un_alloc_ip.insert(i);
    }
    while (n--) {
        int t;
        std::cin >> t;

        while (pool.size() and pool.begin()->first <= t) {
            int ip = pool.begin()->second;
            if (exp_time[ip] > t) {
                pool.erase(pool.begin());
                continue;
            }

            if (alloc_ip.count(ip)) {
                alloc_ip.erase(ip);
                exp_ip.insert(ip);
            } else if (will_alloc_ip.count(ip)) {
                will_alloc_ip.erase(ip);
                un_alloc_ip.insert(ip);
                if (ip_host.count(ip)) {
                    host_ip.erase(ip_host[ip]);
                    ip_host.erase(ip);
                }
            }
            exp_time[ip] = 0;
            pool.erase(pool.begin());
        }
        std::string sender, receiver, type;
        int ip, ttl;
        std::cin >> sender >> receiver >> type >> ip >> ttl;
        if (receiver != H and receiver != "*" and type != "REQ") {
            continue;
        } else if (type != "REQ" and type != "DIS") {
            continue;
        } else if (receiver == "*" and type != "DIS" or
                   receiver == H and type == "DIS") {
            continue;
        }
        if (type == "DIS") {
            if (receiver != "*") {
                continue;
            }

            int res_ip = get_ip(sender, ip);
            if (res_ip == -1) {
                continue;
            }
            set_ip1(sender, res_ip);
            int res_ttl = set_ttl(t, ttl);
            pool.insert({res_ttl, res_ip});
            send_offer(sender, res_ip, res_ttl);
            exp_time[res_ip] = res_ttl;

        } else if (type == "REQ") {
            if (receiver != H) {
                clear_ip(sender);
                continue;
            }
            if (take_ip(sender, ip)) {
                send_nak(sender, ip, 0);
                continue;
            }
            set_ip2(sender, ip);
            int res_ttl = set_ttl(t, ttl);
            pool.insert({res_ttl, ip});
            send_ack(sender, ip, res_ttl);
            exp_time[ip] = res_ttl;
        }
    }

    return 0;
}