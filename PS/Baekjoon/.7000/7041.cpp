#include <bits/stdc++.h>
#define int long long

#define MAX 1001000
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX], cur[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, L, A, B, S, E, K = 0;
    deque<int> dq[2];

    cin >> N >> L;
    cin >> A >> B;

    while (N--) {
        cin >> S >> E;
        S++, E--;
        cur[S]++, cur[E + 1]--;
    }

    for (int i = 1; i <= L; i++)
        cur[i] += cur[i - 1];

    fill(dp, dp + L + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= L; i++) {
        while (!dq[i & 1].empty() && dq[i & 1].front() < i - 2 * B)
            dq[i & 1].pop_front();

        if (i >= 2 * A && dp[i - 2 * A] != -1) {
            while (!dq[i & 1].empty() && dp[dq[i & 1].front()] >= dp[i - 2 * A])
                dq[i & 1].pop_front();
            dq[i & 1].push_back(i - 2 * A);
        }

        if (cur[i])
            continue;

        if (!dq[i & 1].empty())
            dp[i] = dp[dq[i & 1].front()] + 1;
    }

    cout << dp[L];

    return 0;
}