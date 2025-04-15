#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 300001;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X = 0, S = 0, ans = 0;
    pr K;

    vector<pr> L, R;
    deque<pr> dq;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = N; i >= 0; i--) {
        if (A[i] > X)
            R.push_back({i, A[i] - X});
        else if (A[i] < X)
            L.push_back({i, X - A[i]});
        X = A[i];
    }

    sort(L.begin(), L.end()), sort(R.begin(), R.end());
    for (pr i : L)
        dq.push_back(i);

    for (pr i : R) {
        X = i[1], S += i[1];
        while (!dq.empty() && dq.front()[1] <= X)
            X -= dq.front()[1], ans += (i[0] - dq.front()[0]) * (i[0] - dq.front()[0]) * dq.front()[1], dq.pop_front();
        if (!dq.empty()) {
            K = dq.front(), dq.pop_front();
            ans += (i[0] - K[0]) * (i[0] - K[0]) * X, K[1] -= X, dq.push_front(K);
        }
    }

    cout << S << ' ' << ans << '\n';

    return 0;
}