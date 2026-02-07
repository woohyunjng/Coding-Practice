#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")

using namespace std;

typedef array<int, 2> pr;
typedef long long ll;

const int MAX = 300001;
const int BUCKET = 1000;

int A[MAX], C[MAX], L[MAX], R[MAX], B[MAX];
ll ans[MAX], P[MAX][2];
set<int> st;

void update(int x, int v) {
    if (B[C[x]] == 1)
        st.erase(st.find(C[x]));
    B[C[x]]--;

    C[x] += v, B[C[x]]++;
    if (B[C[x]] == 1)
        st.insert(C[x]);
}

ll calc(vector<pr> &arr, int V) {
    ll S = 0, res = 0, K;
    for (pr i : arr) {
        K = V - i[0];
        res += S * S * i[1];
        res += 2 * S * i[0] * P[i[1] - 1][0];
        res += (ll)i[0] * i[0] * P[i[1] - 1][1];
        res -= S * K * i[1];
        res -= (ll)i[0] * K * P[i[1] - 1][0];
        S += (ll)i[0] * i[1];
    }
    return res * 2;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, S, PL, PR;
    ll K, V;
    vector<int> comp, queries;
    vector<pr> arr, larr, rarr;

    arr.reserve(10000), larr.reserve(10000), rarr.reserve(10000);

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> A[i], comp.push_back(A[i]);

    for (int i = 1; i <= N; i++)
        P[i][0] = P[i - 1][0] + i, P[i][1] = P[i - 1][1] + (ll)i * i;

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();
    for (int i = 1; i <= N; i++)
        A[i] = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin() + 1;

    for (int i = 1; i <= S; i++)
        B[0]++;
    st.insert(0);

    for (int i = 1; i <= Q; i++)
        cin >> L[i] >> R[i], queries.push_back(i);

    sort(queries.begin(), queries.end(), [&](int x, int y) {
        if (L[x] / BUCKET != L[y] / BUCKET)
            return L[x] < L[y];
        if ((L[x] / BUCKET) & 1)
            return R[x] > R[y];
        return R[x] < R[y];
    });

    update(A[1], 1), PL = PR = 1;
    for (int i : queries) {
        while (PL > L[i])
            update(A[--PL], 1);
        while (PR < R[i])
            update(A[++PR], 1);
        while (PL < L[i])
            update(A[PL++], -1);
        while (PR > R[i])
            update(A[PR--], -1);
        V = R[i] - L[i] + 1;

        arr.clear(), K = S;
        for (int i : st) {
            if (i == 0) {
                K -= B[i];
                continue;
            }
            arr.push_back({i, B[i]});
        }
        ans[i] = (ll)V * V * K + V;

        for (pr j : arr) {
            ans[i] -= (ll)(V - j[0]) * (V - j[0]) * j[1];
            if (j[1] == 1)
                larr.push_back({j[0], 1});
            else {
                larr.push_back({j[0], (j[1] + 1) / 2});
                rarr.push_back({j[0], j[1] / 2});
            }
            if (j[1] & 1)
                swap(larr, rarr);
        }

        ans[i] -= calc(larr, V), larr.clear();
        ans[i] -= calc(rarr, V), rarr.clear();
    }

    for (int i = 1; i <= Q; i++)
        cout << ans[i] / 2 << '\n';

    return 0;
}