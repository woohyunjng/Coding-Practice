#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 250002;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX], B[MAX], C[MAX], D[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ST[2], EN[2], F[2], X, Y, ans = INF;
    bool flag;
    vector<int> arr;

    set<pr> st;
    set<pr>::iterator it;

    cin >> N >> ST[0] >> ST[1] >> EN[0] >> EN[1];
    F[0] = EN[0] - ST[0] < 0 ? -1 : 1, F[1] = EN[1] - ST[1] < 0 ? -1 : 1;
    A[N + 1] = EN[0], B[N + 1] = EN[1], C[N + 1] = EN[0], D[N + 1] = EN[1];

    for (int i = 1; i <= N + 1; i++) {
        if (i <= N)
            cin >> A[i] >> B[i] >> C[i] >> D[i];

        arr.push_back(i);
        A[i] -= ST[0], B[i] -= ST[1], C[i] -= ST[0], D[i] -= ST[1];
        A[i] *= F[0], B[i] *= F[1], C[i] *= F[0], D[i] *= F[1];
        if (A[i] > C[i])
            swap(A[i], C[i]);
        if (B[i] > D[i])
            swap(B[i], D[i]);
    }

    for (int t = 0; t < 2; t++) {
        for (int i = 1; i <= N + 1; i++)
            swap(A[i], B[i]), swap(C[i], D[i]);
        sort(arr.begin(), arr.end(), [&](int x, int y) { return A[x] < A[y]; });
        st.clear();

        st.insert({0, 0});
        for (int i : arr) {
            if (C[i] > C[N + 1] || C[i] <= 0)
                continue;

            X = Y = INF;
            for (it = st.lower_bound({B[i], 0}); it != st.end() && (*it)[0] <= D[i]; it = st.erase(it)) {
                X = min(X, (*it)[0] - B[i] + (*it)[1]);
                Y = min(Y, D[i] - (*it)[0] + (*it)[1]);
            }
            if (X != INF && B[i] != D[i])
                st.insert({B[i], X}), st.insert({D[i], Y});

            if (i == N + 1 && !st.empty() && (*st.begin())[0] <= B[i] && (*st.rbegin())[0] >= D[i]) {
                for (pr j : st)
                    ans = min(ans, j[1] + abs(j[0] - B[i]) + A[i]);
            }
        }
    }

    if (ans == INF)
        ans = A[N + 1] + B[N + 1];

    cout << ans << '\n';

    return 0;
}