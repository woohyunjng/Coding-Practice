#include <bits/stdc++.h>
#define int long long

#define MAX 800
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX][MAX];
bitset<MAX> dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0;
    string S;
    cin >> N;

    for (int i = 1; i < N; i++) {
        cin >> S;
        for (int j = i + 1; j <= N; j++)
            arr[i][j] = S[j - i - 1] - '0';
    }

    for (int i = N; i >= 1; i--) {
        for (int j = i + 1; j <= N; j++) {
            if (arr[i][j] == 0)
                continue;
            dp[i] ^= dp[j];
        }

        res += dp[i].count();
        dp[i] |= bitset<MAX>("1" + string(i, '0'));
    }

    cout << res;

    return 0;
}