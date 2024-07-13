#include <bits/stdc++.h>
#define int long long
#define MAX 100100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

class UnionFind {
  public:
    UnionFind(int N) { clear(N); }
    int uf_parent[MAX], weight[MAX];

    int find(int K) {
        if (uf_parent[K] != K) {
            int X = uf_parent[K];
            uf_parent[K] = find(X);
            weight[K] += weight[X];
        }
        return uf_parent[K];
    }

    void clear(int N) {
        for (int i = 1; i <= N; i++) {
            uf_parent[i] = i;
            weight[i] = 0;
        }
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, A, B, C, X, Y;
    char T;

    while (true) {
        cin >> N >> M;
        if (!N)
            break;

        UnionFind uf(N);
        while (M--) {
            cin >> T >> A >> B;
            X = uf.find(A), Y = uf.find(B);
            if (T == '?') {
                if (X != Y)
                    cout << "UNKNOWN\n";
                else
                    cout << uf.weight[B] - uf.weight[A] << '\n';
            } else {
                cin >> C;
                if (X == Y)
                    continue;
                if (X > Y) {
                    swap(X, Y);
                    swap(A, B);
                    C = -C;
                }
                uf.uf_parent[Y] = X;
                uf.weight[Y] = uf.weight[A] - uf.weight[B] + C;
            }
        }
    }

    return 0;
}