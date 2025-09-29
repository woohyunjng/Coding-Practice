#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 31;
const int DEF = 40000;
const int MAX_W = 80001;

bitset<MAX_W> dp[MAX];
int W[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> W[i];

    dp[0][DEF] = 1;
    for (int i = 1; i <= N; i++)
        dp[i] = dp[i - 1] | (dp[i - 1] << W[i]) | (dp[i - 1] >> W[i]);

    cin >> Q;
    while (Q--) {
        cin >> X, X += DEF;
        cout << (dp[N][X] ? 'Y' : 'N') << ' ';
    }
    cout << '\n';

    return 0;
}