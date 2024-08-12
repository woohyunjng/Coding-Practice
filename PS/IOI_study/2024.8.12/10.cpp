#include <bits/stdc++.h>
#define int long long

#define MAX 1000100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int fpow(int N, int K) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        K >>= 1;
        N = N * N % MOD;
    }
    return res;
}

int dp[MAX], checked[MAX], depth[MAX], go[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B, res = 1;
    pr K;
    bool cycle, connected;

    cin >> N >> M;

    dp[0] = 1, dp[1] = 0;
    for (int i = 2; i <= N; i++) {
        if (M == 1)
            dp[i] = 0;
        else
            dp[i] = (dp[i - 1] * (M - 2) + dp[i - 2] * (M - 1)) % MOD;
    }

    for (int i = 1; i <= N; i++) {
        cin >> A;
        if (A == i)
            continue;
        go[i] = A;
    }

    for (int i = 1; i <= N; i++) {
        if (checked[i])
            continue;

        A = B = 0;
        cycle = connected = false;

        K = {i, 0};
        depth[i] = 1;
        checked[i] = i;

        while (go[K.first]) {
            if (checked[go[K.first]]) {
                if (checked[go[K.first]] == i) {
                    cycle = true;
                    A = depth[K.first];
                    B = depth[K.first] - depth[go[K.first]] + 1;
                } else
                    connected = true;
                break;
            }
            K = {go[K.first], K.first};
            checked[K.first] = i;
            depth[K.first] = depth[K.second] + 1;
        }

        if (!A)
            A = depth[K.first];

        if (!connected) {
            if (cycle) {
                res = res * M % MOD;
                res = res * dp[B] % MOD;
                res = res * fpow(M - 1, A - B) % MOD;
            } else {
                res = res * M % MOD;
                res = res * fpow(M - 1, A - 1) % MOD;
            }
        } else
            res = res * fpow(M - 1, A) % MOD;
    }

    cout << res;

    return 0;
}