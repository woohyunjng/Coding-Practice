#include <bits/stdc++.h>
#define int long long

#define MAX 510

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX][MAX];
bool chk[MAX][MAX];
pr go[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, W, X, P, Q, val = 0, Y, Z;
    tp K;

    cin >> H >> W >> X >> P >> Q;

    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
            cin >> A[i][j];

    priority_queue<tp, vector<tp>, greater<tp>> pq;
    pq.push({A[P][Q], P, Q}), chk[P][Q] = true;

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        if (!(K[1] == P && K[2] == Q) && K[0] >= (double)val / X)
            break;
        val += K[0];

        for (pr i : go) {
            Y = K[1] + i.first, Z = K[2] + i.second;
            if (Y < 1 || Y > H || Z < 1 || Z > W || chk[Y][Z])
                continue;
            pq.push({A[Y][Z], Y, Z}), chk[Y][Z] = true;
        }
    }

    cout << val << '\n';

    return 0;
}