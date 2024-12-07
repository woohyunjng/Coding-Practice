#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

pr go[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int X[MAX][MAX];
bool vst[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, W, D, res = 0, A, B;
    tp K;
    string S;

    queue<tp> q;

    cin >> H >> W >> D;

    for (int i = 1; i <= H; i++) {
        cin >> S;
        for (int j = 1; j <= W; j++)
            if (S[j - 1] == '#')
                X[i][j] = 1;
            else if (S[j - 1] == 'H')
                q.push({i, j, 0}), vst[i][j] = true;
    }

    while (!q.empty()) {
        K = q.front(), q.pop();
        res++;

        for (pr i : go) {
            A = K[0] + i.first, B = K[1] + i.second;
            if (A < 1 || A > H || B < 1 || B > W || vst[A][B] || K[2] == D || X[A][B])
                continue;
            vst[A][B] = true;
            q.push({A, B, K[2] + 1});
        }
    }

    cout << res << '\n';

    return 0;
}