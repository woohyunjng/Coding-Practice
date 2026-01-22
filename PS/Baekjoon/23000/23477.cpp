#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 200001;

int K, N,
    A[MAX], S[MAX], PS[MAX][2], V[MAX],
    L[MAX], R[MAX], ans[MAX];
vector<pr> arr[MAX][2];
set<pr> st;

int calc(int L, int X) {
    int P = min(X - L, V[X]), res;
    res = (P + 1) * (K - (S[X + P] - S[X - P - 1]));
    res += PS[X - 1][1] - PS[X - P - 1][1] - (S[X - 1] - S[X - P - 1]) * (N + 1 - X);
    res += PS[X + P][0] - PS[X][0] - (S[X + P] - S[X]) * X;
    return res;
}

int fetch(int X) {
    set<pr>::iterator iter = prev(st.lower_bound({X + 1, -1}));
    return (*iter)[1];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, P;
    set<pr>::iterator iter;

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> L[i] >> R[i];
        arr[(R[i] + L[i]) / 2][0].push_back({i, L[i]});
        arr[N - (R[i] + L[i]) / 2][1].push_back({i, N + 1 - R[i]});
    }

    for (int t = 0; t < 2; t++) {
        for (int i = 1; i <= N; i++) {
            S[i] = A[i] + S[i - 1];
            PS[i][0] = A[i] * i + PS[i - 1][0];
            PS[i][1] = A[i] * (N + 1 - i) + PS[i - 1][1];
        }

        for (int i = 1; i <= N; i++) {
            V[i] = 0;
            for (int st = 1, en = min(N - i, i - 1), md; st <= en;) {
                md = st + en >> 1;
                if (S[i + md] - S[i - md - 1] <= K)
                    st = md + 1, V[i] = md;
                else
                    en = md - 1;
            }
        }

        for (int i = 1; i <= N; i++) {
            st.insert({i, i}), P = i;
            for (int st = 1, en = i, md; st <= en;) {
                md = st + en >> 1;
                if (calc(md, i) >= calc(md, fetch(md)))
                    en = md - 1, P = md;
                else
                    st = md + 1;
            }
            iter = prev(st.lower_bound({P + 1, -1}));
            while (!st.empty() && (*st.rbegin())[0] >= P)
                st.erase(prev(st.end()));
            st.insert({P, i});

            for (pr j : arr[i][t])
                ans[j[0]] = max(ans[j[0]], calc(j[1], fetch(j[1])));
        }

        reverse(A + 1, A + N + 1), st.clear();
    }

    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';

    return 0;
}