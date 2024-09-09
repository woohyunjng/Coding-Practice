#include <bits/stdc++.h>
#define int long long

#define MAX 210
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dis[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B, C;
    cin >> N >> M;

    fill(dis[0][0], dis[N + 1][0], INF);
    for (int i = 1; i <= N; i++)
        dis[i][i] = 0;

    while (M--) {
        cin >> A >> B >> C;
        dis[A][B] = dis[B][A] = C;
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++)
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
    
    

    return 0;
}