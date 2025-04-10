#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;

int U[MAX], V[MAX], D[MAX], T[MAX], X[MAX], Y[MAX], parent[MAX], sz[MAX], ans[MAX];
bool chk[MAX];
vector<int> rollback_st, arr[MAX];

int find(int X) { return parent[X] == X ? X : find(parent[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    if (sz[X] < sz[Y])
        swap(X, Y);
    rollback_st.push_back(Y);
    sz[X] += sz[Y], parent[Y] = X;
}

void rollback() {
    int K = rollback_st.back();
    rollback_st.pop_back();
    sz[parent[K]] -= sz[K], parent[K] = K;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q, K, B, cnt;

    cin >> N >> M;
    for (int i = 1; i <= M; i++)
        cin >> U[i] >> V[i] >> D[i];

    cin >> Q;
    for (int i = 1; i <= Q; i++)
        cin >> T[i] >> X[i] >> Y[i];

    vector<int> chng, query, edge;

    B = (int)sqrt(Q);

    for (int i = 1; i <= Q; i += B) {
        chng.clear(), query.clear(), edge.clear(), rollback_st.clear();
        K = min(i + B - 1, Q);

        for (int i = 1; i <= N; i++)
            parent[i] = i, sz[i] = 1;
        fill(chk + 1, chk + M + 1, false);

        for (int j = i; j <= K; j++) {
            if (T[j] == 1)
                chk[X[j]] = true, chng.push_back(X[j]);
            else
                query.push_back(j), arr[j - i].clear();
        }

        for (int j = i; j <= K; j++) {
            if (T[j] == 1)
                D[X[j]] = Y[j];
            else {
                for (int k : chng)
                    if (D[k] >= Y[j])
                        arr[j - i].push_back(k);
            }
        }
        for (int j = 1; j <= M; j++)
            if (!chk[j])
                edge.push_back(j);

        sort(query.begin(), query.end(), [&](int x, int y) { return Y[x] > Y[y]; });
        sort(edge.begin(), edge.end(), [&](int x, int y) { return D[x] > D[y]; });

        K = 0;
        for (int j : query) {
            while (K < edge.size() && D[edge[K]] >= Y[j])
                uni(U[edge[K]], V[edge[K]]), K++;

            cnt = 0;
            for (int k : arr[j - i]) {
                if (find(U[k]) == find(V[k]))
                    continue;
                uni(U[k], V[k]), cnt++;
            }
            ans[j] = sz[find(X[j])];
            while (cnt--)
                rollback();
        }
    }

    for (int i = 1; i <= Q; i++)
        if (T[i] == 2)
            cout << ans[i] << '\n';

    return 0;
}