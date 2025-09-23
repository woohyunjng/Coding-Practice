#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 1000001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[2][MAX], B[2][MAX], C[2][MAX], S[2][MAX], V[MAX << 1], P[MAX << 1];
vector<int> arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K = 0, X, ans = 0;

    set<pr> st;
    set<pr>::iterator it;
    pr Y;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> A[0][i] >> B[0][i] >> C[0][i], S[0][i] = S[0][i - 1] + A[0][i];
    for (int i = 1; i <= M; i++)
        cin >> A[1][i] >> B[1][i] >> C[1][i], S[1][i] = S[1][i - 1] + A[1][i];

    for (int i = 1; i <= N; i++) {
        if (B[0][i] < S[0][i])
            continue;
        X = upper_bound(S[1] + 1, S[1] + M + 1, B[0][i] - S[0][i]) - S[1];
        if (X <= M)
            arr[X].push_back(++K), P[K] = i, V[K] = C[0][i];
        else
            ans += C[0][i];
    }

    st.insert({0, 0}), st.insert({N + 1, INF});

    for (int i = 1; i <= M; i++) {
        if (B[1][i] < S[1][i])
            continue;
        X = upper_bound(S[0] + 1, S[0] + N + 1, B[1][i] - S[1][i]) - S[0], ans += C[1][i];
        if (X <= N)
            arr[i].push_back(++K), P[K] = X, V[K] = -C[1][i];
    }

    for (int i = 1; i <= M; i++) {
        sort(arr[i].begin(), arr[i].end(), [](int x, int y) { return V[x] > V[y]; });
        for (int j : arr[i]) {
            it = st.lower_bound({P[j], -INF});
            if ((*it)[0] > P[j])
                it = st.insert({P[j], 0}).first;
            V[j] += (*it)[1];

            while (V[j] <= 0)
                it = st.erase(it), V[j] += (*it)[1];
            Y = *it, st.erase(it), st.insert({Y[0], V[j]});
        }
    }

    for (pr i : st)
        ans += i[0] <= N ? i[1] : 0;
    cout << ans << '\n';

    return 0;
}