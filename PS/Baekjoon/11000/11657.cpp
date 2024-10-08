#include <bits/stdc++.h>
#define int long long

#define MAX 510
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> arr[MAX];
int dis[MAX], cnt[MAX];
bool checked[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B, C;
    bool cycle = false;

    cin >> N >> M;

    while (M--) {
        cin >> A >> B >> C;
        arr[A].push_back({B, C});
    }

    fill(dis, dis + N + 1, INF);
    dis[1] = 0;

    queue<int> q;
    q.push(1);
    checked[1] = true;

    while (!q.empty()) {
        A = q.front(), q.pop();
        checked[A] = false;

        if (++cnt[A] == N || dis[A] < -INF) {
            cycle = true;
            break;
        }

        for (pr i : arr[A]) {
            if (dis[A] + i.second < dis[i.first]) {
                dis[i.first] = dis[A] + i.second;
                if (!checked[i.first]) {
                    checked[i.first] = true;
                    q.push(i.first);
                }
            }
        }
    }

    if (cycle)
        cout << -1;
    else {
        for (int i = 2; i <= N; i++)
            cout << (dis[i] == INF ? -1 : dis[i]) << '\n';
    }

    return 0;
}