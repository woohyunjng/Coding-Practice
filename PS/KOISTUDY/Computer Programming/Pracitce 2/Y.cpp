#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 1001;
const int MAX_N = 1000001;

int parent[MAX_N], sz[MAX_N], A[MAX][MAX];
pr go[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int find(int X) { return parent[X] == X ? X : parent[X] = find(parent[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X > Y)
        swap(X, Y);
    else if (X == Y)
        return;
    parent[Y] = X, sz[X] += sz[Y];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, W, ans = 0, X, Y;
    string S;

    cin >> W >> H;
    for (int i = 0; i < H; i++) {
        cin >> S;
        for (int j = 0; j < W; j++) {
            parent[i * W + j] = i * W + j, sz[i * W + j] = 1;
            A[i][j] = S[j] == '*';
        }
    }

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++) {
            if (!A[i][j])
                continue;
            for (pr k : go) {
                X = i + k[0], Y = j + k[1];
                if (X < 0 || X >= H || Y < 0 || Y >= W || !A[X][Y])
                    continue;
                uni(i * W + j, X * W + Y);
            }
        }

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++) {
            if (!A[i][j])
                continue;
            ans = max(ans, sz[find(i * W + j)]);
        }

    cout << ans << '\n';

    return 0;
}