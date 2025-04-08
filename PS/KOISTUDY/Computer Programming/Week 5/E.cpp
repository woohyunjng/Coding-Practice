#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1000000007;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, X;

    queue<int> q;

    cin >> N >> M >> K;

    q.push(1);

    while (K--) {
        X = q.front(), q.pop();
        q.push(X * N % MOD), q.push(X * M % MOD);
    }

    cout << q.front() << '\n';
}