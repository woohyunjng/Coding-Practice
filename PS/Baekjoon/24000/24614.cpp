#include <bits/stdc++.h>
#define int long long

#define MAX 20
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int adj[MAX], dp[MAX][1 << MAX], res[1 << MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, Y;
    pr K;
    bool flag;

    string S;

    cin >> N;

    for (int i = 0; i < N; i++) {
        flag = true;
        for (int j = 0; j < N; j++) {
            cin >> X;
            --X;
            if (flag)
                adj[i] |= (1 << X);
            flag = flag && (X != i);
        }
    }

    res[0] = 1;
    for (int i = 0; i < N; i++)
        dp[i][1 << i] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = (1 << i); j < (1 << (i + 1)); j++) {
            for (int k = 0; k <= i; k++) {
                if (!(j & (1 << k)))
                    continue;
                if (adj[k] & (1 << i))
                    res[j] += dp[k][j];
                for (int x = 0; x < i; x++) {
                    if (!(adj[k] & (1 << x)) || (j & (1 << x)))
                        continue;
                    dp[x][j | (1 << x)] += dp[k][j];
                }
            }

            for (int k = i + 1; k < N; k++)
                dp[k][j | (1 << k)] += res[j];
        }
    }

    cin >> Q;
    while (Q--) {
        cin >> S;
        X = 0, Y = 0;

        for (int i = 0; i < N; i++) {
            if (S[i] == 'H')
                X |= (1 << i);
            else
                Y |= (1 << i);
        }

        cout << res[X] * res[Y] << '\n';
    }

    return 0;
}