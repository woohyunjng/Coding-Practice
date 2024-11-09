#include <bits/stdc++.h>
#define int long long

#define MAX 110
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    bool flag;
    string S;

    cin >> N >> K >> S;

    for (int i = K; i <= N; i++) {
        flag = true;
        for (int j = i - K + 1; j <= i; j++)
            flag = flag && (S[j - 1] == 'O');
        dp[i] = dp[i - 1];
        if (flag)
            dp[i] = max(dp[i], dp[i - K] + 1);
    }

    cout << dp[N];

    return 0;
}