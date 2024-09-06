#include <bits/stdc++.h>
#define int long long

#define MAX 50
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

    int K, N, MD, A, B, D;
    string ans;
    bool cycle = false;

    cin >> K >> N;

    while (N--) {
        cin >> A >> B >> D;
        arr[B].push_back({A - 1, -D});
        arr[A - 1].push_back({B, D});
    }

    for (int i = 1; i <= K; i++) {
        arr[i].push_back({i - 1, 0});
        arr[i - 1].push_back({i, 1});
    }

    fill(dis, dis + K + 1, INF);
    dis[0] = 0;

    queue<int> q;
    q.push(0);
    checked[0] = true;

    while (!q.empty()) {
        A = q.front(), q.pop();
        checked[A] = false;

        if (++cnt[A] == K || dis[A] < -INF) {
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

    if (cycle) {
        cout << "NONE";
        return 0;
    }

    for (int i = 1; i <= K; i++) {
        if (dis[i] == dis[i - 1] + 1)
            ans += '#';
        else
            ans += '-';
    }

    cout << ans;

    return 0;
}