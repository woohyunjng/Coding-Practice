#include <bits/stdc++.h>
using namespace std;

typedef array<int, 3> tp;

const int MAX = 1500;

int A[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans;
    tp K;

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    priority_queue<tp, vector<tp>, greater<tp>> pq;
    for (int i = 0; i < N; i++)
        pq.push({A[0][i], 0, i});

    for (int i = 0; i < N * N - N + 1; i++) {
        K = pq.top(), pq.pop(), ans = K[0];
        if (K[1] + 1 < N)
            pq.push({A[K[1] + 1][K[2]], K[1] + 1, K[2]});
    }

    cout << ans << '\n';

    return 0;
}