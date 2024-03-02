#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 2020

static unsigned long next = 1;
int mod;

/* RAND_MAX assumed to be 32767 */
int myrand(void) {
    next = next * 1103515245 + 12345;
    return ((unsigned)(next / 65536) % 32768);
}

int h[size], e[size], ne[size], idx, D[size];
double w[size];
double u[size], v[size], a[size], b[size], c[size], d[size];
double r[size];
double I[1024][1024];
int cnt[1024];
void add(int a, int b, double tw, int td) {
    e[idx] = b, ne[idx] = h[a], w[idx] = tw, D[idx] = td;
    h[a] = idx++;
}

void biu(int x, int time) {
    for (int i = h[x]; ~i; i = ne[i]) {
        int j = e[i];
        I[(time + D[i]) % mod][j] += w[i];
    }
}

int main() {
    memset(h, -1, sizeof h);
    int N, S, P, T;
    scanf("%d %d %d %d", &N, &S, &P, &T);
    double deltat;
    scanf("%lf", &deltat);
    int sm = 0;
    while (sm < N) {
        int RN;
        scanf("%d", &RN);
        double tu, tv, ta, tb, tc, td;
        scanf("%lf %lf %lf %lf %lf %lf", &tv, &tu, &ta, &tb, &tc, &td);
        for (int i = sm; i < sm + RN; ++i) {
            u[i] = tu;
            v[i] = tv;
            a[i] = ta;
            b[i] = tb;
            c[i] = tc;
            d[i] = td;
        }
        sm += RN;
    }
    for (int i = sm; i < P + N; i++) {
        int tr;
        scanf("%d", &tr);
        r[i] = tr;
    }

    for (int i = 0; i < S; i++) {
        int s, t, d;
        double W;
        scanf("%d %d %lf %d", &s, &t, &W, &d);
        add(s, t, W, d);
        if(d + 1 > mod) mod = d + 1;
    }
    for (int i = 1; i <= T; i++) {
        int tt = i % mod;
        for (int j = N; j < N + P; ++j) {
            int val = myrand();
            if (r[j] > val) {
                biu(j, tt);
            }
        }
        for (int j = 0; j < N; ++j) {
            double v1 = v[j];
            double u1 = u[j];
            v[j] =
                v1 + deltat * (0.04 * v1 * v1 + 5 * v1 + 140 - u1) + I[tt][j];
            u[j] = u1 + deltat * a[j] * (b[j] * v1 - u1);
            I[tt][j] = 0;
            if (v[j] >= 30) {
                cnt[j]++;
                biu(j, tt);
                v[j] = c[j], u[j] += d[j];
            }
        }
        // printf("%.3f\n", v[0]);
    }
    double vmin = v[0], vmax = v[0];
    int cmin = cnt[0], cmax = cnt[0];
    for (int i = 0; i < N; i++) {
        if (v[i] < vmin) vmin = v[i];
        if (v[i] > vmax) vmax = v[i];
        if (cnt[i] < cmin) cmin = cnt[i];
        if (cnt[i] > cmax) cmax = cnt[i];
    }
    printf("%.3lf %.3lf\n%d %d\n", vmin, vmax, cmin, cmax);
    return 0;
}