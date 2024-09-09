#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int res[10], ten[11], zero[10];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string S;
    int N, K;

    cin >> S;
    N = S.size();

    ten[0] = 1;
    for (int i = 1; i <= N; i++)
        ten[i] = ten[i - 1] * 10 % MOD;

    zero[1] = 9;
    for (int i = 2; i <= N; i++) {
        zero[i] = (zero[i - 1] + 9 * i * ten[i - 1]) % MOD;
    }

    for (int i = 0; i < N; i++) {
        K = S[i] - '0';
        if (i != N - 1) {
            for (int j = 1; j < 10; j++) {
                res[j] = (res[j] + K * ten[N - i - 2] * (N - i - 1)) % MOD;
            }
            if (i == 0) {
                res[0] = (res[0] + (K - 1) * ten[N - i - 2] * (N - i - 1)) % MOD;
                res[0] = (res[0] + zero[N - i - 2] + MOD) % MOD;
            } else {
                res[0] = (res[0] + K * ten[N - i - 2] * (N - i - 1)) % MOD;
            }
        }

        for (int j = 0; j < K; j++) {
            if (i == 0 && j == 0)
                continue;
            res[j] = (res[j] + ten[N - i - 1]) % MOD;
        }
        if (i == N - 1)
            res[K] = (res[K] + 1) % MOD;
        else
            res[K] = (res[K] + stoi(S.substr(i + 1)) + 1) % MOD;
    }

    for (int i = 0; i < 10; i++)
        cout << res[i] << ' ';

    return 0;
}