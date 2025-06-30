#include <bits/stdc++.h>
#define int long long
using namespace std;

int cnt(int X) {
    if (X < 1)
        return 0;
    int res = 0, K = (int)sqrt(X), V;
    for (int i = 1; i <= K; i++)
        res += X / i * (i & 1 ? -1 : 1);
    for (int i = 1; i < X / K; i++) {
        V = X / i - X / (i + 1);
        res += ((X / i) & 1 ? -1 : 1) * (V & 1 ? i : 0);
    }
    return res;
}

signed main() {
    int S, T;
    cin >> S >> T;
    cout << cnt(T) - cnt(S - 1) << '\n';
    return 0;
}