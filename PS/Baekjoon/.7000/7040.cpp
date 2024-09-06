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

    int N, ML, MD, A, B, D;
    bool cycle = false;

    cin >> N >> ML >> MD;

    while (ML--) {
        cin >> A >> B >> D;
        arr[A].push_back({B, D});
    }

    while (MD--) {
        cin >> A >> B >> D;
        arr[B].push_back({A, -D});
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
    else if (dis[N] == INF)
        cout << -2;
    else
        cout << dis[N];

    return 0;
}