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

    int N, K, A, B, C, T;
    bool cycle = false;

    cin >> N >> K;
    while (K--) {
        cin >> T >> A >> B >> C;
        if (T == 1)
            arr[A].push_back({B, -C});
        else if (T == 2)
            arr[B].push_back({A, C});
        else {
            arr[A].push_back({B, -C});
            arr[B].push_back({A, C});
        }
    }

    for (int i = 1; i <= N; i++) {
        arr[0].push_back({i, 100});
        arr[i].push_back({0, 0});
    }

    fill(dis, dis + N + 1, INF);
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
        cout << -1;
    else {
        A = INF, B = -INF;
        for (int i = 1; i <= N; i++) {
            if (dis[i] == INF)
                continue;
            A = min(A, dis[i]);
            B = max(B, dis[i]);
        }

        cout << B - A;
    }

    return 0;
}