#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

bool sex[MAX];

class UnionFind {
  private:
    vector<int> uf_parent, boy, girl;

  public:
    UnionFind(int N) : uf_parent(N + 1), boy(N + 1, 0), girl(N + 1, 0) { clear(N); }

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

        boy[A] += boy[B];
        girl[A] += girl[B];
    }

    int calc(int X) {
        X = find(X);
        return boy[X] * girl[X];
    }

    void clear(int N) {
        for (int i = 1; i <= N; i++) {
            uf_parent[i] = i;
            if (sex[i])
                boy[i]++;
            else
                girl[i]++;
        }
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B, res = 0;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> A;
        sex[i] = A % 2 == 1;
    }

    UnionFind uf(N);

    while (M--) {
        cin >> A >> B;
        if (uf.find(A) == uf.find(B)) {
            cout << res << '\n';
            continue;
        }

        res -= uf.calc(A) + uf.calc(B);
        uf.uni(A, B);
        res += uf.calc(A);
        cout << res << '\n';
    }

    return 0;
}