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

    int N, M, A, B, C, res = 0;
    cin >> N >> M;

    UnionFind uf(N);

    vector<tp> arr;
    while (M--) {
        cin >> A >> B >> C;
        arr.push_back({C, A, B});
    }
    sort(arr.begin(), arr.end());

    for (tp i : arr) {
        C = i[0], A = i[1], B = i[2];
        if (uf.find(A) == uf.find(B))
            continue;
        uf.uni(A, B);
        res += C;
    }

    cout << res;

    return 0;
}