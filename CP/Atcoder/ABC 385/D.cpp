#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define INF 0x7f7f7f7f7f7f7f7f

using namespace std;
typedef pair<int, int> pr;

int A[MAX], B[MAX], chk[MAX];
map<int, vector<pr>> hor, ver;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, K, res = 0;
    char C;

    cin >> N >> M >> X >> Y;
    for (int i = 1; i <= N; i++)
        cin >> A[i] >> B[i], hor[A[i]].push_back({B[i], i}), ver[B[i]].push_back({A[i], i});

    while (M--) {
        cin >> C >> K;
        if (C == 'D')
            hor[X].push_back({Y - K, 0}), hor[X].push_back({Y + 1, -1}), Y -= K;
        else if (C == 'U')
            hor[X].push_back({Y, 0}), hor[X].push_back({Y + K + 1, -1}), Y += K;
        else if (C == 'R')
            ver[Y].push_back({X, 0}), ver[Y].push_back({X + K + 1, -1}), X += K;
        else if (C == 'L')
            ver[Y].push_back({X - K, 0}), ver[Y].push_back({X + 1, -1}), X -= K;
    }

    for (auto &i : hor) {
        sort(i.second.begin(), i.second.end()), K = 0;
        for (pr j : i.second) {
            if (j.second == -1)
                K--;
            else if (j.second == 0)
                K++;
            else if (chk[j.second] == 0) {
                if (K > 0)
                    chk[j.second] = 1, res++;
            }
        }
    }

    for (auto &i : ver) {
        sort(i.second.begin(), i.second.end()), K = 0;
        for (pr j : i.second) {
            if (j.second == -1)
                K--;
            else if (j.second == 0)
                K++;
            else if (chk[j.second] == 0) {
                if (K > 0)
                    chk[j.second] = 1, res++;
            }
        }
    }

    cout << X << ' ' << Y << ' ' << res << '\n';

    return 0;
}