#include <bits/stdc++.h>
#define int long long

#define MAX 500
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

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

bool arr[MAX][MAX];
int num[2][MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, res = 0, X = 0;
    string S;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> S;
        for (int j = 1; j <= M; j++)
            arr[i][j] = S[j - 1] == '*';
    }

    BipartiteMatching flow(N * M * 2 + 1);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            if (!arr[i][j])
                continue;

            if (!num[0][i][j]) {
                X++;
                for (int k = i; arr[k][j]; k++)
                    num[0][k][j] = X;
            }

            if (!num[1][i][j]) {
                X++;
                for (int k = j; arr[i][k]; k++)
                    num[1][i][k] = X;
            }

            flow.add_path(num[0][i][j], num[1][i][j]);
        }

    cout << flow.run();

    return 0;
}