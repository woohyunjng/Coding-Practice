#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int F[MAX], S[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, res = INF, X = 0, i, j;
    deque<pr> dq;
    cin >> N >> M;

    for (i = 1; i <= N; i++)
        cin >> F[i] >> S[i];

    for (j = 1; X < M; j++) {
        X += F[j];
        while (!dq.empty() && dq.back().first <= S[j])
            dq.pop_back();
        dq.push_back({S[j], j});
    }
    res = dq.front().first;

    for (i = 1; j <= N; i++) {
        X -= F[i];
        while (j <= N && X < M) {
            X += F[j];
            while (!dq.empty() && dq.back().first <= S[j])
                dq.pop_back();
            dq.push_back({S[j], j}), j++;
        }
        while (!dq.empty() && dq.front().second <= i)
            dq.pop_front();
        if (X >= M)
            res = min(res, dq.front().first);
    }

    cout << res << '\n';

    return 0;
}