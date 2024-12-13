#include <bits/stdc++.h>
#define int long long

#define MAX 19
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N, dp[MAX][1 << MAX], sm[1 << MAX], C[MAX];

void print(int mask) {
    cout << __builtin_popcount(mask) << ' ';
    for (int i = 0; i < N; i++)
        if (mask & (1 << i))
            cout << i + 1 << ' ';
    cout << '\n';
}

signed main() { /*
     ios_base::sync_with_stdio(false);
     cin.tie(0), cout.tie(0);*/

    int W, X, Y, Z;
    vector<pr> arr;
    cin >> N >> W;

    for (int i = 0; i < N; i++)
        cin >> C[i];

    for (int i = 1; i < (1 << N); i++) {
        for (int j = 0; j < N; j++)
            if (i & (1 << j))
                sm[i] += C[j];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < (1 << N); j++) {
            if (sm[j] - dp[i - 1][j] <= W)
                dp[i][j] = sm[j];
            for (int k = 0; k < N; k++)
                if (j & (1 << k))
                    dp[i][j] = max(dp[i][j], dp[i][j ^ (1 << k)]);
        }
    }

    X = 0, Y = (1 << N) - 1;
    while (dp[X][Y] != sm[Y])
        X++;
    cout << X << '\n';

    while (--X) {
        for (int i = 1; i < (1 << N); i++) {
            if ((i & Y) == i && sm[Y] - dp[X][i] <= W) {
                print(Y ^ i), Y = i;
                break;
            }
        }
    }

    print(Y);

    return 0;
}