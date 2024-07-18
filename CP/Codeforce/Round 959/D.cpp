#include <bits/stdc++.h>
#define int long long
#define MAX 2010

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

int arr[MAX];
vector<int> rem[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N;
    pr K;
    bool found;
    cin >> T;

    stack<pr> st;

    while (T--) {
        cin >> N;
        UnionFind uf(N);

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
            for (int j = 0; j <= N; j++)
                rem[i][j].clear();
        }

        for (int i = 1; i <= N - 1; i++) {
            for (int j = 1; j <= N; j++)
                rem[i][arr[j] % i].push_back(j);
        }

        for (int i = N - 1; i >= 1; i--) {
            found = false;
            for (int j = 0; j < i; j++) {
                for (int k = 0; k < rem[i][j].size(); k++) {
                    if (uf.find(rem[i][j][k]) != uf.find(rem[i][j][(k + 1) % rem[i][j].size()])) {
                        st.push({rem[i][j][k], rem[i][j][(k + 1) % rem[i][j].size()]});
                        uf.uni(rem[i][j][k], rem[i][j][(k + 1) % rem[i][j].size()]);
                        found = true;
                        break;
                    }
                }
                if (found)
                    break;
            }
        }

        cout << "YES\n";
        while (!st.empty()) {
            K = st.top(), st.pop();
            cout << K.first << ' ' << K.second << '\n';
        }
    }

    return 0;
}