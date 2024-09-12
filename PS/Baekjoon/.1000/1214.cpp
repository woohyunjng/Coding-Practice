#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int D, P, Q, G, X, res = INF;
    cin >> D >> P >> Q;

    G = gcd(P, Q);
    X = (P / G - 1) * (Q / G - 1);
    if (D >= X * G) {
        X = ceil((double)D / G);
        cout << X * G;
        return 0;
    }

    for (int i = 0; i <= min(Q - 1, D / P); i++) {
        X = ceil((double)(D - i * P) / Q);
        res = min(res, i * P + X * Q);
    }

    for (int i = 0; i <= min(P - 1, D / Q); i++) {
        X = ceil((double)(D - i * Q) / P);
        res = min(res, i * Q + X * P);
    }

    cout << res;

    return 0;
}