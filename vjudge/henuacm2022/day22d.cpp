#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 1e5 + 10;

vector<ll> B;

void insert(ll x) {
    for (auto b : B)
        x = min(x, b ^ x);
    for (auto &b : B)
        b = min(b, b ^ x);
    if (x)
        B.push_back(x);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(), cout.tie();

    int n;
    ll x;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x, insert(x);

    ll v = 0;
    for (auto b: B)
        v = max(v, v ^ b);

    cout << v << endl;
}