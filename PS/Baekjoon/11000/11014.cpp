#include <bits/stdc++.h>
#define int long long
#define MAX 10000
#define MAX_VAL 100
#define INF 0x7f7f7f7f7f7f7f7f

using namespace std;
typedef pair<int, int> pr;

class BipartiteMatching {
  private:
    int level[MAX];

    bool hop_dfs(int K) {
        for (int i : arr[K]) {
            if (level[B[i]] == level[K] + 1 && (!B[i] || hop_dfs(B[i]))) {
                A[K] = i, B[i] = K;
                return true;
            }
        }

        level[K] = INF;
        return false;
    }

  public:
    vector<int> arr[MAX], st;
    int A[MAX], B[MAX];

    BipartiteMatching(int N) {
        fill(A, A + N + 1, 0);
        fill(B, B + N + 1, 0);

        st.clear();
        for (int i = 0; i <= N; i++)
            arr[i].clear();
    }

    void add_path(int X, int Y) {
        st.push_back(X);
        arr[X].push_back(Y);
    }

    int run() {
        queue<int> q;
        int K, res = 0, flow;

        while (true) {
            level[0] = INF;
            for (int i : st) {
                if (!A[i]) {
                    level[i] = 0;
                    q.push(i);
                } else
                    level[i] = INF;
            }

            while (!q.empty()) {
                K = q.front(), q.pop();
                for (int i : arr[K]) {
                    if (level[B[i]] == INF) {
                        level[B[i]] = level[K] + 1;
                        q.push(B[i]);
                    }
                }
            }

            if (level[0] == INF)
                break;

            for (int i : st) {
                if (!A[i] && hop_dfs(i))
                    res++;
            }
        }

        return res;
    }
};

int subst(int A, int B, int N) { return (A - 1) * N + B; }

bool arr[MAX_VAL][MAX_VAL];
pr go[6] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}, {0, -1}, {0, 1}};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, C, res = 0, nX, nY;
    string S;
    bool val;

    cin >> C;
    while (C--) {
        cin >> N >> M;
        res = 0;

        for (int i = 1; i <= N; i++) {
            cin >> S;
            for (int j = 1; j <= M; j++) {
                if (S[j - 1] == '.') {
                    res++;
                    arr[i][j] = true;
                } else
                    arr[i][j] = false;
            }
        }

        BipartiteMatching bm(N * M);

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (!arr[i][j] || !(j & 1))
                    continue;
                for (int k = 0; k < 6; k++) {
                    nX = i + go[k].first, nY = j + go[k].second;
                    if (nX < 1 || nX > N || nY < 1 || nY > M || !arr[nX][nY])
                        continue;
                    bm.add_path(subst(i, j, M), subst(nX, nY, M));
                }
            }
        }

        cout << res - bm.run() << '\n';
    }

    return 0;
}