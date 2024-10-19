#include <bits/stdc++.h>
#define int long long

#define MAX 250100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], val[MAX], nxt[MAX], sparse[MAX][20][2], sm[MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, L, R, res, X;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 2; i <= N; i++) {
        X = A[i];
        if (A[i] > A[i - 1]) {
            while (A[i - 1] <= (X >> 1))
                X >>= 1, val[i]--;
        } else {
            while (A[i - 1] > X)
                X <<= 1, val[i]++;
        }
    }

    stack<pr> st;

    for (int i = 1; i <= N; i++) {
        sm[i][0] = sm[i - 1][0] + val[i];
        sm[i][1] = sm[i - 1][1] + sm[i][0];
    }

    nxt[N] = N + 1;
    for (int i = N; i >= 1; i--) {
        X += val[i];
        while (!st.empty() && st.top().first <= X)
            st.pop();

        if (st.empty())
            nxt[i - 1] = N + 1;
        else
            nxt[i - 1] = st.top().second - 1;

        st.push({X, i});
    }

    if (val[N] < 0)
        nxt[N - 1] = N;

    for (int i = N; i >= 1; i--) {
        sparse[i][0][0] = nxt[i];
        sparse[i][0][1] = sm[nxt[i] - 1][1] - sm[i][1] - sm[i][0] * (nxt[i] - i - 1);

        for (int j = 1; j <= 19; j++) {
            if (sparse[sparse[i][j - 1][0]][j - 1][0] == 0)
                break;
            sparse[i][j][0] = sparse[sparse[i][j - 1][0]][j - 1][0];
            sparse[i][j][1] = sparse[i][j - 1][1] + sparse[sparse[i][j - 1][0]][j - 1][1];
        }
    }

    while (Q--) {
        cin >> L >> R;
        res = 0;

        for (int i = 19; i >= 0; i--) {
            if (sparse[L][i][0] != 0 && sparse[L][i][0] <= R) {
                res += sparse[L][i][1];
                L = sparse[L][i][0];
            }
        }

        if (R == N + 1)
            R--;
        if (L < R)
            res += sm[R][1] - sm[L][1] - sm[L][0] * (R - L);

        cout << res << '\n';
    }

    return 0;
}