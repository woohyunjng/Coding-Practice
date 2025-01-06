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

    void uni(int A, int B) {
        A = find(A), B = find(B);
        if (A > B)
            swap(A, B);
        uf_parent[B] = A;
    }

    void clear(int N) {
        for (int i = 1; i <= N; i++)
            uf_parent[i] = i;
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, A, B, C;
    cin >> N;
    UnionFind uf(N);

    cin >> Q;
    while (Q--) {
        cin >> A >> B >> C;
        if (A == 0)
            uf.uni(B, C);
        else
            cout << (uf.find(B) == uf.find(C) ? 1 : 0) << endl;
    }

    return 0;
}