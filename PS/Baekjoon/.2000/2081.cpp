#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N;
vector<pr> arr[MAX];
int dis[MAX], cnt[MAX];
bool checked[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B, C, T;
    bool cycle = false;

    cin >> N >> M;
    while (M--) {
        cin >> A >> T >> B >> C;
        if (T == 0)
            arr[B].push_back({A, C});
        else
            arr[A].push_back({B, -C});
    }

    for (int i = 1; i <= N; i++) {
        arr[i].push_back({0, -1});
        arr[0].push_back({i, 1000000});
    }

    fill(dis, dis + N + 10, INF);
    dis[0] = 0;

    queue<int> q;
    q.push(0);
    checked[0] = true;

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
        cout << -1 << '\n';
    else {
        for (int i = 1; i <= N; i++)
            cout << dis[i] << ' ';
    }

    return 0;
}