#include <bits/stdc++.h>
#define int long long
#define MAX 1010

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int subst(int A, int B) { return A * MAX + B; }

class UnionFind {
  private:
    int uf_parent[MAX * MAX];

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

int arr[MAX][MAX];
bool checked[MAX][MAX];
pr go[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int H, W, Y, res, K, x, y, nx, ny;
    cin >> H >> W >> Y;

    UnionFind uf(MAX * MAX - 1);
    vector<tp> vec;

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> arr[i][j];
            vec.push_back({arr[i][j], i, j});
        }
    }
    sort(vec.begin(), vec.end());

    for (int i = 1; i <= H; i++) {
        uf.uni(0, subst(i, W));
        uf.uni(0, subst(i, 1));
    }

    for (int i = 1; i <= W; i++) {
        uf.uni(0, subst(1, i));
        uf.uni(0, subst(H, i));
    }

    queue<pr> q;

    K = 0, res = H * W;
    for (int i = 1; i <= Y; i++) {
        for (; K < H * W && vec[K][0] <= i; K++) {
            x = vec[K][1], y = vec[K][2];
            if (checked[x][y] || uf.find(subst(x, y)))
                continue;
            checked[x][y] = true;
            res--;
            q.push({x, y});

            while (!q.empty()) {
                x = q.front().first, y = q.front().second;
                q.pop();

                for (int j = 0; j < 4; j++) {
                    nx = x + go[j].first, ny = y + go[j].second;
                    if (nx < 1 || nx > H || ny < 1 || ny > W || checked[nx][ny])
                        continue;
                    uf.uni(subst(x, y), subst(nx, ny));
                    if (arr[nx][ny] <= i) {
                        checked[nx][ny] = true;
                        res--;
                        q.push({nx, ny});
                    }
                }
            }
        }
        cout << res << '\n';
    }

    return 0;
}