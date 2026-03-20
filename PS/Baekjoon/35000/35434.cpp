#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000002;
const int MAX_LOG = 21;

int A[MAX], V[MAX], S[MAX],
    sparse[MAX_LOG][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, ans = 0, X, Y, Z;
    multiset<int> st;

    cin >> N >> K, fill(V + 1, V + K + 1, N << 1 | 1);
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= K; i++)
        st.insert(V[i]);

    for (int i = 1; i <= N + 2; i++)
        sparse[0][i] = min(N + 2, i + 1);
    for (int i = N; i >= 1; i--)
        st.erase(st.find(V[A[i]])), V[A[i]] = N + i, st.insert(V[A[i]]);
    for (int i = N; i >= 1; i--) {
        st.erase(st.find(V[A[i]])), V[A[i]] = i, st.insert(V[A[i]]);
        S[i] = *st.rbegin() + 1, sparse[0][i] = min(N + 2, S[i]);
    }

    for (int i = 1; i < MAX_LOG; i++)
        for (int j = 1; j <= N + 2; j++)
            sparse[i][j] = sparse[i - 1][sparse[i - 1][j]];

    for (int i = 1; i <= N; i++) {
        if (S[i] > (N << 1) + 1)
            continue;
        if (i == 1)
            X = S[i], Y = N;
        else if (S[i] > N + 1)
            X = S[i] - N, Y = i - 1;
        else
            continue;

        Z = 0;
        for (int j = MAX_LOG - 1; j >= 0; j--)
            if (sparse[j][X] - 1 <= Y)
                X = sparse[j][X], Z += 1 << j;
        ans = max(ans, Z + 1);
    }

    cout << ans << '\n';

    return 0;
}