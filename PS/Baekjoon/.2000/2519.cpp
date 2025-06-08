#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 6001;

int X[MAX][2], Y[MAX][2], D[MAX], cnt;
bool vst[MAX];

vector<int> adj[MAX], rvt_adj[MAX], st, ans;

void dfs1(int node) {
    vst[node] = true;
    for (int i : adj[node])
        if (!vst[i])
            dfs1(i);
    st.push_back(node);
}

void dfs2(int node) {
    D[node] = cnt;
    for (int i : rvt_adj[node])
        if (!D[i])
            dfs2(i);
}

int CCW(pr A, pr B, pr C) {
    int val = (B[0] - A[0]) * (C[1] - A[1]) - (C[0] - A[0]) * (B[1] - A[1]);
    if (val > 0)
        return 1;
    else if (val < 0)
        return -1;
    else
        return 0;
}

bool is_intersect(pr A, pr B, pr C, pr D) {
    int AtoC = CCW(A, B, C) * CCW(A, B, D);
    int CtoA = CCW(C, D, A) * CCW(C, D, B);

    if (AtoC == 0 && CtoA == 0) {
        if (A > B)
            swap(A, B);
        if (C > D)
            swap(C, D);
        return C <= B && A <= D;
    }

    return AtoC <= 0 && CtoA <= 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    bool flag = true;

    cin >> N;
    for (int i = 1; i <= N * 3; i++)
        cin >> X[i][0] >> Y[i][0] >> X[i][1] >> Y[i][1];

    for (int i = 1; i <= N * 3; i++)
        for (int j = i + 1; j <= N * 3; j++) {
            if (!is_intersect({X[i][0], Y[i][0]}, {X[i][1], Y[i][1]}, {X[j][0], Y[j][0]}, {X[j][1], Y[j][1]}))
                continue;
            adj[i * 2 - 1].push_back(j * 2), adj[j * 2 - 1].push_back(i * 2);
            rvt_adj[j * 2].push_back(i * 2 - 1), rvt_adj[i * 2].push_back(j * 2 - 1);
        }

    for (int i = 1; i <= N; i++)
        for (int j = i * 3 - 2; j <= i * 3; j++)
            for (int k = j + 1; k <= i * 3; k++) {
                adj[j * 2].push_back(k * 2 - 1), adj[k * 2].push_back(j * 2 - 1);
                rvt_adj[k * 2 - 1].push_back(j * 2), rvt_adj[j * 2 - 1].push_back(k * 2);
            }

    for (int i = 1; i <= N * 6; i++)
        if (!vst[i])
            dfs1(i);

    while (!st.empty()) {
        K = st.back(), st.pop_back();
        if (!D[K])
            cnt++, dfs2(K);
    }

    for (int i = 1; i <= N * 3; i++)
        flag &= D[i * 2] != D[i * 2 - 1];

    if (!flag)
        cout << -1 << '\n';
    else {
        for (int i = 1; i <= N * 3; i++)
            if (D[i * 2] > D[i * 2 - 1])
                ans.push_back(i);
        cout << ans.size() << '\n';
        for (int i : ans)
            cout << i << ' ';
        cout << '\n';
    }

    return 0;
}