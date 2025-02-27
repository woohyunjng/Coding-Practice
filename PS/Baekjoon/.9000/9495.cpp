#include <bits/stdc++.h>

using namespace std;
typedef array<int, 2> pr;

const int MAX = 5000;
const int MAX_S = 600;

int A[MAX_S][MAX_S], V[MAX_S][MAX_S], num[MAX];
vector<int> adj[MAX];
bool vst[MAX];

pr go[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool dfs(int node) {
    for (int i : adj[node]) {
        if (vst[i])
            continue;
        vst[i] = true;
        if (!num[i] || dfs(num[i])) {
            num[i] = node;
            return true;
        }
    }
    return false;
}

int match(int N) {
    int res = 0;
    for (int i = 1; i <= N; i++) {
        fill(vst, vst + N + 1, false);
        if (dfs(i))
            res++;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K = 0, X, Y;
    string S;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> S;
        for (int j = 1; j <= N; j++) {
            if (S[j - 1] == 'o')
                A[i][j] = 0, V[i][j] = ++K;
            else if (S[j - 1] == 'x')
                A[i][j] = 1;
            else
                A[i][j] = 2, V[i][j] = ++K;
        }
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            if (A[i][j] != 0)
                continue;
            for (pr k : go) {
                X = i + k[0], Y = j + k[1];
                if (X <= 0 || X > N || Y <= 0 || Y > N || A[X][Y] != 2)
                    continue;
                adj[V[i][j]].push_back(V[X][Y]);
            }
        }

    cout << K - match(K) << '\n';

    return 0;
}