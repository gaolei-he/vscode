#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iomanip>

using i64 = long long;

constexpr double eps = 1e-8;
int total_id;

static unsigned long next = 1;

/* RAND_MAX assumed to be 32767 */
int myrand(void) {
    next = next * 1103515245 + 12345;
    return ((unsigned)(next / 65536) % 32768);
}

class Node {
   public:
    double I{0};
    int count;
    int id;
    double v, u, a, b, c, d;
    int r;
    Node(int id, double v, double u, double a, double b, double c, double d) {
        this->id = id;
        this->v = v;
        this->u = u;
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        count = 0;
    }
    Node(int id, int r) {
        this->id = id;
        this->r = r;
        count = 0;
    }
};
struct A {
    int t, D;
    double w;
    A(int t, int D, double w) : t(t), D(D), w(w) {}
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, S, P, T;
    std::cin >> N >> S >> P >> T;
    double deltat;
    std::cin >> deltat;

    std::vector<Node> vec;
    int sm = 0;
    while (sm < N) {
        int RN;
        std::cin >> RN;
        double u, v, a, b, c, d;
        std::cin >> v >> u >> a >> b >> c >> d;
        for (int i = sm; i < sm + RN; ++i) {
            vec.emplace_back(i, v, u, a, b, c, d);
        }
        sm += RN;
    }
    for (int i = sm; i < P + N; i++) {
        int r;
        std::cin >> r;
        vec.emplace_back(i, r);
    }
    std::vector<std::vector<A>> g(N + P);
    for (int i = 0; i < S; i++) {
        int s, t, D;
        double w;
        std::cin >> s >> t >> w >> D;
        g[s].emplace_back(t, D, w);
    }
    for(auto &v : g) {
        std::sort(v.begin(), v.end(), [&](A a, A b) { return a.D < b.D;});
    }
    std::unordered_map<int, std::vector<std::pair<double, int>>> st1(T + 1);
    auto calc_st = [&](double t, int idx) {
        for (int i = N; i < N + P; ++i) {
            int val = myrand();
            if (vec[i].r > val) {
                for (auto &p : g[i]) {
                    if(idx + p.D > T) {
                        break;
                    }
                    st1[idx + p.D].emplace_back(p.w, p.t);
                }
            }
        }

        for (auto &p : st1[idx]) {
            vec[p.second].I += p.first;
        }
        st1.erase(idx);
        for (int i = 0; i < N; i++) {
            double v1 = vec[i].v;
            double u1 = vec[i].u;
            vec[i].v =
                v1 + deltat * (0.04 * v1 * v1 + 5 * v1 + 140 - u1) + vec[i].I;
            vec[i].u = u1 + deltat * vec[i].a * (vec[i].b * v1 - u1);
            if (vec[i].v >= 30) {
                vec[i].count += 1;
                for (auto &p : g[i]) {
                    if(idx + p.D > T) {
                        break;
                    }
                    st1[idx + p.D].emplace_back(p.w, p.t);
                }
                vec[i].v = vec[i].c;
                vec[i].u += vec[i].d;
            }
            vec[i].I = 0;
        }
    };

    for (int i = 1; i <= T; ++i) {
        double t = i * deltat;
        calc_st(t, i);
    }

    double vmin = vec.front().v;
    double vmax = vec.front().v;
    int cmin = vec.front().count;
    int cmax = vec.front().count;
    for (int i = 0; i < N; i++) {
        vmin = std::min(vmin, vec[i].v);
        vmax = std::max(vmax, vec[i].v);
        cmin = std::min(cmin, vec[i].count);
        cmax = std::max(cmax, vec[i].count);
    }
    std::cout << std::fixed << std::setprecision(3) << vmin << ' ' << vmax
              << std::endl;
    std::cout << std::fixed << std::setprecision(3) << cmin << ' ' << cmax
              << std::endl;
    return 0;
}