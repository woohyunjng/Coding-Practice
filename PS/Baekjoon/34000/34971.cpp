#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 4> tp;

const int MAX = 1001;
const int MOD = 998244353;

int A[MAX][MAX], T[MAX * MAX];
bool chk[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, N, X, ans;
    bool flag;

    tp K;
    priority_queue<tp> pq;

    T[0] = 1;
    for (int i = 1; i < MAX * MAX; i++)
        T[i] = (T[i - 1] * 2) % MOD;

    cin >> Q;
    while (Q--) {
        cin >> N, ans = 0;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                cin >> A[i][j], ans = (ans + T[A[i][j]]) % MOD, chk[i][j] = false;

        for (int i = 1; i <= N; i++) {
            X = 0;
            for (int j = 1; j <= N; j++)
                if (X == 0 || A[i][j] < A[i][X])
                    X = j;
            pq.push({A[i][X], i, X, 0});
        }

        for (int j = 1; j <= N; j++) {
            X = 0;
            for (int i = 1; i <= N; i++)
                if (X == 0 || A[i][j] < A[X][j])
                    X = i;
            pq.push({A[X][j], X, j, 1});
        }

        while (!pq.empty()) {
            K = pq.top(), pq.pop();
            flag = chk[K[1]][K[2]];

            for (int i = 1; i <= N; i++) {
                if (K[3] == 0)
                    flag |= chk[K[1]][i];
                else
                    flag |= chk[i][K[2]];
            }

            if (!flag) {
                chk[K[1]][K[2]] = true;
                ans = (ans - N * T[K[0]] % MOD + MOD) % MOD;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}