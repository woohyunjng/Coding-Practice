#include <bits/stdc++.h>
#define int long long

#define MAX 5100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N;
vector<pr> arr[MAX];
int dis[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B, C, T;
    bool cycle = false, change;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        arr[i].push_back({i - 1, 0});
        arr[i - 1].push_back({i, 1});
    }

    while (M--) {
        cin >> A >> B >> C >> T;
        if (T == 0)
            arr[A].push_back({B + 1, B - A + 1 - C});
        else
            arr[B + 1].push_back({A, -(B - A + 2 - C)});
    }

    fill(dis, dis + N + 1, INF);
    dis[0] = 0;

    for (int i = 0; i < N + 1; i++) {
        change = false;
        for (int j = 0; j <= N; j++) {
            if (dis[j] == INF)
                continue;
            for (pr k : arr[j]) {
                if (dis[j] + k.second < dis[k.first]) {
                    dis[k.first] = dis[j] + k.second;
                    change = true;
                }
            }
        }

        if (i == N && change)
            cycle = true;
    }

    if (cycle)
        cout << -1 << '\n';
    else {
        for (int i = 1; i <= N; i++)
            cout << dis[i] - dis[i - 1] << ' ';
    }

    return 0;
}