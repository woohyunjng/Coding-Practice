#include <bits/stdc++.h>
#define int long long
#define MAX 5010
#define MAX_SIZE 110
#define INF 0x7f7f7f7f7f7f7f7f

using namespace std;

class BipartiteMatching {
  private:
    int level[MAX], work[MAX];
    bool used[MAX];

    bool dinic_dfs(int K) {
        for (int i : arr[K]) {
            if (B[i] == -1 || level[B[i]] == level[K] + 1 && dinic_dfs(B[i])) {
                used[K] = true;
                A[K] = i;
                B[i] = K;
                return true;
            }
        }
        return false;
    }

  public:
    vector<int> arr[MAX], A, B;
    int N, M;

    BipartiteMatching(int A_size, int B_size) : N(A_size), M(B_size) {
        A.resize(N + 1, -1);
        B.resize(M + 1, -1);
    }

    void add_path(int X, int Y) { arr[X].push_back(Y); }

    int run() {
        queue<int> q;
        int K, res = 0, flow;

        while (true) {
            for (int i = 1; i <= N; i++) {
                if (!used[i]) {
                    level[i] = 0;
                    q.push(i);
                } else
                    level[i] = INF;
            }

            while (!q.empty()) {
                K = q.front();
                q.pop();
                for (int i : arr[K]) {
                    if (B[i] != -1 && level[B[i]] == INF) {
                        level[B[i]] = level[K] + 1;
                        q.push(B[i]);
                    }
                }
            }

            flow = 0;
            for (int i = 1; i <= N; i++) {
                if (!used[i] && dinic_dfs(i))
                    flow++;
            }
            if (!flow)
                break;

            res += flow;
        }

        return res;
    }
};

bool arr[MAX_SIZE][MAX_SIZE];
int parent_X[MAX_SIZE][MAX_SIZE], parent_Y[MAX_SIZE][MAX_SIZE];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y;
    string S;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> S;
        for (int j = 0; j < N; j++) {
            if (S[j] == '.')
                arr[i][j + 1] = true;
            else
                arr[i][j + 1] = false;
        }
    }

    X = 0, Y = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!arr[i][j])
                continue;
            if (arr[i][j - 1])
                parent_X[i][j] = parent_X[i][j - 1];
            else
                parent_X[i][j] = ++X;
        }

        for (int j = 1; j <= N; j++) {
            if (!arr[j][i])
                continue;
            if (arr[j - 1][i])
                parent_Y[j][i] = parent_Y[j - 1][i];
            else
                parent_Y[j][i] = ++Y;
        }
    }

    BipartiteMatching bm(X, Y);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!arr[i][j])
                continue;
            bm.add_path(parent_X[i][j], parent_Y[i][j]);
        }
    }

    cout << bm.run();

    return 0;
}