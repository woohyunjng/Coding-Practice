#include <bits/stdc++.h>
#define int long long

#define MAX 15
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int B[MAX], P[50], val[1 << MAX], dp[1 << MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, C, X, Y;
    vector<int> arr;
    cin >> N >> C;

    for (int i = 0; i < N; i++)
        cin >> B[i];
    for (int i = 0; i <= C; i++)
        cin >> P[i];

    for (int i = 0; i < (1 << N); i++) {
        X = 0;
        for (int j = 0; j < N; j++)
            if (i & (1 << j))
                X += B[j];
        val[i] = P[X % C] + P[C] * (X / C) + P[0] * ((int)__builtin_popcount(i) - 1 - X / C);
    }

    for (int i = 1; i < (1 << N); i++) {
        for (int j = 0; j < N; j++)
            if (i & (1 << j))
                arr.push_back(1 << j);
        X = arr.size();
        for (int j = 0; j < (1 << X); j++) {
            Y = 0;
            for (int k = 0; k < X; k++)
                if (j & (1 << k))
                    Y |= arr[k];
            dp[i] = max(dp[i], dp[Y] + val[i ^ Y]);
        }
        arr.clear();
    }

    cout << dp[(1 << N) - 1] << '\n';

    return 0;
}