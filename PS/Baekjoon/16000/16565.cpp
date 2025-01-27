#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 10007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int comb[100][100];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0;
    cin >> N;

    comb[0][0] = 1;
    for (int i = 1; i < 100; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            comb[i][j] %= MOD;
        }
    }

    for (int i = 1; i * 4 <= N; i++)
        res = (res + comb[52 - i * 4][N - i * 4] * comb[13][i] * (i % 2 ? 1 : -1) + MOD * MOD) % MOD;

    cout << res;

    return 0;
}