#include <bits/stdc++.h>
#define int long long

#define MAX 10000100
using namespace std;

int A[MAX], dp[MAX], sm[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    string S;
    deque<int> dq;

    cin >> N >> K >> S;
    for (int i = 1; i <= N; i++)
        A[i] = S[i - 1] == 'G' ? 1 : -1, sm[i] = sm[i - 1] + A[i];

    dq.push_back(0);
    for (int i = 1; i <= N; i++) {
        while (!dq.empty() && dq.front() < i - K)
            dq.pop_front();
        dp[i] = dp[dq.front()] + (sm[dq.front()] <= sm[i]);
        while (!dq.empty() && (dp[dq.back()] > dp[i] || (dp[dq.back()] == dp[i] && sm[dq.back()] <= sm[i])))
            dq.pop_back();
        dq.push_back(i);
    }

    cout << dp[N] << '\n';

    return 0;
}