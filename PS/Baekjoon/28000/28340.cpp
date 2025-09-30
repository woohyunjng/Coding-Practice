#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, K, X, ans;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> T;
    while (T--) {
        cin >> N >> K, ans = 0;
        for (int i = 0; i < N; i++)
            cin >> X, pq.push(X);

        while (K != 2 && pq.size() % (K - 1) != 1)
            pq.push(0);

        while (pq.size() > 1) {
            X = 0;
            for (int i = 0; i < K; i++)
                if (!pq.empty())
                    X += pq.top(), pq.pop();
            ans += X, pq.push(X);
        }

        cout << ans << '\n';

        while (!pq.empty())
            pq.pop();
    }

    return 0;
}