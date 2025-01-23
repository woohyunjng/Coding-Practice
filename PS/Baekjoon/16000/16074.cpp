#include <bits/stdc++.h>

#define MAX 600
#define MAX_Q 200000

using namespace std;
typedef array<int, 2> pr;
typedef array<int, 3> tp;

pr go[2] = {{1, 0}, {0, 1}};
int H[MAX][MAX], inp[MAX_Q][2], parent[MAX * MAX], L[MAX_Q], R[MAX_Q], ans[MAX_Q];
vector<int> arr[MAX * MAX * 4];

int find(int X) { return X == parent[X] ? X : parent[X] = find(parent[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    parent[max(X, Y)] = min(X, Y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int M, N, Q, A, B, C, D;
    bool flag;
    vector<tp> edges;

    cin >> M >> N >> Q;

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            cin >> H[i][j];

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++) {
            for (pr k : go) {
                if (i + k[0] > M || j + k[1] > N)
                    continue;
                edges.push_back({max(H[i][j], H[i + k[0]][j + k[1]]), (i - 1) * N + j, (i + k[0] - 1) * N + j + k[1]});
            }
        }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= Q; i++) {
        cin >> A >> B >> C >> D, inp[i][0] = (A - 1) * N + B, inp[i][1] = (C - 1) * N + D;
        L[i] = 0, R[i] = edges.size() - 1;

        if (inp[i][0] == inp[i][1])
            ans[i] = H[A][B], R[i] = -1;
    }

    while (true) {
        for (int i = 1; i <= N * M; i++)
            parent[i] = i;

        flag = false;
        for (int i = 1; i <= Q; i++) {
            if (L[i] <= R[i])
                flag = true, arr[L[i] + R[i] >> 1].push_back(i);
        }
        if (!flag)
            break;

        for (int i = 0; i < edges.size(); i++) {
            uni(edges[i][1], edges[i][2]);
            for (int j : arr[i]) {
                if (find(inp[j][0]) == find(inp[j][1]))
                    R[j] = i - 1, ans[j] = edges[i][0];
                else
                    L[j] = i + 1;
            }
            arr[i].clear();
        }
    }

    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';
}