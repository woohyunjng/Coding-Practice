#include <bits/stdc++.h>
#define int long long

#define MAX 2100
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

int arr[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, C, D, V, X, Y, K = 0;
    string A, B;
    cin >> T;

    vector<pr> cat, dog;

    while (T--) {
        cin >> C >> D >> V;

        BipartiteMatching match(2 * V);
        K = 0;

        for (int i = 1; i <= V; i++) {
            cin >> A >> B;
            X = stoi(A.substr(1)), Y = stoi(B.substr(1));
            if (A[0] == 'C')
                cat.push_back({X, Y});
            else
                dog.push_back({X, Y});
        }

        for (int i = 1; i <= cat.size(); i++) {
            for (int j = 1; j <= dog.size(); j++) {
                if (cat[i - 1].first == dog[j - 1].second || cat[i - 1].second == dog[j - 1].first) {
                    match.add_path(i, j + V);
                }
            }
        }

        cout << V - match.run() << '\n';
        memset(arr, 0, sizeof(arr));
        cat.clear(), dog.clear();
    }

    return 0;
}