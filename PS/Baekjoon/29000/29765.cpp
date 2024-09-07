#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> arr[MAX][31];
int dis[MAX], cnt[MAX], res[MAX];
bool checked[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, P, T, A, B, C;
    bool cycle = false;

    cin >> N >> P;

    while (P--) {
        cin >> T >> A >> B >> C;
        for (int i = 0; i < 31; i++) {
            if (C & (1 << i)) {
                if (T == 1) {
                    arr[A - 1][i].push_back({B, B - A + 1});
                    arr[B][i].push_back({A - 1, A - B - 1});
                } else
                    arr[B][i].push_back({A - 1, -1});
            } else {
                if (T == 1)
                    arr[A - 1][i].push_back({B, B - A});
                else {
                    arr[A - 1][i].push_back({B, 0});
                    arr[B][i].push_back({A - 1, 0});
                }
            }
        }
    }

    for (int i = 0; i < 31; i++) {
        for (int j = 1; j <= N; j++) {
            arr[j][i].push_back({j - 1, 0});
            arr[j - 1][i].push_back({j, 1});
        }
    }

    queue<int> q;

    for (int i = 0; i < 31; i++) {
        fill(dis, dis + N + 1, INF);
        fill(cnt, cnt + N + 1, 0);
        fill(checked, checked + N + 1, false);

        dis[0] = 0;
        q.push(0);
        checked[0] = true;

        while (!q.empty()) {
            A = q.front(), q.pop();
            checked[A] = false;

            if (++cnt[A] == N + 1 || dis[A] < -INF) {
                cycle = true;
                break;
            }

            for (pr j : arr[A][i]) {
                if (dis[A] + j.second < dis[j.first]) {
                    dis[j.first] = dis[A] + j.second;
                    if (!checked[j.first]) {
                        checked[j.first] = true;
                        q.push(j.first);
                    }
                }
            }
        }

        if (cycle)
            break;

        for (int j = 1; j <= N; j++) {
            if (dis[j] - dis[j - 1] == 1)
                res[j] += (1 << i);
        }
    }

    if (cycle)
        cout << -1;
    else {
        for (int i = 1; i <= N; i++)
            cout << res[i] << ' ';
    }

    return 0;
}