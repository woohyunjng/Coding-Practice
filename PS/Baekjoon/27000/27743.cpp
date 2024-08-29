#include <bits/stdc++.h>
#define int long long

#define MAX 200100
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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, res;
    cin >> N >> M;

    if (M != 1) {
        res = (fpow(2, N) - 1 + MOD) % MOD;
        res = (res * 2 * M - 1 + MOD) % MOD;
    } else
        res = (fpow(2, N) - 1 + MOD) % MOD;

    cout << res;

    return 0;
}