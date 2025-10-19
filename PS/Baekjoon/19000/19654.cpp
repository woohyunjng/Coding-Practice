#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 200001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX], B[MAX];
bool vst[2][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, K, L, ans, val, V, Y, Z;

    priority_queue<pr> pq[5];
    pr X[5];

    cin >> T;
    while (T--) {
        for (int i = 0; i < 5; i++)
            pq[i].push({-INF, 0});

        cin >> N >> K >> L, L = K - L, ans = 0;
        for (int i = 1; i <= N; i++)
            cin >> A[i];

        for (int i = 1; i <= N; i++) {
            cin >> B[i];
            pq[0].push({A[i] + B[i], i}), pq[1].push({A[i], i}), pq[2].push({B[i], i});
        }

        for (int i = 1; i <= K; i++) {
            for (int j = 1; j < 5; j++)
                while (vst[j & 1 ^ 1][pq[j].top()[1]])
                    pq[j].pop();
            while (vst[0][pq[0].top()[1]] || vst[1][pq[0].top()[1]])
                pq[0].pop();

            for (int j = 0; j < 5; j++)
                X[j] = pq[j].top();
            val = X[0][0], V = 1;

            if (val < X[3][0] + X[4][0])
                val = X[3][0] + X[4][0], V = 3;
            if (val < X[3][0] + X[2][0])
                val = X[3][0] + X[2][0], V = 4;
            if (val < X[1][0] + X[4][0])
                val = X[1][0] + X[4][0], V = 5;
            if (X[1][1] != X[2][1] && L > 0 && val < X[1][0] + X[2][0])
                val = X[1][0] + X[2][0], V = 2;

            ans += val;

            if (V == 1)
                Y = X[0][1], Z = X[0][1];
            else if (V == 2)
                Y = X[1][1], Z = X[2][1], L--;
            else if (V == 3)
                Y = X[3][1], Z = X[4][1], L++;
            else if (V == 4)
                Y = X[3][1], Z = X[2][1];
            else
                Y = X[1][1], Z = X[4][1];

            vst[0][Y] = true, vst[1][Z] = true;
            if (!vst[1][Y])
                pq[4].push({B[Y], Y});
            if (!vst[0][Z])
                pq[3].push({A[Z], Z});
        }

        cout << ans << '\n';

        for (int i = 0; i < 5; i++)
            while (!pq[i].empty())
                pq[i].pop();
        fill(vst[0], vst[0] + N + 1, false), fill(vst[1], vst[1] + N + 1, false);
    }

    return 0;
}