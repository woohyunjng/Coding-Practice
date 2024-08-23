#include <bits/stdc++.h>
#define int long long

#define MAX 100100
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
        if (A < B)
            swap(A, B);
        uf_parent[B] = A;
    }

    void clear(int N) {
        for (int i = 1; i <= N; i++)
            uf_parent[i] = i;
    }
};

int arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, A, B, X, K;
    cin >> N >> Q;

    UnionFind uf(N + 1);

    while (Q--) {
        cin >> A >> B >> X;
        K = uf.find(A);
        while (K <= B) {
            arr[K] = X;
            uf.uni(K, K + 1);
            K = uf.find(K);
        }
    }

    for (int i = 1; i <= N; i++)
        cout << arr[i] << ' ';

    return 0;
}