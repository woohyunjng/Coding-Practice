#include <bits/stdc++.h>
#define int long long
#define MAX 1010

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

class UnionFind {
  private:
    int uf_parent[MAX];

  public:
    UnionFind(int N) { clear(N); }

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
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K, F, T, A, B, mn, mx;
    char C;

    UnionFind uf(0);

    while (true) {
        vector<tp> arr;

        cin >> N >> M >> K;
        if (!N)
            break;

        for (int i = 0; i < M; i++) {
            cin >> C >> F >> T;
            if (C == 'R')
                arr.push_back({1, F, T});
            else
                arr.push_back({0, F, T});
        }
        sort(arr.begin(), arr.end());
        mn = 0, mx = 0;

        uf.clear(N);

        for (tp i : arr) {
            A = uf.find(i[1]), B = uf.find(i[2]);
            if (A == B)
                continue;

            if (!i[0])
                mx++;
            uf.uni(A, B);
        }

        reverse(arr.begin(), arr.end());
        uf.clear(N);

        for (tp i : arr) {
            A = uf.find(i[1]), B = uf.find(i[2]);
            if (A == B)
                continue;

            if (!i[0])
                mn++;
            uf.uni(A, B);
        }

        cout << ((mn <= K && K <= mx) ? 1 : 0) << '\n';
    }

    return 0;
}
