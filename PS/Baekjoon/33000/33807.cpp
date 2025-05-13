#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int MOD = 998244353;

int fpow(int N, int K) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = (res * N) % MOD;
        N = (N * N) % MOD, K >>= 1;
    }
    return res;
}

int in[MAX], V[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, X, Y, ans = 0;

    vector<int> arr;

    cin >> N >> M >> K;
    while (M--)
        cin >> X >> Y, in[Y]++;

    for (int i = 1; i <= N; i++)
        if (in[i] != 0)
            arr.push_back(in[i]);

    sort(arr.begin(), arr.end()), arr.erase(unique(arr.begin(), arr.end()), arr.end());
    for (int i : arr) {
        for (int j = 1; j <= K; j++)
            V[i] = (V[i] + fpow(j, i)) % MOD;
        V[i] = V[i] * fpow(fpow(K, i), MOD - 2) % MOD;
    }

    for (int i = 1; i <= N; i++)
        ans = (ans + V[in[i]]) % MOD;

    cout << ans << '\n';

    return 0;
}