#include <bits/stdc++.h>

#define MAX 200000

using namespace std;

typedef array<int, 3> tp;

int ans[MAX][2], inp[MAX][2], L[MAX], R[MAX], parent[MAX], sz[MAX];
vector<int> arr[MAX];

int find(int X) { return X == parent[X] ? X : parent[X] = find(parent[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    parent[max(X, Y)] = min(X, Y);
    sz[min(X, Y)] += sz[max(X, Y)];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N, M, Q, X, Y, Z;
    bool flag;
    vector<tp> edges;

    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> X >> Y >> Z;
        edges.push_back({Z, X, Y});
    }
    sort(edges.begin(), edges.end());

    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> inp[i][0] >> inp[i][1];
        L[i] = 0, R[i] = M - 1;
    }

    while (true) {
        for (int i = 1; i <= N; i++)
            parent[i] = i, sz[i] = 1;
        for (int i = 0; i < M; i++)
            arr[i].clear();
        flag = false;

        for (int i = 1; i <= Q; i++)
            if (L[i] <= R[i])
                flag = true, arr[L[i] + R[i] >> 1].push_back(i);
        if (!flag)
            break;

        for (int i = 0; i < M; i++) {
            uni(edges[i][1], edges[i][2]);
            for (int j : arr[i]) {
                if (find(inp[j][0]) == find(inp[j][1]))
                    ans[j][0] = edges[i][0], ans[j][1] = sz[find(inp[j][0])], R[j] = i - 1;
                else
                    L[j] = i + 1;
            }
        }
    }

    for (int i = 1; i <= Q; i++) {
        if (ans[i][0] == 0)
            cout << -1 << '\n';
        else
            cout << ans[i][0] << ' ' << ans[i][1] << '\n';
    }
}