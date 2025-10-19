#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 250001;

int P[MAX], S[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> P[i], S[i] = S[i - 1] + P[i];

    for (int i = 0; i <= N; i++) {
        pq.push(S[i]), pq.push(S[i]);
        ans += S[i] - pq.top(), pq.pop();
    }

    cout << ans << '\n';

    return 0;
}