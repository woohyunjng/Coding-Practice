#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

class UnionFind {
  private:
    vector<int> uf_parent;

  public:
    UnionFind(int N) : uf_parent(N + 1) { clear(N); }

    int find(int K) {
        if (uf_parent[K] != K)
            uf_parent[K] = find(uf_parent[K]);
        return uf_parent[K];
    }

    bool uni(int A, int B) {
        A = find(A), B = find(B);
        if (A == B)
            return false;

        if (A > B)
            swap(A, B);
        uf_parent[B] = A;
        return true;
    }

    void clear(int N) {
        for (int i = 1; i <= N; i++)
            uf_parent[i] = i;
    }
};

vector<pr> queries[11][11], arr;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, A, B, C, res;
    cin >> T;

    while (T--) {
        cin >> N >> M;
        res = N;

        UnionFind uf(N);

        for (int i = 1; i <= 10; i++)
            for (int j = 0; j < 10; j++)
                queries[i][j].clear();

        while (M--) {
            cin >> A >> B >> C;
            queries[B][A % B].push_back({A, A + B * C});
        }

        for (int i = 1; i <= 10; i++) {
            for (int j = 0; j < 10; j++) {
                arr.clear();
                sort(queries[i][j].begin(), queries[i][j].end());

                for (pr k : queries[i][j]) {
                    if (!arr.empty() && arr.back().second >= k.first) {
                        for (int l = arr.back().second; l <= k.second; l += i)
                            res -= (int)uf.uni(l, arr.back().first);
                        arr.back().second = max(arr.back().second, k.second);
                    } else {
                        for (int l = k.first; l <= k.second; l += i)
                            res -= (int)uf.uni(l, k.first);
                        arr.push_back(k);
                    }
                }
            }
        }

        cout << res << '\n';
    }

    return 0;
}