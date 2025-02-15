#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 200;
const int MAX_NUM = 20000;

int A[MAX][MAX], parent[MAX_NUM], num[MAX_NUM], depth[MAX_NUM];
vector<int> tmp[MAX_NUM], adj[MAX_NUM];
pr go[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int find(int X) { return X == parent[X] ? X : parent[X] = find(parent[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    if (X > Y)
        swap(X, Y);
    parent[Y] = X;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, K, ans = MAX_NUM * 10, S;
    vector<int> comp;
    queue<int> q;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> A[i][j], parent[(i - 1) * M + j] = (i - 1) * M + j;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            for (pr k : go) {
                X = i + k[0], Y = j + k[1];
                if (X <= 0 || X > N || Y <= 0 || Y > M || A[X][Y] != A[i][j])
                    continue;
                uni((i - 1) * M + j, (X - 1) * M + Y);
            }
        }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            for (pr k : go) {
                X = i + k[0], Y = j + k[1];
                if (X <= 0 || X > N || Y <= 0 || Y > M || A[X][Y] == A[i][j])
                    continue;
                K = find((X - 1) * M + Y), X = find((i - 1) * M + j);
                tmp[K].push_back(X), tmp[X].push_back(K);
            }
        }

    for (int i = 1; i <= N * M; i++) {
        if (find(i) != i)
            continue;
        sort(tmp[i].begin(), tmp[i].end()), tmp[i].erase(unique(tmp[i].begin(), tmp[i].end()), tmp[i].end());
        comp.push_back(i);
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();
    for (int i : comp)
        num[i] = lower_bound(comp.begin(), comp.end(), i) - comp.begin() + 1;

    for (int i : comp)
        for (int j : tmp[i])
            adj[num[i]].push_back(num[j]);

    for (int i = 1; i <= S; i++) {
        fill(depth + 1, depth + S + 1, 0);
        q.push(i), depth[i] = 1;

        while (!q.empty()) {
            K = q.front(), q.pop();
            for (int j : adj[K])
                if (!depth[j])
                    q.push(j), depth[j] = depth[K] + 1;
        }

        K = 0;
        for (int i = 1; i <= S; i++)
            K = max(K, depth[i] - 1);
        ans = min(K, ans);
    }

    cout << ans << '\n';

    return 0;
}